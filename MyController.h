#pragma once

#include <map>
#include <string>
#include <memory>
#include <string.h>

#include "Controller.h"

#include "Command.h"
#include "DirectoryCommand.h"
#include "DisplayCommand.h"
#include "ExitCommand.h"
#include "GenerateCommand.h"
#include "LoadCommand.h"
#include "SaveCommand.h"
#include "SolveCommand.h"
#include "MazeSizeCommand.h"
#include "FileSizeCommand.h"
#include "DisplaySolutionCommand.h"
#include "../Utils.h"

class MyController : public Controller {

	const std::map<std::string, Command*> cmdMap{
		{"dir",				new DirectoryCommand()},
		{"generate maze",	new GenerateCommand()},
		{"display",			new DisplayCommand()},
		{"save maze",		new SaveCommand()},
		{"load maze",		new LoadCommand()},
		{"maze size",		new MazeSizeCommand()},
		{"file size",		new FileSizeCommand()},
		{"solve",			new SolveCommand()},
		{"Display solution",new DisplaySolutionCommand()},
		{"exit",			new ExitCommand()}
	};

public:
	MyController() {

	}
	
	virtual const std::map<std::string, Command*>& getCommandList() {
		return this->cmdMap;
	}

};


