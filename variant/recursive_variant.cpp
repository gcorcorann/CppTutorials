#include <map>
#include <vector>
#include <variant>
#include <iostream>

struct Value {
    std::variant<int, std::string, std::vector<Value>, std::map<std::string, Value>> m_data;
};

struct Foo {
    std::variant<int, float, std::vector<Foo>> m_data;
};

int main() {
    Foo a = {std::vector<Foo>{Foo{}, Foo{}}};
    std::vector<Foo> b;
    b.push_back(Foo{3});
    b.push_back(Foo{2});

    Value value = {std::vector<Value>{Value{3}, Value{3}}};
    Value temp = std::get<std::vector<Value>>(value.m_data)[0];
    int tempInt = std::get<int>(temp.m_data);
    return 0;
}
