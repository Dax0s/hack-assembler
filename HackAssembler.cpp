#include "HackAssembler.h"
#include "BinaryConverter.h"
#include "Utils.h"

#include <fstream>
#include <iostream>

HackAssembler::HackAssembler(std::string input) {
    m_output = GenerateOutputFileName(input);
    m_input = std::move(input);
}

std::string HackAssembler::GenerateOutputFileName(const std::string& input) {
    return input.substr(0, input.length() - 4) + ".hack";
}

void HackAssembler::Assemble() const {
    if (std::ifstream inputFile(m_input); inputFile.is_open()) {
        if (std::ofstream outputFile(m_output); outputFile.is_open()) {
            std::string line;
            while (getline(inputFile, line)) {
                std::string clearLine = ClearWhitespace(line);
                if (clearLine.substr(0, 2) != "//" && !clearLine.empty()) {
                    outputFile << BinaryConverter::CommandToBin(line) << std::endl;
                }
            }
            outputFile.close();
        } else {
            std::cerr << "Failed to open file " << m_output << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Failed to open file " << m_input << std::endl;
    }
}


std::unordered_map<std::string, int> HackAssembler::CreateSymbolTable() {
    std::unordered_map<std::string, int> symbolTable;

    for (int i = 0; i < 16; i++) {
        symbolTable[std::format("R{}", i)] = i;
    }

    symbolTable["SCREEN"] = 16384;
    symbolTable["KBD"] = 24576;

    symbolTable["SP"] = 0;
    symbolTable["LCL"] = 1;
    symbolTable["ARG"] = 2;
    symbolTable["THIS"] = 3;
    symbolTable["THAT"] = 4;

    return symbolTable;
}
