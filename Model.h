#pragma once
#include "Solution.h"

class Model {
public: 
	Model() {}
	virtual bool addSolution(std::string mazeName, Solution sol) = 0;
	virtual Solution getSolution(std::string mazeName) = 0;
};
