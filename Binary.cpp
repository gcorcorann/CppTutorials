#include <iostream>

int main() {
    char c = 'c';
    unsigned char uc = 'c';
    int x = 0b1100011;
    char b = 0b1100011;
    unsigned char ub = 0b1100011;
    char t = 99;

    std::cout << ub << std::endl;
    std::cout << (char) ub << std::endl;

    // convert unsigned char (160) to signed char
    std::cout << "Unsigned to signed char when greater than +127" << std::endl;
    unsigned char big = 160;
    std::cout << big << std::endl;
    std::cout << (char) big << std::endl;

    char y = 0b01111100;
    std::cout << "signed 0b0111100 as character: " << y << std::endl; 
    std::cout << "signed 0b0111100 converted to unsigned character: " << (unsigned char) y << std::endl; 
}
