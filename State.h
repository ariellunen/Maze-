#pragma once

#include <string>
#include <memory>

#include "Position.h"

using namespace std;

class State
{
public:
	State(const Position& state, State* cameFrom = nullptr): m_state(state), m_cost(0), m_cameFrom(cameFrom) {}
	//State(const Position state, State* cameFrom = nullptr) : m_state(state), m_cost(0), m_cameFrom(cameFrom) {}
	State();
	State(const State& state) : m_state(state.m_state), 
		m_cost(0) {
		*this = state;
	}
	State(State* state) : m_state(state->m_state),
		m_cost(0) {
		*this = state;
	}

	~State() {};

public:

	bool operator == (const State& s) { return m_state == s.m_state; }

	bool operator!=(const State& s) { return !(*this == s); }

	State& operator=(const State &s) { 

		m_state = s.m_state;
		m_cost = s.m_cost;

		m_cameFrom = s.m_cameFrom;

		return *this;
	}

	void setCost(double cost) {
		m_cost = cost;
	}


	void setState(Position pos) {
		m_state.setrow(pos.row());
		m_state.setcol(pos.column());
		//m_state = pos;
	}

	bool operator<(const State& s) const {
		return m_cost < s.m_cost;
	}

	bool operator>(const State& s) const {
		return m_cost > s.m_cost;
	}

	Position getState() const {
		return m_state;
	}

	State* getParent() const {
		return m_cameFrom;
	}



private:
	Position			m_state;
	double				m_cost;
	State*				m_cameFrom;
};

