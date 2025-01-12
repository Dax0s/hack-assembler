#include "Parser.h"

#include "Utils.h"

std::string Parser::ParseDest(const std::string& command) {
    int index = FindChar(command, '=');
    if (index == -1) return "";

    return ClearWhitespace(command.substr(0, index));
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

    return ClearWhitespace(comp);
}

std::string Parser::ParseJump(const std::string& command) {
    if (const int index = FindChar(command, ';'); index != -1) {
        return ClearWhitespace(command.substr(index + 1, command.length() - 1));
    }

    return "";
}

ParsedCommand Parser::ParseCommand(const std::string& command) {
    ParsedCommand result;

    result.dest = ParseDest(command);
    result.comp = ParseComp(command);
    result.jump = ParseJump(command);

    return result;
}
