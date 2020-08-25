#pragma once

#include "CommonSearcher.h"
#include "Heuristic.h"
class AStar : public CommonSearcher
{

private:
	Heuristic &heuristic;
	const int _moveCost;
public:
	//c'tor
	AStar(int moveCost, Heuristic& h) : heuristic(h), _moveCost(moveCost) {}
	

	virtual Solution search(Searchable& s){
		
		State* curr_state = new State(s.getStartState());
		State* target_state = new State(s.getGoalState());
		
		//push to queue
		this->pushOpenList(curr_state);

		while (*curr_state != *target_state && !this->isEmpty()) {

			curr_state = this->popOpenList();
			//save to options al possible states
			std::vector<State> options = s.getAllPossibleStates(*curr_state);

			for (unsigned int i = 0; i < options.size(); ++i) {

				State* nextState = new State(options[i]);
				//Calculates the distance from the current point to the target point
				double cost = heuristic.calculate(*nextState, *target_state);
				//udate the cost of the strp
				nextState->setCost(cost + _moveCost);

				this->pushOpenList(nextState);
			}
		}

		Solution solution;
		//If I reached the goal
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
