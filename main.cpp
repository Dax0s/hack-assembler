#include <iostream>

#include "BinaryConverter.h"
#include "Parser.h"
#include "Utils.h"

int main() {
    std::cout << BinaryConverter::CommandToBin("   @   2   522\n") << std::endl;
    std::cout << BinaryConverter::CommandToBin("AMD=D+1;JMP\n") << std::endl;

    return 0;
}
