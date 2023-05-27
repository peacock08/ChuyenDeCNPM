#include <iostream>
#include <string>
#include <cmath>

const int PRIME = 101; // S? nguyên t? dùng cho phép toán modulo

bool areEqual(const std::string& text, const std::string& pattern, int start) {
    int m = pattern.length();
    for (int i = 0; i < m; i++) {
        if (text[start + i] != pattern[i]) {
            return false;
        }
    }
    return true;
}

void karpRabin(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int patternHash = 0; // Giá tr? bam c?a m?u
    int textHash = 0; // Giá tr? bam c?a do?n van b?n hi?n t?i

    // Tính toán giá tr? bam cho m?u và do?n van b?n d?u tiên có d? dài m
    for (int i = 0; i < m; i++) {
        patternHash += pattern[i] * std::pow(PRIME, i);
        textHash += text[i] * std::pow(PRIME, i);
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash && areEqual(text, pattern, i)) {
            std::cout << "Pattern found at position: " << i << std::endl;
        }
        // Tính toán giá tr? bam c?a do?n van b?n ti?p theo
        if (i < n - m) {
            textHash = (textHash - text[i]) / PRIME + text[i + m] * std::pow(PRIME, m - 1);
        }
    }
}

int main() {
    std::string text = "ABCABCDABABCDABCD";
    std::string pattern = "ABCD";

    karpRabin(text, pattern);

    return 0;
}

