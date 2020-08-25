#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "../Controller/Controller.h"
#include "View.h"
#include "../Utils.h"
class MyCLIView : public View {

private:

	std::istream& in;
	std::ostream& out;


public:
	MyCLIView(std::istream& _in, std::ostream& _out) : in(_in), out(_out) 
	{

	}

	virtual void start() {

		//Program navigation function.
		//For each function, select the number displayed on the console.
		std::vector<std::string> inputs;
		std::string input;
		std::vector<std::string> numbers;
		std::string number;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

		out << ".___________. __    __   _______       .___  ___.     ___      ________   _______     __" << endl;
		out << "|           ||  |  |  | |   ____|      |   \\/   |    /   \\    |       /  |   ____|   |  |" << endl;
		out << "`---|  |----`| | __|  | |  |__         |  \\  /  |   /  ^  \\   `---/  /   |  |__      |  |" << endl;
		out << "    |  |     |   __   | |   __|        |  |\\/|  |  /  /_\\  \\     /  /    |   __|     |  |" << endl;
		out << "    |  |     |  |  |  | |  |____       |  |  |  | /  _____  \\   /  /----.|  |____    |__|" << endl;
		out << "    |__|     |__|  |__| |_______|      |__|  |__|/__/     \\__\\ /________||_______|   (__)" << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		out << "All possible commands:" << std::endl;
		out << "(For selecting a command write down its number)" << std::endl;
		out << "1. View all files and folders" << std::endl;
		out << "2. Create a new maze" << std::endl;
		out << "3. Print the maze" << std::endl;
		out << "4. Save the maze inside the file" << std::endl;
		out << "5. The claim of the maze from the file" << std::endl;
		out << "6. Display the size of the maze in memory" << std::endl;
		out << "7. Display the size of the maze in the file" << std::endl;
		out << "8. Choosing an algorithm for the solution" << std::endl;
		out << "9. Presentation of the solution steps" << std::endl;
		out << "If you have finished choosing - write 'exit'" << std::endl;

		do {
			std::getline(in, number);
			std::transform(number.begin(), number.end(), number.begin(), ::tolower);
			if (number == "exit")
			{
				numbers.push_back("-1");
			}
			else
			{
				int choice = std::stoi(number);
				if (choice > 0 && choice < 10)
				{
					numbers.push_back(number);
				}
				else
				{
					out << "Select number only from the suggested list" << std::endl;
				}
			}
		} while (number != "exit");

		system("CLS");

		int vec_size = numbers.size();
		for (int i = 0; i < vec_size; i++)
		{
			int cell = stoi(numbers[i]);
			switch (cell)
			{
			case 1:
				out << "To execute command 1, enter the command: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				out << "'dir <path>'" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				out << "write here: ";
				std::getline(in, input);
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				inputs.push_back(input);
				break;
			case 2:
				out << "To execute command 2, enter the command: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				out << "'generate maze <name><Random/backtracker> <Row> <Cols>'" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				out << "write here: ";
				std::getline(in, input);
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				inputs.push_back(input);
				break;
			case 3:
				out << "To execute command 3, enter the command: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				out << "'display <name>'" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				out << "write here: ";
				std::getline(in, input);
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				inputs.push_back(input);
				break;
			case 4:
				out << "To execute command 4, enter the command: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				out << "'save maze <name> <file name>'" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				out << "write here: ";
				std::getline(in, input);
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				inputs.push_back(input);
				break;
			case 5:
				out << "To execute command 5, enter the command: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				out << "'load maze <file name> <name>'" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				out << "write here: ";
				std::getline(in, input);
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				inputs.push_back(input);
				break;
			case 6:
				out << "To execute command 6, enter the command: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				out << "'maze size <name>'" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				out << "write here: ";
				std::getline(in, input);
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				inputs.push_back(input);
				break;
			case 7:
				out << "To execute command 7, enter the command: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				out << "'file size <name>'" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				out << "write here: ";
				std::getline(in, input);
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				inputs.push_back(input);
				break;
			case 8:
				out << "To execute command 8, enter the command: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				out << "'solve <name> <algorithm>'" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				out << "write here: ";
				std::getline(in, input);
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				inputs.push_back(input);
				break;
			case 9:
				out << "To execute command 9, enter the command: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				out << "'Display solution <name>'" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				out << "write here: ";
				std::getline(in, input);
				//std::transform(input.begin(), input.end(), input.begin());//, ::tolower);
				inputs.push_back(input);
				break;
			case -1:
				input = "exit";
				inputs.push_back(input);
				break;
			default:
				break;
			}
		}

		out << "Processing commands" << std::endl;

		auto cmdMap = controller->getCommandList();

		for (std::string& input : inputs) {

			auto tokens = split(input, ' ');

			Command* cmd = nullptr;

			if (tokens.size()) {

				auto iter = cmdMap.find(tokens[0]);

				if ((iter != cmdMap.end())
					|| (tokens.size() >= 2 && (iter = cmdMap.find(tokens[0] + ' ' + tokens[1])) != cmdMap.end())) {
					cmd = iter->second;
				}
			}

			if (cmd != nullptr) {
				// command found
				bool status = cmd->doCommand(tokens, *this, *controller);

				if (status) {
					if (input != "exit") {
						out << cmd->getResult() << std::endl;
					}
				}
				else {
					out << "Error running command '" << input << "'." << std::endl;
					out << cmd->getError() << std::endl;
				}
			}
			else {
				out << "Unrecognized command '" << input << "'." << std::endl;
			}
			out << std::endl;
			if (this->exit) {
				return;
			}
		}
	}

	virtual void display(const std::string& msg) {
		out << msg << std::endl;
	}
};
