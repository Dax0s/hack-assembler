#ifndef PARSER_H
#define PARSER_H

#include <string>

struct ParsedCCommand {
    std::string dest;
    std::string comp;
    std::string jump;
};

class Parser {
public:
    static std::string ParseDest(const std::string& command);
    static std::string ParseComp(const std::string& command);
    static std::string ParseJump(const std::string& command);

    static ParsedCCommand ParseCCommand(const std::string& command);
    static int ParseACommand(const std::string& command);

    /**
     * Checks whether the command passed in is an A or C command
     * @param command command string
     * @return 0 if A command, 1 if C command
     */
    static int ParseCommandType(const std::string& command);
};

#endif //PARSER_H
