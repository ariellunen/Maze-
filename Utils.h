#pragma once

#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> split(const std::string& str, char delim) {

	std::vector<std::string> tokens;

	std::string word;
	for (unsigned int i = 0; i < str.length(); ++i) {

		if (str[i] == delim) {

			if (word.length()) {
				tokens.push_back(word);
				word = "";
			}
		}
		else {
			word.push_back(str[i]);
		}
	}

	if (word.length())
		tokens.push_back(word);

	return tokens;
}

std::string toLower(std::string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}