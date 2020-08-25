#pragma once

#include <string>
#include <ctime>
#include <cstdlib>
#include "Maze2d.h"

class Maze2dGenerator
{
public:
	virtual Maze2d generate(int rows, int columns) = 0;

	virtual std::string measureAlgorithmTime(int rows, int columns) {

		clock_t begin_time = clock();
		
		this->generate(rows, columns);

		clock_t end_time = clock();

		float seconds = ((float)end_time - begin_time) / CLOCKS_PER_SEC;

		return std::to_string(seconds);
	}
};

