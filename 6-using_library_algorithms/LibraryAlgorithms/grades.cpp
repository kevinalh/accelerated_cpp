#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include "Student_info.h"

using std::vector;
using std::domain_error;
using std::sort;
using std::accumulate;

double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");
	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size & 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double average(const vector<double>& v) {
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double grade(double midterm_ex, double final_ex, double homework) {
	return 0.2 * midterm_ex + 0.4 * final_ex + 0.4 * homework;
}

double grade(double midterm_ex, double final_ex, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("Student has done no homework");
	return grade(midterm_ex, final_ex, median(hw));
}

double grade(const Student_info& s) {
	return grade(s.midterm_ex, s.final_ex, s.homework);
}