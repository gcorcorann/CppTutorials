#include <iostream>
#include <fstream>

#include "student.h"

int main() {
    std::ofstream wf("student.pat", std::ios::out | std::ios::binary);
    if (!wf) {
        std::cout << "Cannot open file!" << std::endl;
        return 1;
    }
    Student students[3];
    students[0].roll_no = 65;
    students[0].name = "Steve";
    students[1].roll_no = 66;
    students[1].name = "Chris";
    students[2].roll_no = 67;
    students[2].name = "Amy";
    for (size_t i = 0; i < 3; ++i) {
        wf.write((char*) &students[i], sizeof(Student));
    }
    wf.close();
    if (!wf.good()) {
        std::cout << "Error occurred at writing time!" << std::endl;
        return 1;
    }
    return 0;
}
