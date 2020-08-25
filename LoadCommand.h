#pragma once

#include <experimental/filesystem>

#include "Command.h"

class LoadCommand : public Command {

private:
	std::string result;
	std::string error;
public:
	virtual bool doCommand(const std::vector<std::string>& tokens, View& view, Controller& controller) {

		// load maze <file name> <name>
		if (tokens.size() == 4) {

			std::string fileName = tokens[2];
			std::string mazeName = tokens[3];

			Maze2d maze;
			if(Cache::getMaze(fileName, maze)) {
				
				// load the maze from file into maze map
			
				result = "'" + fileName + "' maze loaded in '" + mazeName + "'.";
				return true;
			} else {
				error = "'" + fileName + "' no such file found.";
				return false;
			}

			return true;
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
