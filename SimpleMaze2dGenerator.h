#pragma once

#include "Maze2dGenerator.h"

class SimpleMaze2dGenerator : public Maze2dGenerator
{
public:
	virtual Maze2d generate(int rows, int columns) {

		srand(time_t(NULL));

		Maze2d maze(rows, columns);

		// randomly open internal walls in the maze
		for (int row = 0; row < rows; ++row) {
			for (int col = 0; col < columns; ++col) {

				Direction dir;
				bool valid = false;

				do {
					valid = true;

					 dir = rand() % 4;

					 if ((row == 0 && dir == UP) ||
						 (row == rows - 1 && dir == DOWN) ||
						 (col == 0 && dir == LEFT) ||
						 (col == columns - 1 && dir == RIGHT))
						 valid = false;

				} while (!valid);

				maze.openWall(Position(row, col), dir);
			}
		}

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


		// create a path from start to end to ensure a solution
		Position curr_pos = start_pos;

		while (curr_pos != end_pos) {

			Direction result_dir;

			int col_diff = curr_pos.column() - end_pos.column();

			int row_diff = curr_pos.row() - end_pos.row();

			int choice = 0;
			if (col_diff && row_diff) {
				// if we have a choice to move a particular direction, randomly choose it
				choice = rand() % 2; // 1 -> use col
			}
			else {
				choice = col_diff > 0;
			}

			if (choice) { // use col
				if (col_diff > 0) // move left
					result_dir = LEFT;
				else
					result_dir = RIGHT;
			}
			else {
				if (row_diff > 0)
					result_dir = UP;
				else
					result_dir = DOWN;
			}

			maze.openWall(curr_pos, result_dir);
			curr_pos = applyDirection(curr_pos, result_dir);
		}

		return maze;
	}
};

