#pragma once

#include "Command.h"
#include "../Model/AStar.h"
#include "../Model/BFS.h"
#include "../Model/CommonSearcher.h"
#include "../Model/Maze2d.h"
#include "../Model/Maze2dSearchable.h"
#include "../Model/ManhattanDistance.h"
#include "../Model/MyModel.h"
#include "../Model/Solution.h"
#include <fstream>
#include <iterator>

class SolveCommand : public Command {

private:
	std::string result;
	std::string error;
public:
	virtual bool doCommand(const std::vector<std::string>& tokens, View& view, Controller& controller) {

		if (tokens.size() == 3) {

			std::string name = tokens[1];
			std::string algorithm = tokens[2];

			int moveCost = 10;
			Heuristic *hueristic = new ManhattanDistance();

			Maze2d maze;
			Maze2dSearchable *maze2dSearchable;
			if(Cache::getMaze(name, maze)) {
				 maze2dSearchable = new Maze2dSearchable(maze);
			} else {
				error = "'" + name + "' no such maze found.";
				return false;
			}

			CommonSearcher* cS;
			if(algorithm == "bfs") {
				cS = new BFS();
			} else if(algorithm == "astar"){
				cS = new AStar(moveCost, *hueristic);
			} else {
				error = "Invalid Algorithm type";
				return false;
			}


			map<std::string, vector <pair<int, int>>>::iterator it;
			bool found = false;
			for (it = Cache::Mysol.begin(); it != Cache::Mysol.end(); it++)
			{
				if (it->first == name)
				{
					//sol.size = it->second.size());
					for (unsigned int i = 0; i < it->second.size(); i++)
					{
						int row = it->second[i].first;
						int col = it->second[i].second;
						sol[i].push_back(make_pair(row,col));
					}


					found = true;
					std::cout <<  "Solution for " + name + " is All ready made" << std::endl;
					for (unsigned int i = 0; i < sol.size(); i++) {
						std::cout << "(" << sol[i][0].first <<"," << sol[i][0].second << ")" << ",";
					}
					return true;
				}
			}
			if (found == false)
			{

				Solution sol = cS->search(*maze2dSearchable);
				controller.model->addSolution(name, sol);
				saveSol(name, sol, maze.rows(), maze.columns());
				return true;

			}
			result = "Solution for " + name + " is ready";

			return true;
		}

		return false;
	}


	void saveSol(std::string name, Solution& sol, int row , int col) 
	{
		std::ofstream output_file("solves.mz", std::ios_base::app);
		output_file << "#" << name << endl; //name 
		vector<State*> temp = sol.getVector();
		int size = sol.getVector().size();
		cout << "(" << temp[0]->getState().row() << "," << temp[0]->getState().column() << ")\t" << "(" << temp[size-1]->getState().row() << "," << temp[size-1]->getState().column() << ")";
		output_file << "(" << temp[0]->getState().row() << "," << temp[0]->getState().column() <<")\t" << "(" << temp[size-1]->getState().row() << "," << temp[size-1]->getState().column() << ")" <<endl; //start + end
		//output_file << temp[size] << endl; //end
		output_file << row << "," << col <<endl; //maze size
		State* curr_val = temp[0];
		Position temppos;
		int count = 0;
		for (unsigned int i = 0; i < temp.size() ; ++i) {
			if (temp[i]->getState() == curr_val->getState())
				count++;
			else {
				output_file << "*" << curr_val->getState().row() << " " << curr_val->getState().column() << ',';
				cout <<  curr_val->getState().row() << " " << curr_val->getState().column() << ',';
				
				curr_val = temp[i];
				count = 1;
			}
		}
		output_file <<"*"<< temp[size-1]->getState().row() << " " << temp[size-1]->getState().column() << endl;
		cout << temp[size-1]->getState().row() << " " << temp[size-1]->getState().column();
		output_file.close();

	}

	std::string getError() const {
		return "Invalid command";
	}

	std::string getResult() const {
		return result;
	}
};
