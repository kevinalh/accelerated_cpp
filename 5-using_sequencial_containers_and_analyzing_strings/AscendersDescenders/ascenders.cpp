#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

bool has_ascender_or_descender(string);
bool is_ascender(char);
bool is_descender(char);

int main() {
	string word;
	vector<string> dictionary, longest;
	string::size_type maxlen = 0;
	ifstream infile;
	string fileloc = "words3.txt";
	infile.open(fileloc);
	if (!infile) {
		cout << "Error opening file" << endl;
		system("pause");
		return 1;
	}
	while (getline(infile, word)) {
		dictionary.push_back(word);
	}
	cout << "The longest words without ascenders or descenders are: " << endl;
	for (vector<string>::size_type i = 0; i != dictionary.size(); i++) {
		if (!has_ascender_or_descender(dictionary[i]) && dictionary[i].size() > maxlen) {
			longest.clear();
			longest.push_back(dictionary[i]);
			maxlen = dictionary[i].size();
			continue;
		}
		if (!has_ascender_or_descender(dictionary[i]) && dictionary[i].size() == maxlen) {
			longest.push_back(dictionary[i]);
		}
	}
	if (maxlen == 0) {
		cout << "None" << endl;
	}
	else
		for (vector<string>::size_type i = 0; i != longest.size(); i++) {
			cout << longest[i] << endl;
		}
	system("pause");
	return 0;
}

bool has_ascender_or_descender(string word) {
	for (string::size_type i = 0; i != word.size(); i++) {
		if (is_ascender(word[i]) || is_descender(word[i]))
			return true;
	}
	return false;
}

bool is_ascender(char l) {
	if (l == 'b' || l == 'd' || l == 'f' || l == 'k' || l == 'h' || l == 'l' || l == 't')
		return true;
	else return false;
}

bool is_descender(char l) {
	if (l == 'g' || l == 'j' || l == 'p' || l == 'q' || l == 'y')
		return true;
	else return false;
}