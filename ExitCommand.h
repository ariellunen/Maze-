#pragma once

#include "Command.h"

class ExitCommand : public Command {

public:
	virtual bool doCommand(const std::vector<std::string>& tokens, View& view, Controller& controller) {
		
		view.terminate();			
		return true;
	}

	std::string getError() const {
		return "";
	}

	std::string getResult() const {
		return "";
	}
};
