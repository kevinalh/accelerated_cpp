#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;

int main() {
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    cout << "Enter all your homework grades, "
        "followed by end-of-file: ";
    int count = 0;
    double sum = 0;
    double x;

    // invariant:
    // we have read count grades so far, and
    // sum is the sum of the first count grades
    while (cin >> x) {
        ++count;
        sum += x;
    }

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
        << 0.2 * midterm + 0.4 * final + 0.4 * (sum/count)
        << setprecision(prec) << endl;

    return 0;
}
