#include <iostream>
#include <string>
#include <cmath>

const int PRIME = 101; // S? nguy�n t? d�ng cho ph�p to�n modulo

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
    int patternHash = 0; // Gi� tr? bam c?a m?u
    int textHash = 0; // Gi� tr? bam c?a do?n van b?n hi?n t?i

    // T�nh to�n gi� tr? bam cho m?u v� do?n van b?n d?u ti�n c� d? d�i m
    for (int i = 0; i < m; i++) {
        patternHash += pattern[i] * std::pow(PRIME, i);
        textHash += text[i] * std::pow(PRIME, i);
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash && areEqual(text, pattern, i)) {
            std::cout << "Pattern found at position: " << i << std::endl;
        }
        // T�nh to�n gi� tr? bam c?a do?n van b?n ti?p theo
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

