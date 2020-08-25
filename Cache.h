#pragma once

#include <experimental/filesystem>
#include <map>
#include <string_view>
#include <sstream>
#include <string>
#include "MazeCompression.h"

class Cache {

public:
	static std::map<std::string, Maze2d> mazeMap;
	static std::map<std::string, std::vector <std::pair<int, int>>> Mysol;



	static void initializeCache() {
		std::ifstream init("solves.mz", std::ios_base::app);
		int i = 1;
		int j = 3;
		map<std::string, vector <pair<int, int>>> temp;
		std::string MazeName;
		if (!(init.peek() == std::ifstream::traits_type::eof())) {
			while (!init.eof()) {
				std::string line;
				std::getline(init, line);
				if (line[0] == '#') {
					line = line.erase(0, 1);
					MazeName = line;
				}
				if (line[0] == '*') {
					int size = line.size();
					for (int k = 0; k <= size; k = k + 5)
					{
						const string a = std::to_string(line[i] - '0');
						int x = std::stoi(a);
						const string b = std::to_string(line[j] - '0');
						int y = std::stoi(b);
						pair<int, int> p;
						p.first = x;
						p.second = y;
						temp[MazeName].push_back(p);
						i += 5;
						j += 5;
					}
				}
				i = 1;
				j = 3;
			}
		}
		readSol(temp);

		for (auto& p : std::experimental::filesystem::directory_iterator(".")) {
			std::string fileName = p.path().filename().string();
			std::string_view v(fileName);
			auto trim_pos = v.find(".txt");
			if (trim_pos != v.npos) {
				v.remove_suffix(v.size() - trim_pos);
				Maze2d maze;

				if (MazeCompression().readMaze(fileName, maze)) {
					mazeMap.insert(std::pair<std::string, Maze2d>(v, maze));
				}
			}
		}
	}






	static void saveMaze(std::string Mazename, Maze2d& maze, bool writeFile) {
		mazeMap.erase(Mazename);
		mazeMap.insert(std::pair<std::string, Maze2d>(Mazename, maze));
		if(writeFile) {
			std::string fileName = Mazename + ".txt";
			MazeCompression().writeMaze(maze, fileName);
		}
	}

	static void saveMaze(std::string FileName ,std::string Mazename, Maze2d& maze, bool writeFile) {
		// saving the maze to .txt file
		mazeMap.erase(Mazename);
		mazeMap.insert(std::pair<std::string, Maze2d>(Mazename, maze));
		if (writeFile) {
			std::string fileName = FileName + ".txt";
			MazeCompression().writeMaze(maze, fileName);
		}
	}



	static void readSol(map<std::string, vector <pair<int,int>>> temp)
	{
		Mysol = temp;
	}



	static long getMazeCompressedSize(Maze2d& maze) {
		return MazeCompression().getMazeCompressionSize(maze);
	}

	static bool getMaze(std::string name, Maze2d& maze) {
		std::map<std::string, Maze2d>::iterator it;
		it = mazeMap.find(name);
		if(it != mazeMap.end()) {
			maze = it->second;
			return true;
		} else {
			std::string fileName = name + ".txt";
			return MazeCompression().readMaze(fileName, maze);
		}
	}
};

std::map<std::string, Maze2d> Cache::mazeMap = {};
std::map<std::string, std::vector <std::pair<int, int>>>Cache::Mysol = {};

