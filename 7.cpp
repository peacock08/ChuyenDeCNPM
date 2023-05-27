#include <iostream>
#include <vector>
#include <string>

std::vector<int> shiftOr(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    int n = text.length();
    int m = pattern.length();
    std::vector<int> bitmask(256, 0);

    // Thi?t l?p bitmask cho m?u
    for (int i = 0; i < m; i++) {
        bitmask[pattern[i]] |= (1 << i);
    }

    int state = 0;
    for (int i = 0; i < n; i++) {
        state = ((state << 1) | 1) & bitmask[text[i]];

        if ((state & (1 << (m - 1))) != 0) {
            matches.push_back(i - m + 1);
        }
    }

    return matches;
}

int main() {
    std::string text = "abababcababcabcabc";
    std::string pattern = "abc";

    std::vector<int> matches = shiftOr(text, pattern);

    std::cout << "Pattern found at positions: ";
    for (int i = 0; i < matches.size(); i++) {
        std::cout << matches[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

