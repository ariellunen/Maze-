#pragma once

#include <string>

class Controller;

class View {

protected:
	Controller* controller;

	bool exit;
public:
	View():controller(0) , exit(false){ }

	virtual void start() = 0;

	virtual void display(const std::string& msg) = 0;

	virtual void setController(Controller* controller) {
		this->controller = controller;
	}

	virtual void terminate() {
		this->exit = true;
	}
};
