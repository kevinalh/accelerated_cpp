#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>
#include <string>
#include <cctype>

using std::vector;
using std::domain_error;
using std::cout;
using std::endl;
using std::swap;
using std::cin;
using std::cout;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::string;
using std::find_if;
using std::isspace;

template<class T>
T median(vector<T> v) {
	typedef typename vector<T>::size_type vec_sz;
	vec_sz size = v.size();
	if (size == 0) {
		throw domain_error("Median of an empty vector");
	}
	sort(v.begin(), v.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

template<class T>
T custom_max(const T& left, const T& right) {
	return left > right ? left : right;
}

// In is an input iterator
template<class In, class X> In custom_find(In begin, In end, const X& x) {
	while (begin != end && *begin != x) {
		++begin;
	}
	return begin;
}

// Out in an output iterator
template<class In, class Out>
Out custom_copy(In begin, In end, Out dest) {
	while (begin != end) {
		*dest++ = *begin++;
	}
	return dest;
}

// For is a forward iterator
template<class For, class X>
void custom_replace(For beg, For end, const X& x, const X& y) {
	while (beg != end) {
		if (*beg == x) {
			*beg = y;
		}
		++beg;
	}
}

// Bi is a bidirectional iterator
template<class Bi> void custom_reverse(Bi begin, Bi end) {
	while (begin != end) {
		--end;
		if (begin != end) {
			swap(*begin++, *end);
		}
	}
}

// Ran is a random-access iterator
template<class Ran, class X>
bool custom_binary_search(Ran begin, Ran end, const X& x) {
	while (begin < end) {
		Ran mid = begin + (end - begin) / 2;
		if (x < *mid) {
			end = mid;
		}
		else if (*mid < x) {
			begin = mid + 1;
		}
		else return true;
	}
	return false;
}

bool space(char c) {
	return isspace(c);
}

bool not_space(char c) {
	return !isspace(c);
}

template<class Out>
void split(const string& str, Out os) {
	typedef string::const_iterator iter;
	iter i = str.begin();

	while (i != str.end()) {
		i = find_if(i, str.end(), not_space);
		iter j = find_if(i, str.end(), space);
		if (i != str.end()) {
			*os++ = string(i, j);
		}
		i = j;
	}
}

int main() {
	vector<int> v;
	cout << "Write some numbers: " << endl;
	// istream_iterator gives an input iterator
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
	// ostream_iterator gives an output iterator
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl << "Write some sentences: " << endl;
	cin.clear();
	string s;
	while (getline(cin, s)) {
		split(s, ostream_iterator<string>(cout, "\n"));
	}
	return 0;
}
