#pragma once

#include <stack>
#include "Maze2dGenerator.h"

class MyMaze2dGenerator : public Maze2dGenerator
{
public:
	virtual Maze2d generate(int rows, int columns) {
		/*
		RECURSIVE BACKTRACKER WITH STACK 

		Choose the initial cell, mark it as visited and push it to the stack
		While the stack is not empty
			Pop a cell from the stack and make it a current cell
			If the current cell has any neighbours which have not been visited
				Push the current cell to the stack
				Choose one of the unvisited neighbours
				Remove the wall between the current cell and the chosen cell
				Mark the chosen cell as visited and push it to the stack
		*/
		srand(time_t(NULL));
		Maze2d maze(rows, columns);

		// create two random, different points on the edge as our start and end points
		std::pair<Position, Direction> res = maze.getRandomEdge();
		Position start_pos = res.first;
		maze.openWall(start_pos, res.second);
		maze.setStart(start_pos);

		Position end_pos;
		do {
			res = maze.getRandomEdge();
			end_pos = res.first;
		} while (end_pos == start_pos);

		maze.openWall(end_pos, res.second);
		maze.setEnd(end_pos);

		std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));

		std::stack<Position> stk;

		stk.push(start_pos);
		visited[start_pos.row()][start_pos.column()] = true;

		while (!stk.empty()) {
			
			Position curr = stk.top();
			stk.pop();

			std::vector<std::pair<Position, Direction>> options;

			for (int i = 0; i < 4; ++i) {

				Position result_pos = applyDirection(curr, i);

				if (maze.isValidPosition(result_pos) && visited[result_pos.row()][result_pos.column()] == false) {
					options.push_back(std::make_pair(result_pos, i));
				}
			}

			if (options.size()) {

				stk.push(curr);

				int selected = rand() % options.size();

				maze.openWall(curr, options[selected].second);

				Position selected_neighbour = options[selected].first;

				stk.push(selected_neighbour);
				visited[selected_neighbour.row()][selected_neighbour.column()] = true;
			}
		}

		return maze;
	}
};

