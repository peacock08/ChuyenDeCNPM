#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> findRepeatedSubstrings(const string& input_string) {
    set<string> repeated_substrings;

    for (int length = 2; length <= input_string.length(); length++) {
        for (int i = 0; i <= input_string.length() - length; i++) {
            string substring = input_string.substr(i, length);
            if (input_string.find(substring, i + 1) != string::npos) {
                repeated_substrings.insert(substring);
            }
        }
    }

    return repeated_substrings;
}

int main() {
    string input_str = "ababcababcab";
    set<string> result = findRepeatedSubstrings(input_str);

    cout << "Repeated substrings:" << endl;
    set<string>::iterator it;
    for (it = result.begin(); it != result.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}

