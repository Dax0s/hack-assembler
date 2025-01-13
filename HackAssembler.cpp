#include "HackAssembler.h"
#include "BinaryConverter.h"
#include "Utils.h"

#include <fstream>
#include <iostream>

HackAssembler::HackAssembler(std::string input) {
    m_output = GenerateOutputFileName(input);
    m_input = std::move(input);
    m_symbolTable = CreateSymbolTable();
    // Default address at which variables start
    m_currentRamAddr = 16;
    this->FillSymbolTable();
}

std::string HackAssembler::GenerateOutputFileName(const std::string& input) {
    return input.substr(0, input.length() - 4) + ".hack";
}

void HackAssembler::Assemble() {
    if (std::ifstream inputFile(m_input); inputFile.is_open()) {
        if (std::ofstream outputFile(m_output); outputFile.is_open()) {
            std::string line;
            while (getline(inputFile, line)) {
                std::string clearLine = ClearWhitespace(line);
                if (clearLine.substr(0, 2) != "//" && !clearLine.empty() && clearLine[0] != '(') {
                    outputFile << BinaryConverter::CommandToBin(CheckAddress(clearLine)) << std::endl;
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

void HackAssembler::FillSymbolTable() {
    if (std::ifstream inputFile(m_input); inputFile.is_open()) {
        std::string line;
        int i = 0;
        while (getline(inputFile, line)) {
            std::string clearLine = ClearWhitespace(line);
            if (clearLine.substr(0, 2) != "//" && !clearLine.empty()) {
                if (clearLine[0] == '(' && clearLine[clearLine.length() - 1] == ')') {
                    std::string symbol = clearLine.substr(0, clearLine.length() - 1);
                    symbol = symbol.substr(1);

                    if (!m_symbolTable.contains(symbol)) {
                        m_symbolTable[symbol] = i;
                    }
                } else {
                    i++;
                }
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Failed to open file " << m_input << std::endl;
    }
}


std::string HackAssembler::CheckAddress(std::string address) {
    if (address[0] != '@') {
        return address;
    }

    try {
        // Checks if address is a number
        std::stoi(address.substr(1));
        return address;
    } catch (std::invalid_argument const& e) {
        const std::string symbol = address.substr(1);

        if (m_symbolTable.contains(symbol)) {
            return "@" + std::to_string(m_symbolTable[symbol]);
        }

        m_symbolTable[symbol] = m_currentRamAddr;
        return "@" + std::to_string(m_currentRamAddr++);
    }
}
