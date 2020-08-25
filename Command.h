#pragma once

#include <vector>
#include <string>

#include "../View/View.h"
class Command {

private:
public:
	virtual bool doCommand(const std::vector<std::string>& commandTokens, View& view, Controller& controller) = 0;
	
	virtual std::string getError() const = 0;

	virtual std::string getResult() const = 0;
};
static std::map<int, vector <std::pair<int, int>>> sol;
