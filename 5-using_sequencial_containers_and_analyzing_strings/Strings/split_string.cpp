#include <string>
#include <vector>
#include <cctype>
#include "split_string.h"

#pragma region using
using std::string;
using std::vector;
using std::isspace;
#pragma endregion

vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	// inv: We have processed characters [original i, i)
	while (i != s.size()) {
		// inv: Characters in [original i, current i) are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;
		string_size j = i;
		// inv: None of the characters in range [original j, current j) is a space
		while (j != s.size() && !isspace(s[j]))
			j++;
		// If we found some nonwhitespace characters
		if (i != j) {
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}