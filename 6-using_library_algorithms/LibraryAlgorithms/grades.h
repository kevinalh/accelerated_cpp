#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

double median(std::vector<double>);
double average(const std::vector<double>&);
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);