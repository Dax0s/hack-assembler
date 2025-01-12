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

std::string Parser::ParseComp(const std::string& command) {
    std::string comp;
    const int index0 = FindChar(command, '=');
    if (index0 != -1) {
        comp = command.substr(index0 + 1, command.length() - 1);
    }

    if (index0 == -1) {
        const int index1 = FindChar(command, ';');
        if (index1 != -1) {
            comp = command.substr(0, index1);
        }
    } else {
        const int index1 = FindChar(comp, ';');
        if (index1 != -1) {
            comp = comp.substr(0, index1);
        }
    }

    return comp;
}

std::string Parser::ParseJump(const std::string& command) {
    if (const int index = FindChar(command, ';'); index != -1) {
        return command.substr(index + 1, command.length() - 1);
    }

    return "";
}
