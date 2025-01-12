#include "Utils.h"

int FindChar(const std::string &s, const char ch) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ch) return i;
    }

    return -1;
}

std::string ClearWhitespace(const std::string &s) {
    std::string result;
    result.reserve(s.length());

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            result += s[i];
        }
    }

    int a = s.length();
    int b = result.length();

    return result;
}
