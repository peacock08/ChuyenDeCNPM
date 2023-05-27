#include <iostream>
#include <vector>
#include <string>

std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

std::vector<int> apostolicoCrochemore(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    int n = text.length();
    int m = pattern.length();
    std::vector<int> lps = computeLPS(pattern);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;

            if (j == m) {
                matches.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return matches;
}

int main() {
    std::string text = "ABCABCDABABCDABCD";
    std::string pattern = "ABCD";

    std::vector<int> matches = apostolicoCrochemore(text, pattern);

    std::cout << "Pattern found at positions: ";
    for (int i = 0; i < matches.size(); i++) {
        std::cout << matches[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

