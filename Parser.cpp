#include "Parser.h"

int FindChar(std::string s, char ch) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ch) return i;
    }

    return -1;
}

std::string Parser::ParseDest(const std::string& command) {
    int index = FindChar(command, '=');
    if (index == -1) return "";

    return command.substr(0, index);
}
