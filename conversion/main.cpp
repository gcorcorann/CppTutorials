#include <iostream>
#include <sstream>
#include <string>

// RHS 0b01010011 is actually first read into an integer, then assigned to
// the LHS
// regards bits as integer then convers it

void print() {
    std::cout << "Number of bytes for short: "<< sizeof(short);
    std::cout << std::endl;
    std::cout << "Number of bytes for int: "<< sizeof(int);
    std::cout << std::endl;
    std::cout << "0b1110001001110101 represented in the follow ways...";
    std::cout << std::endl;
    std::cout << "Short:" << std::endl;
    unsigned short ushort = 0b1110001001110101;
    signed short sshort = 0b1110001001110101;
    std::cout << "\tunsigned: " << ushort << std::endl;
    std::cout << "\tsigned: " << sshort << std::endl;
    std::cout << "Int:" << std::endl;
    unsigned int uint = 0b1110001001110101;
    signed int sint = 0b1110001001110101;
    std::cout << "\tunsigned: " << uint << std::endl;
    std::cout << "\tsigned: " << sint << std::endl;
}

void print2() {
    std::cout << "Number of bytes for char: "<< sizeof(char);
    std::cout << std::endl;
    std::cout << "Number of bytes for short: "<< sizeof(short);
    std::cout << std::endl;
    std::cout << "0b11110101 represented in the follow ways...";
    std::cout << std::endl;
    std::cout << "Char:" << std::endl;
    unsigned char uchar = 0b11110101;
    signed char schar = 0b11110101;
    std::cout << "\tunsigned: " << (signed short)uchar << std::endl;
    std::cout << "\tsigned: " << (signed short)schar << std::endl;
    // this char was represented as unsigned so when we upscale it
    // left pad it with zeros
    // this char was represented as signed so when we upscale it
    // left pad it with ones
    //
    // assigned -11 to unsigned short causes the short to wrap arround
    // and this wrapped around unsigned short has the same bits set as the
    // signed int corresponding to -11 in the twos complement representation
    std::cout << "\tunsigned: " << (unsigned short)uchar << std::endl;
    std::cout << "\tsigned: " << (unsigned short)schar << std::endl;
    std::cout << "Short:" << std::endl;
    unsigned short ushort = 0b11110101;
    signed short sshort = 0b11110101;
    std::cout << "\tunsigned: " << ushort << std::endl;
    std::cout << "\tsigned: " << sshort << std::endl;
}

int main() {
//    print2();
//    unsigned short c = 0b1111111111110101;
//    unsigned short ct = 0b0000000011110101;
//    std::cout << c << std::endl;
//    std::cout << ct << std::endl;
    std::cout << std::to_string(0b11110101) << std::endl;
    std::cout << 0b11110101 << std::endl;
    std::cout << sizeof(0b11110101) << std::endl;
    signed char c = -1;
    unsigned long long int y = c;
    std::cout << y << std::endl;

}
