#include <map>
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::map;
using std::endl;

int main() {
	string s;
	map<string, int> counters;
	while (cin >> s)
		++counters[s];
	for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}
}