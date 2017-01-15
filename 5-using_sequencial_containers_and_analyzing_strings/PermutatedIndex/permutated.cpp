#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> get_words(string);
vector<string> rotate(string);
string unrotate(string, string::size_type);
string::size_type width(const vector<string>&);

int main() {
	vector<string> all_phrases, all_rotations;
	string phrase;
	while (getline(cin, phrase)) {
		all_phrases.push_back(phrase);
	}
	vector<string>::size_type amount_of_phrases = all_phrases.size();
	for (vector<string>::size_type i = 0; i != amount_of_phrases; i++) {
		vector<string> current_phrase = rotate(all_phrases[i]);
		all_rotations.insert(all_rotations.end(), current_phrase.begin(), current_phrase.end());
	}
	sort(all_rotations.begin(), all_rotations.end());
	cout.clear();
	string::size_type width1 = width(all_rotations);
	for (vector<string>::size_type i = 0; i != all_rotations.size(); i++) {
		cout << unrotate(all_rotations[i], width1) << endl;
	}
	system("pause");
	return 0;
}

string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		maxlen = max(maxlen, v[i].size());
	}
	return maxlen;
}

vector<string> get_words(string line) {
	vector<string> words;
	string::size_type i = 0;
	while (i < line.size()) {
		string current;
		while (!isspace(line[i]) && i != line.size()) {
			current += line[i];
			i++;
		}
		if ((isspace(line[i]) || i == line.size()) && current.size() != 0) {
			words.push_back(current);
			i++;
		}
	}
	return words;
}

vector<string> rotate(string line) {
	vector<string> rotated, words;
	words = get_words(line);
	vector<string>::size_type amount_of_words = words.size();
	for (vector<string>::size_type i = 0; i != amount_of_words; ++i) {
		string phrase;
		for (vector<string>::size_type j = i; j != amount_of_words; ++j) {
			if (j != i)
				phrase += ' ';
			phrase += words[j];
		}
		for (vector<string>::size_type j = 0; j != i; ++j) {
			phrase += ' ';
			phrase += words[j];
		}
		phrase += to_string(i);
		rotated.push_back(phrase);
	}
	return rotated;
}

string unrotate(string phrase, string::size_type width1) {
	// Works for less than 9 words, very unelegant
	// Using - '0' for transforming char into integer
	int word_number = *(--phrase.end()) - '0';
	phrase.erase(phrase.end() - 1, phrase.end());
	vector<string> words = get_words(phrase);
	typedef vector<string>::size_type size;
	size amount_of_words = words.size();
	string s;
	for (size i = amount_of_words - word_number; i != amount_of_words; i++) {
		s += (words[i] + " ");
	}
	s += string(width1 - s.size(), ' ');
	for (size i = 0; i != amount_of_words - word_number; i++)
	{
		s += (words[i] + " ");
	}
	return s;
}