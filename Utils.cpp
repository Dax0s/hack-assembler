#include "Utils.h"

int FindChar(const std::string &s, const char ch) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ch) return i;
    }

    return -1;
}
