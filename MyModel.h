#pragma once

#include <map>

#include "Model.h"
#include "Solution.h"

class MyModel : public Model {
private:
	std::map<std::string, Solution> hashMap;
public:
	bool addSolution(std::string mazeName, Solution sol) {
		// Add solution to the hash table return status of 
		// either inserted or already exists
		return hashMap.insert(std::pair<std::string, Solution>(mazeName, sol)).second;
	}
	
	Solution getSolution(std::string mazeName) {
		// Get solution back
		std::map<std::string, Solution>::iterator it = hashMap.find(mazeName); 
		if(it != hashMap.end())
			return it->second;
		
		return Solution();
	}
};
