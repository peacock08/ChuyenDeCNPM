#include <iostream>
#include <vector>
#include <string>

std::vector<int> build_table(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> table(m + 1, m);

    for (int i = 0; i < m; i++) {
        table[m - i - 1] = m - i;
        for (int j = m - i; j < m; j++) {
            if (pattern[m - i - 1] == pattern[j]) {
                table[m - i - 1] = j - (m - i - 1);
                break;
            }
        }
    }

    return table;
}

std::vector<int> reverse_colussi(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    int n = text.length();
    int m = pattern.length();
    std::vector<int> table = build_table(pattern);

    int i = m - 1;
    int j = i;
    int k = i;

    while (j >= 0 && i < n) {
        if (text[i] == pattern[j]) {
            i--;
            j--;
        } else {
            i += table[j];
            j = m - 1;
        }
    }

    if (j < 0) {
        matches.push_back(i + 1);
        k = m - 1;
    }

    while (i < n) {
        if (text[i] == pattern[k]) {
            i++;
            k--;
        } else {
            i += table[m - k - 1];
            k = m - 1;
        }

        if (k < 0) {
            matches.push_back(i - m);
            k = m - 1;
        }
    }

    return matches;
}

int main() {
    std::string text = "ABCABCDABABCDABCD";
    std::string pattern = "ABCD";

    std::vector<int> matches = reverse_colussi(text, pattern);

    std::cout << "Pattern found at positions: ";
    for (int i = 0; i < matches.size(); i++) {
        std::cout << matches[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

