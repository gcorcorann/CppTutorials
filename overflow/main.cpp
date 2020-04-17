#include <string>
#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

void printLine(string message) {
    cout << message << endl;
}

void printLine() {
    cout << endl;
}

void wrapping() {
    unsigned char uchar = 0b11110101;  // 245
    signed char schar = 0b11110101;  // -11
    printLine("Demostration of wrapping");
    printLine( "========================");
    printLine("Number of bytes for char: " + to_string(sizeof(char)));
    printLine("0b11110101 byte represented in the follow ways...");
    printLine("Char:");
    printLine("\tunsigned: " + to_string(uchar));
    printLine("\tsigned: " + to_string(schar));
    printLine();
}

void unsignedOverflow() {
    unsigned char x = 200;  // 0b11001000
    unsigned char y = 100;  // 0b01100100
    unsigned char r = x + y;  // 0b00101100
    printLine("Demostration of unsigned overflow");
    printLine("=================================");
    printLine("unsigned char x = " + to_string(x) + " (0b11001000)");
    printLine("\t + ");
    printLine("unsigned char y = " + to_string(y) + " (0b01100100)");
    printLine("----------------------------------");
    printLine("unsigned char r = " + to_string(r) + " (0b00101100)");
    printLine("300 % 256 = " + to_string(300 % 256));
    printLine();
}

void signedOverflow() {
    // positive overflow
    signed char s = 100;  // 0b01100100
    signed char t = 50;  // 0b00110010
    signed char r = s + t;  // 0b10010110
    printLine("Demostration of signed overflow");
    printLine("===============================");
    printLine("signed char s = " + to_string(s) + " (0b01100100)");
    printLine("\t + ");
    printLine("signed char t = " + to_string(t) + " (0b00110010)");
    printLine("--------------------------------");
    printLine("signed char r = " + to_string(r) + " (0b10010110)");
    printLine("150 % 128 - 128 = " + to_string(150 % 128 - 128));
}

//void signedUnderflow() {
//    // negative overflow
//    s = -100;
//    t = -50;
//    r = s + t;
//    printLine("Overflow with negatives.");
//    printLine("-100 + -50 = -150 % 128 + 128 = " \
//        + to_string(-150 % -128 + 128) + "(" + to_string(r) + ")");
//    printLine();
//}

void detectingSignedOverflow(signed char x, signed char y) {
    signed char r = x + y;
    printLine("Detecting signed overflow");
    printLine("=========================");
    printLine(to_string(x) + " + " + to_string(y) + " = " + to_string(r));
    if (x > 0 && y > 0 && r < 0) {
        printLine("Overflow detected.");
    }
    else if (x < 0 && y <0 && r >= 0) {
        printLine("Overflow detected.");
    }
    printLine();
}

void detectingUnsignedOverflow(unsigned char x, unsigned char y) {
    unsigned char r = x + y;
    printLine("Detecting unsigned overflow");
    printLine("===========================");
    printLine(to_string(x) + " + " + to_string(y) + " = " + to_string(r));
    if (r < x || r < y) {
        printLine("Overflow detected.");
    }
    printLine();
}

int main() {
//    wrapping();
//    unsignedOverflow();
//    signedOverflow();
//    detectingSignedOverflow(-89, -66);
//    detectingSignedOverflow(77, 94);
//    detectingSignedOverflow(40, 51);
//    detectingUnsignedOverflow(101, 193);
//    detectingUnsignedOverflow(50, 99);

    char c;
    short s = 398;
    c = s;
    printLine(to_string(c));

    short a;
    int b = 57973;
    a = b;
    printLine(to_string(a));
}
