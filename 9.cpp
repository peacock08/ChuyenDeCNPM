#include <iostream>
#include <vector>
#include <string>

std::vector<int> build_shift_table(const std::string& pattern) {
    std::vector<int> table(256, pattern.length());

    for (int i = 0; i < pattern.length() - 1; i++) {
        table[pattern[i]] = pattern.length() - 1 - i;
    }

    return table;
}

std::vector<int> horspool(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    int n = text.length();
    int m = pattern.length();
    std::vector<int> shift_table = build_shift_table(pattern);

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == m) {
            matches.push_back(i - m + 1);
        }
        i += shift_table[text[i]];
    }

    return matches;
}

int main() {
    std::string text = "This is a test string.";
    std::string pattern = "test";

    std::vector<int> matches = horspool(text, pattern);

    if (matches.empty()) {
        std::cout << "Pattern not found." << std::endl;
    } else {
        std::cout << "Pattern found at positions: ";
        for (int i = 0; i < matches.size(); i++) {
            std::cout << matches[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

