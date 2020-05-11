#include <iostream>
#include <string>
#include <regex>

using namespace std;

void process_integers(string line) {
    cout << line;
    //regex r ("(\\+|-)?[[:d:]]+");
    regex r ("(\\+|-)?(\\d+)");
    if (regex_match(line, r)) {
        cout << " PASSED\n";
    }
    else {
        cout << " FAILED\n";
    }

}

void test() {
    if (regex_match("subject", regex("(sub)(.*)"))) {
        cout << "string literal matched\n";
    }
    string s = "subject";
    regex e ("(sub)(.*)");
    if (regex_match(s, e)) {
        cout << "string object matched\n";
    }
    if (regex_match(s.begin(), s.end(), e)) {
        cout << "range matched\n";
    }
    const char* cstr = "subject";
    cmatch cm;  // same as match_results<const char*> cm;
    regex_match(cstr, cm, e);
    cout << "string literator with " << cm.size() << " matches\n";
    smatch sm;  // same as match_results<string::const_iterator> sm;
    regex_match(s, sm, e);
    cout << "string object with " << sm.size() << " matches\n";
    regex_match(s.cbegin(), s.cend(), sm, e);
    cout << "range with " << sm.size() << " matches\n";
    // using explicit flags
    regex_match(cstr, cm, e, regex_constants::match_default);
    cout << "the matches were: ";
    for (size_t i = 0; i < cm.size(); ++i) {
        cout << "[" << cm[i] << "] ";
    }
    cout << endl;
}

int main() {
    int ns = 5;
    string s [ns] {"0012", "+0012", "-0012", "-12", "-0012"};
    for (int i = 0; i < ns; ++i) {
        process_integers(s[i]);
    }
    test();
}
