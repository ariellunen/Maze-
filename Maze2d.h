#pragma once

#include <vector>
#include <array>
#include <iostream>
#include <cassert>
#include <cmath>
#include "Position.h"
#include "Solution.h"

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

typedef int Direction;

std::string move_to_str(Direction move) {
	switch (move) {
	case UP:
		return "UP";
	case RIGHT:
		return "RIGHT";
	case DOWN:
		return "DOWN";
	case LEFT:
		return "LEFT";
	}
	assert(false);
	return "";
}

std::pair<int, int> getDirVector(Direction dir) {

	static std::vector<std::pair<int, int>> moves{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	return moves[dir];
}

Position applyDirection(const Position& pos, Direction dir) {

	auto diff = getDirVector(dir);
	return Position(pos.row() + diff.first, pos.column() + diff.second);
}

class Maze2d
{

private:
	std::vector<std::vector<int>> maze;

	Position start_pos;
	Position end_pos;

	int m_rows;
	int m_cols;
public:
	Maze2d(int rows, int columns) {
		
		m_rows = rows;
		m_cols = columns;
		maze.resize(rows * 2 + 1);

		for (unsigned int i = 0; i < maze.size(); ++i) {

			maze[i].resize(columns * 2 + 1);

			for (unsigned int c = 0; c < maze[0].size(); ++c) {
				if (i % 2 == 1 && c % 2 == 1)
					maze[i][c] = 0;
				else
					maze[i][c] = 1;
			}
		}
	}

	Maze2d(int rows, int columns, std::vector<std::vector<int>>& maze_data, Position start_pos, Position end_pos) {
		m_rows = rows;
		m_cols = columns;
		maze = maze_data;
		this->start_pos = start_pos;
		this->end_pos = end_pos;
	}

	const std::vector<std::vector<int>>& getRaw() const {
		return maze;
	}

	Position convertToCell(const Position& pos) const {
		return Position(pos.row() * 2 + 1, pos.column() * 2 + 1);
	}

	void openWall(const Position& pos, Direction wall) {

		assert(isValidPosition(pos));

		Position res = applyDirection(convertToCell(pos), wall);
		
		maze[res.row()][res.column()] = 0;
	}

	bool isOpen(const Position& pos, Direction wall) const {

		assert(isValidPosition(pos));

		Position res = applyDirection(convertToCell(pos), wall);

		return maze[res.row()][res.column()] == 0;
	}

	bool isValidPosition(const Position& pos) const {
		return 0 <= pos.row() && pos.row() < m_rows && 0 <= pos.column() && pos.column() < m_cols;
	}

	std::vector<Direction> getPossibleDirections(const Position &pos) const {
		
		std::vector<Direction> result;
		std::vector<std::pair<int, int>> moves{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

		int curr_row = pos.row();
		int curr_col = pos.column();

		for (unsigned int i = 0; i < moves.size(); ++i) {

			int n_row = moves[i].first + curr_row;
			int n_col = moves[i].second + curr_col;

			Position result_pos(n_row, n_col);

			Position wall_pos = applyDirection(pos, i);
			// if within limits and wall is open
			if (isValidPosition(result_pos) && isOpen(pos, i)) {

				result.push_back(i);
			}
		}

		return result;
	}

	std::vector<std::string> getPossibleMoves(const Position &pos) const {

		std::vector<Direction> positions = this->getPossibleDirections(pos);

		std::vector<std::string> moves(positions.size());

		for (unsigned int i = 0; i < positions.size(); ++i)
			moves[i] = move_to_str(positions[i]);
		
		return moves;
	}

	Position getStartPosition() const {
		return start_pos;
	}

	Position getGoalPosition() const {
		return end_pos;
	}

	void setStart(const Position& pos) {
		start_pos = pos;
	}

	void setEnd(const Position& pos) {
		end_pos = pos;	
	}

	int rows() const {
		return m_rows;
	}

	int columns() const {
		return m_cols;
	}

	Maze2d() {
		m_rows = 0;
		m_cols = 0;
	}

	std::pair<Position, Direction> getRandomEdge() const {

		Direction dir = rand() % 4;
		Position pos;
		if (dir == UP)
			pos = Position(0, rand() % m_cols);
		else if (dir == DOWN)
			pos = Position(m_rows - 1, rand() % m_cols);
		else if (dir == LEFT)
			pos = Position(rand() % m_rows, 0);
		else if (dir == RIGHT)
			pos = Position(rand() % m_rows, m_cols - 1);

		return std::make_pair(pos, dir);
	}

	void displayWithSolution(std::ostream& out, Solution sol) const noexcept{

		out << "Start: " << start_pos << " Exit: " << end_pos << std::endl;

		for (unsigned int row = 0; row < maze.size(); ++row) {
			for (unsigned int col = 0; col < maze[0].size(); ++col) {


				if (maze[row][col] == 0) {
					if(row % 2 == 1 && col % 2 == 1) {
						double flrow = floor((double)row / 2);
						double flcol = floor((double)col / 2);
						Position pos((int)flrow, (int)flcol);
						if (sol.isInSolution(pos))
							out << '+';
						else
							out << ' ';
					} else
						out << ' ';
				}	else // 1 or any other interger == wall
					out << '#';
			}
			out << std::endl;
		}
	}

	void display(std::ostream& out) const {

		out << "Start: " << start_pos << " Exit: " << end_pos << std::endl;

		for (unsigned int row = 0; row < maze.size(); ++row) {
			for (unsigned int col = 0; col < maze[0].size(); ++col) {

				if (maze[row][col] == 0)
					out << ' ';
				else
					out << '#';
			}
			out << std::endl;
		}
	}
	
	long getMazeMemSize() {
		return sizeof(std::vector<std::vector<int>>) + (maze.size() * sizeof(std::vector<int>)) + (maze.size() * maze[0].size() * sizeof(int));
	} 
};

std::ostream& operator<<(std::ostream& out, const Maze2d& maze) {
	maze.display(out);
	return out;
}
