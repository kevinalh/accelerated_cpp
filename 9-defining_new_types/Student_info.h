#pragma once

#include <string>
#include <vector>
#include <iostream>

double median(std::vector<double>);
double grade(double, double, double);
std::istream& read_hw(std::istream&, std::vector<double>&);

class Student_info {
public:
	double grade() const;
	std::istream& read(std::istream&);
	std::string name() const { return n; }
	bool valid() const { return !homework.empty(); }
	// Constructors
	Student_info();
	Student_info(std::istream&);
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
