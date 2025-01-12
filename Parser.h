#ifndef PARSER_H
#define PARSER_H

#include <string>

class Parser {
public:
    static std::string ParseDest(const std::string& command);
    static std::string ParseComp(const std::string& command);
    static std::string ParseJump(const std::string& command);
};

#endif //PARSER_H
