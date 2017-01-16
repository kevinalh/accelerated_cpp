#include <stdexcept>
#include <iostream>
#include <string>
#include "Student_info.h"
#include "grades.h"

using std::vector;
using std::domain_error;
using std::transform;
using std::ostream;
using std::string;
using std::endl;
using std::cin;
using std::cout;

double grade_aux(const Student_info& s) {
	try {
		return grade(s);
	}
	catch (domain_error) {
		return grade(s.midterm_ex, s.final_ex, 0);
	}
}

double average_grade(const Student_info& s) {
	return grade(s.midterm_ex, s.final_ex, average(s.homework));
}

double optimistic_median(const Student_info& s) {
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
	if (nonzero.empty())
		return grade(s.midterm_ex, s.final_ex, 0);
	else
		return grade(s.midterm_ex, s.final_ex, median(nonzero));
}

double median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

double average_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}

// Left as an exercise
double optimistic_median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&),
	const vector<Student_info>& did, const vector<Student_info>& didnt) {
	out << name << ": median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
	return;
}

int main() {
	vector<Student_info> did, didnt;
	Student_info student;
	while (read(cin, student)) {
		if (did_all_hw(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}
	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;
	}
	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
	}
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);
	return 0;
}