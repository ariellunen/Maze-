#pragma once

#include "CommonSearcher.h"

class BFS : public CommonSearcher
{

public:
	virtual Solution search(Searchable& s){

		State* curr_state = new State(s.getStartState());
		State* target_state = new State(s.getGoalState());

		this->pushOpenList(curr_state);

		while (*curr_state != *target_state && !this->isEmpty()) {

			curr_state = this->popOpenList();

			std::vector<State> options = s.getAllPossibleStates(*curr_state);

			for (unsigned int i = 0; i < options.size(); ++i) {
				this->pushOpenList(new State(options[i]));
			}
		}

		Solution solution;

		if (*curr_state == *target_state) {

			while (*curr_state != s.getStartState()) {
				solution.addState(curr_state);
				curr_state = curr_state->getParent();
			}
			solution.addState(curr_state);
			solution.finalize();
		} 

		return solution; 
	};
};
