#include <iostream>
#include <fstream>

#include "BinaryConverter.h"
#include "Parser.h"
#include "Utils.h"

int main(const int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./HackAssembler <file>" << std::endl;
        return 1;
    }

    std::string outputFileName = argv[1];
    outputFileName = outputFileName.substr(0, outputFileName.length() - 4);
    outputFileName += ".hack";

    if (std::ifstream inputFile(argv[1]); inputFile.is_open()) {
        if (std::ofstream outputFile(outputFileName); outputFile.is_open()) {
            std::string line;
            while (getline(inputFile, line)) {
                std::string clearLine = ClearWhitespace(line);
                if (clearLine.substr(0, 2) != "//" && !clearLine.empty()) {
                    outputFile << BinaryConverter::CommandToBin(line) << std::endl;
                }
            }
            outputFile << std::endl;
            outputFile.close();
        }
        inputFile.close();
    } else {
        std::cerr << "Failed to open file " << argv[1] << std::endl;
    }

    return 0;
}
