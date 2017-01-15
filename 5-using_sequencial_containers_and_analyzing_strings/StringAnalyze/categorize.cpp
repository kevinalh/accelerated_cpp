#include <list>
#include <stdexcept>
#include "grades.h"
#include "median.h"
#include "Student_info.h"

using std::list;

// Using iterators and lists

list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}

/* Avoiding the unnecessary copy

vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;
	// invariant: [0, i) are students with passing grades
	while (i != students.size()) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
			students.erase(students.begin() + i);
		}
		else
			++i;
	}
	return fail;
}
*/

/* Naive approach

vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> pass, fail;
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		if (fgrade(students[i]))
			fail.push_back(students[i]);
		else
			pass.push_back(students[i]);
	}
	students = pass;
	return fail;
	}
*/
