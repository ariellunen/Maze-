#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include "State.h"

class Solution
{
public:
	Solution() {}
	~Solution() {}

	void addState(State* s) {
		m_solution.push_back(s);
	}

	void finalize() {
		std::reverse(m_solution.begin(), m_solution.end());
	}

	void display(std::ostream& out) const {
		//prints maze
		for (unsigned int i = 0; i < m_solution.size(); ++i) {

			Position pos = m_solution[i]->getState();
			out << '(' << pos.row() << ", " << pos.column() << ")";
			
			if (i < m_solution.size() - 1)
				out << ", ";
		}
	}


	bool isEmpty() {
		// if there is no any solution
		return m_solution.size() == 0;
	}

	bool isInSolution(Position pos) {
		for(auto sol: m_solution)
			if(sol->getState() == pos)
				return true;

		return false;
	}

	static auto getVector()  {
		return m_solution;
	}

	static auto setVector(std::vector<State*> sol) {
		int i = 0;
		m_solution.resize(sol.size());
		for (auto value : sol)
		{
			m_solution[i] = value;
			i++;
		}
	}

public:
	static std::vector<State*> m_solution;
};

std::ostream& operator<<(std::ostream& out, const Solution& sol) {
	sol.display(out);
	return out;
}

std::vector<State*> Solution::m_solution = {};