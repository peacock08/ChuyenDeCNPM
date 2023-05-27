#include <iostream>
#include <vector>

std::vector<int> build_bad_character_table(const std::string& pattern) {
    std::vector<int> bad_character_table(256, -1);
    int m = pattern.length();
    
    for (int i = 0; i < m - 1; i++) {
        bad_character_table[pattern[i]] = i;
    }

    return bad_character_table;
}

std::vector<int> build_good_suffix_table(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> good_suffix_table(m, 0);
    std::vector<int> suffixes(m + 1, 0);

    int i = m;
    int j = m + 1;
    suffixes[i] = j;

    while (i > 0) {
        while (j <= m && pattern[i - 1] != pattern[j - 1]) {
            if (good_suffix_table[j] == 0) {
                good_suffix_table[j] = j - i;
            }
            j = suffixes[j];
        }
        i--;
        j--;
        suffixes[i] = j;
    }

    j = suffixes[0];
    for (i = 0; i <= m; i++) {
        if (good_suffix_table[i] == 0) {
            good_suffix_table[i] = j;
        }
        if (i == j) {
            j = suffixes[j];
        }
    }

    return good_suffix_table;
}

std::vector<int> tuned_boyer_moore(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    int n = text.length();
    int m = pattern.length();

    std::vector<int> bad_character = build_bad_character_table(pattern);
    std::vector<int> good_suffix = build_good_suffix_table(pattern);

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            matches.push_back(shift);
            shift += good_suffix[0];
        } else {
            shift += std::max(good_suffix[j + 1], j - bad_character[text[shift + j]]);
        }
    }

    return matches;
}

int main() {
    std::string text = "ABCABCDABABCDABCD";
    std::string pattern = "ABCD";

    std::vector<int> matches = tuned_boyer_moore(text, pattern);

    std::cout << "Pattern found at positions: ";
    for (int i = 0; i < matches.size(); i++) {
        std::cout << matches[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

