#pragma once

#include <fstream>
#include <string>

#include "Maze2d.h"
#include "Solution.h"
#include <sstream>
#include "../Utils.h"

class MazeCompression {

public:
	void writeMaze(const Maze2d& maze, const std::string& filename) {
		//writing maze to file
		Position start_pos = maze.getStartPosition();
		Position end_pos = maze.getGoalPosition();

		const std::vector<std::vector<int>> &data = maze.getRaw();

		int nrow = maze.rows();
		int ncol = maze.columns();

		std::vector<int> flat_data(data.size() * data[0].size());

		unsigned int ind = 0;
		for (unsigned int row = 0; row < data.size(); ++row) {
			for (unsigned int col = 0; col < data[0].size(); ++col) {
				flat_data[ind++] = data[row][col];
			}
		}

		std::ofstream outFile(filename.c_str());
	
		outFile << start_pos << '\t' << end_pos << std::endl;
		outFile << nrow << ',' << ncol << std::endl;

		int count = 0;
		int curr_val = flat_data[0];

		for (ind = 0; ind < flat_data.size(); ++ind) {
			if (flat_data[ind] == curr_val)
				count++;
			else {
				outFile << count << ',' << curr_val << ',';
				curr_val = flat_data[ind];
				count = 1;
			}
		}

		outFile << count << ',' << curr_val;
		outFile.close();
	}



	unsigned long getMazeCompressionSize(const Maze2d& maze) {

		Position start_pos = maze.getStartPosition();
		Position end_pos = maze.getGoalPosition();

		const std::vector<std::vector<int>> &data = maze.getRaw();

		int nrow = maze.rows();
		int ncol = maze.columns();

		std::vector<int> flat_data(data.size() * data[0].size());

		unsigned int ind = 0;
		for (unsigned int row = 0; row < data.size(); ++row) {
			for (unsigned int col = 0; col < data[0].size(); ++col) {
				flat_data[ind++] = data[row][col];
			}
		}

		std::stringstream out;

		int count = 0;
		int curr_val = flat_data[0];

		for (ind = 0; ind < flat_data.size(); ++ind) {
			if (flat_data[ind] == curr_val)
				count++;
			else {
				out << count << ',' << curr_val << ',';
				curr_val = flat_data[ind];
				count = 1;
			}
		}

		out << count << ',' << curr_val;
		
		return (long(out.tellp()));
	}

	bool readMaze(const std::string& filename, Maze2d& maze) {
		//read maze from txt file 
		std::ifstream iFile(filename.c_str());

		if (!iFile.is_open()) {
			return false;
		}
		std::string record;
		std::getline(iFile, record);

		auto tokens = split(record, '\t');

		auto start_tok = split(tokens[0], ',');
		start_tok[0].erase(start_tok[0].begin());
		start_tok[1].pop_back();

		auto end_tok = split(tokens[1], ',');
		end_tok[0].erase(end_tok[0].begin());
		end_tok[1].pop_back();

		Position start_pos(std::stoi(start_tok[0]), std::stoi(start_tok[1]));
		Position end_pos(std::stoi(end_tok[0]), std::stoi(end_tok[1]));

		int nrow, ncol;
		std::getline(iFile, record);
		tokens = split(record, ',');
		
		nrow = std::stoi(tokens[0]);
		ncol = std::stoi(tokens[1]);

		std::getline(iFile, record);
		tokens = split(record, ',');

		std::vector<std::vector<int>> mazeData(nrow * 2 + 1, std::vector<int>(ncol * 2 + 1));

		int curr_count = std::stoi(tokens[0]);
		int curr_val = std::stoi(tokens[1]);

		unsigned int ind = 2;
		
		for (unsigned int row = 0; row < mazeData.size(); ++row) {
			for (unsigned int col = 0; col < mazeData[0].size(); ++col) {

				mazeData[row][col] = curr_val;
				--curr_count;
				
				if (curr_count <= 0 && ind < tokens.size()) {
					
					curr_count = std::stoi(tokens[ind]);
					curr_val = std::stoi(tokens[ind + 1]);

					ind += 2;
				}
			}
		}
		
		maze =  Maze2d(nrow, ncol, mazeData, start_pos, end_pos);
		return true;
	}



};


