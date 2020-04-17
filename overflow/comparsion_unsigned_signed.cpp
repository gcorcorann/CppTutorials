#include <string>
#include <iostream>

using namespace std;

int main() {
    /* Comparison of signed and unsigned types */

    // unsigned integral types with a max value smaller than a signed int will be
    // promoted to a signed int when used in arithmetic or comparison
    signed char c = -10;
    unsigned char t = 10;
    if (c < t) {
        cout << to_string(c) << " < " << to_string(t) << endl;
    }
    else {
        cout << to_string(c) << " > " << to_string(t) << endl;
    }
    // unsigned integral types with a max value larger than a signed int will
    // promote both operands to the unsigned counterpart
    signed int x = -10;
    unsigned int y = 100;
    if (x < y) {
        cout << to_string(x) << " < " << to_string(y) << endl;
    }
    else {
        cout << to_string(x) << " > " << to_string(y) << endl;
    }
}
