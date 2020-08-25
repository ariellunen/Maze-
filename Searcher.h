#pragma once

#include "Solution.h"
#include "Searchable.h"

class Searcher
{
public:
	//pure virstual functions
	virtual Solution search(Searchable& s) = 0;
	virtual int getNumberOfNodesEvaluated() = 0;
};

