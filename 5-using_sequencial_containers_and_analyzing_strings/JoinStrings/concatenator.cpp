#include <string>
#include <vector>
#include <iostream>
#include "join_strings.h"
using std::cin;		using std::cout;
using std::string;	using std::vector;
using std::endl;	using std::getline;

int main() {
	cout << "Please enter the first vector of strings: " << endl;
	vector<string> first, second, h_cat, v_cat;
	string current;
	cin.ignore();
	while (getline(cin, current)) {
		first.push_back(current);
	}
	cout << "Please enter the second vector of strings: " << endl;
	cin.clear();
	while (getline(cin, current)) {
		second.push_back(current);
	}
	first = frame(first);
	second = frame(second);
	h_cat = hcat(first, second);
	for (vector<string>::size_type i = 0; i != h_cat.size(); i++) {
		cout << h_cat[i] << endl;
	}
	cout << endl;
	v_cat = vcat(first, second);
	for (vector<string>::size_type i = 0; i != v_cat.size(); i++) {
		cout << v_cat[i] << endl;
	}
	system("pause");
	return 0;
}