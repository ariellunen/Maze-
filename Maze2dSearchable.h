#pragma once

#include "Searchable.h"
#include "Maze2dState.h"
//template <class T>
class Maze2dSearchable : public Searchable
{
private:
	const Maze2d& m_maze;

	State start_state;
	State goal_state;
public:
	Maze2dSearchable(const Maze2d& maze) : 
		m_maze(maze), 
		start_state(maze.getStartPosition()),
		goal_state(maze.getGoalPosition()) {	
		
		visited.resize(maze.rows());
		for (int i = 0; i < maze.rows(); ++i)
			visited[i].resize(maze.columns());
	}
private:
	std::vector<std::vector<bool>> visited;
public:
	virtual const State& getStartState() const {
		return start_state;
	}
	virtual const State& getGoalState() const {
		return goal_state;
	}

	virtual std::vector<State> getAllPossibleStates(State& s) {

		std::vector<State> all_states;

		visited[s.getState().row()][s.getState().column()] = true;

		std::vector<Direction> directions = m_maze.getPossibleDirections(s.getState());

		for (Direction dir : directions) {

			Position new_pos = applyDirection(s.getState(), dir);

			if (visited[new_pos.row()][new_pos.column()] == false) {
				visited[new_pos.row()][new_pos.column()] = true;
				State newState(new_pos, &s);
				all_states.push_back(newState);
			}
		}

		return all_states;
	}
};

