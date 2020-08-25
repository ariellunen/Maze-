#pragma once

#include "State.h"

class Heuristic {
public:
	virtual double calculate(State& currState, State& targetState) noexcept = 0;
};