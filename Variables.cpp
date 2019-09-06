#include <iostream>
#include <string>
using namespace std;


int main() {
    // c++ is a strongly-typed language and requires every variable to be declared
    // with its type before its use
    int a, b;
    int result;
    
    // process
    a = 5;
    b = 2;
    a = a + 1;
    result = a - b;

    // print the result
    cout << result << endl;

    /* initialization of variables */
    // c-like initialization
    int x = 0;
    // constructor initialization
    int y (0);
    // uniform initialization
    int z {0};

    // let compiler figure out type
    int foo = 0;
    auto bar = foo;     // the same as: int bar = foo

    // variables that are not initialization can make use of decltype
    decltype(foo) bar2; // the same as: int bar;

    // all with all fundamental types, all initialization formats are valid with strings
    // strings are a compound type
    string mystring;
    mystring = "This is my string.";
    cout << mystring << endl;

    // terminate the program
    return 0;
}
