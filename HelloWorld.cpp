/* directive read and interpreted by the preprocessor (interpreted before compilation of
 * the program itself begins) */
#include <iostream>
// using declaration (introduce visibilty of components)
using namespace std;

// initates declaration of a function
int main() {
    // unqualified name
    cout << "Hello World." << endl;
    // qualifies it directly within the namespace (explicit qualification)
    std::cout << "C++ Program." << std::endl;
    return 0;
}
