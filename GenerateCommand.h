#pragma once

#include <sstream>

#include "Command.h"

#include "../Model/MyMaze2dGenerator.h"
#include "../Model/SimpleMaze2dGenerator.h"
#include "../Model/Cache.h"
class GenerateCommand : public Command {

private:
	std::string result;
	std::string error;
public:
	virtual bool doCommand(const std::vector<std::string>& tokens, View& view, Controller& controller) {

		// generate maze name <backtracker/random> row column 
		if (tokens.size() == 6) {

			std::string name = tokens[2];

			std::string type = tokens[3];

			Maze2dGenerator* mg;
			if (type == "backtracker") {
				mg = new MyMaze2dGenerator();
			}
			else if (type == "random") {
				mg = new SimpleMaze2dGenerator();
			}
			else {
				error = "Invalid Generator type";
				return false;
			}

			int rows = stoi(tokens[4]);
			int cols = stoi(tokens[5]);

			Maze2d maze = mg->generate(rows, cols);

			Cache::saveMaze(name, maze, false);

			std::stringstream ss;
			ss << maze;
			result = ss.str();

			return true;
		}

		return false;
	}

	std::string getError() const {
		return "Invalid command";
	}

	std::string getResult() const {
		return result;
	}
};
