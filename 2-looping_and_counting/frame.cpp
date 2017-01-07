#include <iostream>
#include <string>

using std::cout;    using std::endl;
using std::cin;     using std::string;

int main(){
    cout << "Please enter your name: ";
    string name;
    cin >> name;
    const string greeting = "Hello " + name + "!";
    cout << "Please enter the amount of space for padding: ";
    unsigned int pad = 1;
    cin >> pad;
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;
    cout << endl;

    for (int r=0; r != rows; ++r) {
        string::size_type c = 0;
        // invariant: we have written c characters so far in the current row
        while (c != cols) {
            if (r==0 || r==rows-1 || c==0 || c==cols-1) {
                cout << "*";
                c++;
            } else {
                if (r==pad+1 && c==pad+1) {
                    cout << greeting;
                    c += greeting.size();
                } else {
                    cout << " ";
                    c++;
                }
            }
        }
        cout << endl;
    }

    cout << " " << endl;
    return 0;
}
