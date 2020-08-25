#pragma once

#include <sstream>

#include "Command.h"

#include "../Model/Cache.h"
class DisplayCommand : public Command {

private:
	std::string error = "Invalid Command";
	std::string result;
public:
	virtual bool doCommand(const std::vector<std::string>& tokens, View& view, Controller& controller) {


		if (tokens.size() == 2) {

			Maze2d maze(10, 10);
			if (Cache::getMaze(tokens[1], maze)) {
				std::stringstream ss;
				ss << maze;
				result = ss.str();
				return true;
			}
			else {
				error = "'" + tokens[1] + "' no such maze found.";
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
