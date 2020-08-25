#pragma once

#include <experimental/filesystem>

#include "Command.h"

class MazeSizeCommand : public Command {

private:
	std::string result;
	std::string error;
public:
	virtual bool doCommand(const std::vector<std::string>& tokens, View& view, Controller& controller) {

		// Maze size <name>
		if (tokens.size() == 3) {
			std::string name = tokens[2];

			// Give size of maze in memory
			Maze2d maze;
			if(Cache::getMaze(name, maze)) {
				result = name + " Size: " + std::to_string(maze.getMazeMemSize()) + " Bytes.";
				return true;
			} else {
				error = "'" + name + "' no such maze found.";
				return false;
			}
		}
		return false;
	}

	std::string getError() const {
		return error;
	}

	std::string getResult() const {
		return result;
	}
};
