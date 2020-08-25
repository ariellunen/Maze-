#pragma once

#include "../Model/Cache.h"
#include "../Model/Model.h"
#include "../Model/MyModel.h"
#include "../View/View.h"

#include "Command.h"

#include <map>

class Controller {

protected:
	View* view;
public:
	Model* model;

	Controller() {
		view = { 0 };
		model = new MyModel();
		Cache::initializeCache();
	}

	virtual const std::map<std::string, Command*>& getCommandList() = 0;

	virtual void setView(View* view) {
		this->view = view;
	}
};
