#include <iostream>
#include <fstream>

#include "student.h"

int main() {
    std::ifstream rf("student.pat", std::ios::out | std::ios::binary);
    if (!rf) {
        std::cout << "Cannot open read file!" << std::endl;
        return 1;
    }
    Student students[3];
    for (size_t i = 0; i < 3; i++) {
        rf.read((char*) &students[i], sizeof(Student));
    }
    rf.close();
    if (!rf.good()) {
        std::cout << "Error occured at reading time!" << std::endl;
        return 1;
    }
    std::cout << "Student's Details:" << std::endl;
    for (size_t i = 0; i < 3; ++i) {
        std::cout << "Roll No: " << students[i].roll_no << std::endl;
        std::cout << "Name: " << students[i].name << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
