#pragma once

#include "Model/MyMaze2dGenerator.h"
#include "Model/BFS.h"
#include "Model/AStar.h"
#include "Model/Maze2dSearchable.h"
#include "Model/ManhattanDistance.h"

class Demo {
public:
	void runQ() {

		auto mg = new MyMaze2dGenerator();
		Maze2d maze = mg->generate(5, 5);

		cout << maze << endl;

		Maze2dSearchable searchable_a(maze);
		BFS bfs;

		Solution bfsSolution = bfs.search(searchable_a);
		cout << "BFS Nodes explored: " << bfs.getNumberOfNodesEvaluated() << endl;

		Maze2dSearchable searchable(maze);

		ManhattanDistance md_heuristic;
		AStar astar(10, md_heuristic);

		Solution astarSolution = astar.search(searchable);
		cout << "A* Nodes explored: " << astar.getNumberOfNodesEvaluated() << endl;

		cout << "A* solution: " << astarSolution << endl;
	}
};
