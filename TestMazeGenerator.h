#pragma once

#include "Model/MyMaze2dGenerator.h"
#include "Model/SimpleMaze2dGenerator.h"

class TestMazeGenerator {
public:
	TestMazeGenerator() {}

	void testMazeGenerator(Maze2dGenerator* mg) {

		const int rows = 10, columns = 10;

		std::cout << mg->measureAlgorithmTime(rows, columns) << std::endl;

		Maze2d maze = mg->generate(rows, columns);

		Position p = maze.getStartPosition();

		std::cout << p << std::endl;

		std::vector<std::string> moves = maze.getPossibleMoves(p);

		for (std::string move : moves) {
			std::cout << move << std::endl;
		}

		std::cout << maze.getGoalPosition() << std::endl;

		std::cout << maze << std::endl;
	}
};

void test() {
	TestMazeGenerator t;
	TestMazeGenerator t2;

	t.testMazeGenerator(new SimpleMaze2dGenerator());
	t2.testMazeGenerator(new MyMaze2dGenerator());
}
