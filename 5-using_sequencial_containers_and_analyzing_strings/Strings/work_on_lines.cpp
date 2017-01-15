#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include "split_string.h"

#pragma region using
using std::string;
using std::vector;
using std::isspace;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
#pragma endregion

int main() {
	string s;
	while (getline(cin, s)) {
		vector<string> v = split(s);
		for (vector<string>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
	}
	return 0;
}