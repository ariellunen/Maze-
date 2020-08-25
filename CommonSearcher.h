#pragma once
#include "Searcher.h"
#include <queue>

class Comparator {
public:
	bool operator()(const State* left, const State* right) {
		return *left > *right;
	}
};

class CommonSearcher : public Searcher
{
public:
	CommonSearcher(): m_evaluatedNodes(0){}

//Abstraction
public:
	virtual Solution search(Searchable& s) = 0;
	virtual int getNumberOfNodesEvaluated() { return m_evaluatedNodes; };

//Additional implementation
public:
	State* popOpenList() { 
		m_evaluatedNodes++;
		State* top = m_openList.top();
		m_openList.pop(); 
		return top;
	}

	void pushOpenList(State* state) {
		m_openList.push(state);
	}

	bool isEmpty() const {
		return m_openList.empty();
	}

private:
	int m_evaluatedNodes;
	std::priority_queue<State*, vector<State*>, Comparator> m_openList;
};

