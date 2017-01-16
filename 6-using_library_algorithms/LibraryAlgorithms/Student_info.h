#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student_info {
	std::string name;
	double midterm_ex, final_ex;
	std::vector<double> homework;
};

bool did_all_hw(const Student_info&);
bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);