#include <iostream>

#include "HackAssembler.h"

int main(const int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./HackAssembler <file>" << std::endl;
        return 1;
    }

    HackAssembler assembler(argv[1]);
    assembler.Assemble();

    return 0;
}
