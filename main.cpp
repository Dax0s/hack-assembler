#include <iostream>

#include "Parser.h"

int main() {

    std::cout << Parser::ParseDest("D=D+1") << std::endl;
    std::cout << Parser::ParseDest("0;JMP") << std::endl;
    std::cout << Parser::ParseDest("DM=D+1") << std::endl;
    std::cout << Parser::ParseDest("AMD=D+1") << std::endl;

    return 0;
}
