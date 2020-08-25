#pragma once

#include "State.h"

class Maze2dState : public State
{

public:
	Maze2dState(const Position& state) : State(state) {};
	~Maze2dState() {}


};

