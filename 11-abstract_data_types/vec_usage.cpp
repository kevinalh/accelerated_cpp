#include <iostream>

#include "Vec.h"

int main() {
	Vec<long long> a(10, 5);
	a.push_back(3);
	a.push_back(1);
	for(Vec<long long>::size_type i = 0; i < a.size(); ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	a.erase(a.begin());
	a.erase(a.end()-1);
	for(Vec<long long>::const_iterator it = a.begin(); it != a.end(); ++it) {
			std::cout << *it << " ";
		}
	std::cout << std::endl;
	return 0;
}
