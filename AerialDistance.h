#pragma once

#include "Heuristic.h"

class AerialDistance : public Heuristic {
public:
	//Heuristic function
	virtual double calculate(State& currState, State& targetState) {
		Position curr_pos = currState.getState();
		Position target_pos = targetState.getState();

		return	sqrt(pow(abs(curr_pos.row() - target_pos.row()), 2)
				       +  pow(abs(curr_pos.column() - target_pos.column()), 2));
	}
};
