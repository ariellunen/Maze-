#pragma once

#include <vector>
#include "State.h"

class Searchable
{
public:
	//pure virstual functions
	virtual const State& getStartState() const = 0;
	virtual const State& getGoalState() const = 0;
	virtual std::vector<State> getAllPossibleStates(State& s) = 0;
};

