#pragma once

#include "Command.h"

class SaveCommand : public Command {

private:
	std::string result;
	std::string error;
public:
	virtual bool doCommand(const std::vector<std::string>& tokens, View& view, Controller& controller) {

		// save maze <name> <file name>
		if (tokens.size() == 4) {

			std::string mazeName = tokens[2];
			std::string fileName = tokens[3];

			Maze2d maze;
			if(Cache::getMaze(mazeName, maze)) {
				Cache::saveMaze(fileName,mazeName, maze, true);
				result = "'" + mazeName + "' saved.";
				return true;
			} else {
				error = "'" + mazeName + "' no such maze found.";
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
