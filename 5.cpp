#include <iostream>
#include <vector>
#include <string>

std::vector<int> build_table(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> table(m + 1);

    int i = m;
    int j = m + 1;
    std::vector<int> border(j, i);

    while (i > 0) {
        while (j <= m && pattern[i - 1] != pattern[j - 1]) {
            if (border[j] > m - i)
                border[j] = m - i;
            j = border[j];
        }
        i--;
        j--;
        border[j] = i;
        if (border[j] > m - i)
            border[j] = m - i;
    }

    for (int i = 0; i <= m; i++) {
        if (border[i] > m - i)
            border[i] = m - i;
    }

    return border;
}

std::vector<int> colussi(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    int n = text.length();
    int m = pattern.length();
    std::vector<int> table = build_table(pattern);

    int i = m - 1;
    int j = m - 1;

    while (i < n) {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                matches.push_back(i);
                i += m;
                j = m - 1;
            } else {
                i--;
                j--;
            }
        } else {
            i += table[j + 1];
            j = m - 1;
        }
    }

    return matches;
}

int main() {
    std::string text = "ABCABCDABABCDABCD";
    std::string pattern = "ABCD";

    std::vector<int> matches = colussi(text, pattern);

    std::cout << "Pattern found at positions: ";
    for (int i = 0; i < matches.size(); i++) {
        std::cout << matches[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

