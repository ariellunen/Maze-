#pragma once

#include "Heuristic.h"

class ManhattanDistance : public Heuristic {
public:
	virtual double calculate(State& currState, State& targetState)noexcept {
		Position curr_pos = currState.getState();
		Position target_pos = targetState.getState();
		double x = abs(curr_pos.row() - target_pos.row());
		double y = abs(curr_pos.column() - target_pos.column());
		auto z = x + y;
		return z;
		
	}
};
