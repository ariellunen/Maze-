#pragma once

#include "Command.h"

class FileSizeCommand : public Command {
private:
	std::string result;
	std::string error;
public:
	virtual bool doCommand(const std::vector<std::string>& tokens, View& view, Controller& controller) {

		// file size <name>
		if (tokens.size() == 3) {

			std::string name = tokens[2];

			Maze2d maze;
			if(Cache::getMaze(name, maze)) {
				result = name + " Size: " + std::to_string(Cache::getMazeCompressedSize(maze)) + " Bytes.";
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
