#include <iostream>
#include <variant>
#include <vector>
#include <map>
#include <optional>

enum class ErrorCode {
    None = 0, NotFound = 1, NoAccess = 2
};

std::variant<std::string, ErrorCode> ReadFileAsString() {
    return {};
}

int main() {
    test();
    std::variant<std::string, int> data;
    std::cout << sizeof(int) << '\n';
    std::cout << sizeof(std::string) << '\n';
    std::cout << sizeof(data) << '\n';
    data = "Patrick";
    std::cout << std::get<std::string>(data) << '\n';
    data = 2;
    std::cout << std::get<int>(data) << '\n';
    if (data.index() == 0) {
        std::string v = std::get<std::string>(data);
    }
    else if (data.index() == 1) {
        int v = std::get<int>(data);
    }
    if (auto value = std::get_if<std::string>(&data)) {
        std::string& v = *value;
    }
    else if (auto value = std::get_if<int>(&data)) {
        int& v = *value;
    }
    return 0;
}
