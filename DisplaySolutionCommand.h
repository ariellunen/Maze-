#pragma once

#include "Command.h"

class DisplaySolutionCommand : public Command {

private:
	std::string result;
	std::string error;
public:
	virtual bool doCommand(const std::vector<std::string>& tokens, View& view, Controller& controller) {

		// display solution <name>
		if (tokens.size() == 3) {
			std::string mazeName = tokens[2];
			map<std::string, vector <pair<int, int>>>::iterator it;
			bool found = false;
			for (it = Cache::Mysol.begin(); it != Cache::Mysol.end(); it++)
			{
				if (it->first == mazeName)
				{
					for (unsigned int i = 0; i < Cache::Mysol[mazeName].size(); i++)
					{
//						std::cout << Cache::Mysol[mazeName][i].second << endl;
						std::cout << "(" << Cache::Mysol[mazeName][i].first << "," << Cache::Mysol[mazeName][i].second << ")" << ",";
					}
					return true;
				}
			}

			Solution sol = controller.model->getSolution(mazeName);

			if(!sol.isEmpty()) {

				Maze2d maze;
				Cache::getMaze(mazeName, maze);
				
				std::stringstream ss;
				
				ss << "Solution: " << sol << "\n";

				maze.displayWithSolution(ss, sol);
				
				result = ss.str();
				return true;
			}	else {
				error = "Solution for '" + mazeName + "' not found";
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
