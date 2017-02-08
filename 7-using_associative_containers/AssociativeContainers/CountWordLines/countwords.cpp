#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "split.h"

using std::vector;
using std::string;
using std::map;
using std::getline;
using std::istream;
using std::cin;
using std::cout;
using std::endl;

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split) {
	string line;
	int line_number = 0;
	map<string, vector<int>> ret;
	while (getline(in, line)) {
		++line_number;
		vector<string> words = find_words(line);
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
			ret[*it].push_back(line_number);
	}
	return ret;
}

int main() {
	map<string, vector<int> > ret = xref(cin);
	for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
		cout << it->first << " occurs on line(s): ";
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it;
		++line_it;
		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}
		cout << endl;
	}
	return 0;
}