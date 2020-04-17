#include <iostream>
using namespace std;

int main() {
    // integer literal
    /* In addition to decimal numbers, the use of octal and hexadecimal numbers
     * can be used at literal constants */
    int decimal = 75;
    int octal = 0113;
    int hexadecimal = 0x4b;

    cout << "decimal number: " << decimal << endl;
    cout << "octal number: " << octal << endl;
    cout << "hexadecimal number: " << hexadecimal << endl;

    /* certain suffixes may be appended to an integer literal to specify a different type
     * of integer (suffixes can be upper or lowercase) */
    int normalInt = 75;
    int unsignedInt = 75u;
    int longInt = 75l;
    int unsignedLongInt = 75ul;
    int longUnsignedInt = 75lu;
    cout << "normal integer: " << normalInt << endl;
    cout << "unsigned integer: " << unsignedInt << endl;
    cout << "long integer: " << longInt << endl;
    cout << "unsigned long integer: " << unsignedLongInt << endl;
    cout << "long unsigned integer: " << longUnsignedInt << endl;


    // Floating Point Numbers
    double normalFloat = 3.14159;
    double exponentFloat = 6.02e23;
    double exponentNegativeFloat = 1.6e-9;
    cout << "normal float: " << normalFloat << endl;
    cout << "exponent float: " << exponentFloat << endl;
    cout << "exponent negative float: " << exponentNegativeFloat << endl;
    /* default type for floating-point literal is double, floating-point literals of
     * type float or long double can be specified by adding a suffix */
    double longDouble = 3.14159L;
    float actualFloat = 6.02e23f;
    cout << "long double: " << longDouble << endl;
    cout << "actual float: " << actualFloat << endl;

    // Character and strings literals
    char c1 = 'z';
    char c2 = 'p';
    return 0;
}
