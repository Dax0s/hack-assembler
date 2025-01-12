#include "Parser.h"

#include "Utils.h"

std::string Parser::ParseDest(const std::string& command) {
    const int index = FindChar(command, '=');
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
        if (const int index1 = FindChar(command, ';'); index1 != -1) {
            comp = command.substr(0, index1);
        }
    } else {
        if (const int index1 = FindChar(comp, ';'); index1 != -1) {
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

ParsedCCommand Parser::ParseCCommand(const std::string& command) {
    ParsedCCommand result;

    result.dest = ParseDest(command);
    result.comp = ParseComp(command);
    result.jump = ParseJump(command);

    return result;
}

int Parser::ParseACommand(const std::string& command) {
    const std::string commandClear = ClearWhitespace(command);
    return std::stoi(commandClear.substr(1, commandClear.length() - 1));
}
