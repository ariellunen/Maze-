#pragma once

#include <experimental/filesystem>
#include <iostream>
#include <string.h>

#include "Command.h"

using namespace std;

class DirectoryCommand : public Command {

private:
	std::string result;
public:
	virtual bool doCommand(const std::vector<std::string>& tokens, View& view, Controller& controller) {

		// dir <path>
		if (tokens.size() == 2) {
			std::string path = tokens[1];

			// --- for C++17 onwards
			//		for (auto & p : std::filesystem::directory_iterator(path))
			for (auto & p : std::experimental::filesystem::directory_iterator(path))
				result += p.path().filename().string() + '\n';

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
