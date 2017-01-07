#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::string;
using std::cout;
using std::endl;

int main() {
    cout << "Enter words: ";
    typedef string::size_type ssz;
    string word, shortest, longest;
    cin >> word;
    ssz word_length = word.size(),
        short_length = word_length,
        long_length =  word_length; 
    while (cin >> word) {
        word_length = word.size();
        if (word_length <= short_length) {
            short_length = word_length;
            shortest = word;
        } else if (word_length >= long_length) {
            long_length = word_length;
            longest = word;
        }
    }
    cout << "The longest word was: " << longest
        << ", and the shortest: " << shortest << endl;
    return 0;
}
