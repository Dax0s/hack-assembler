#include "BinaryConverter.h"

#include <bitset>

#include "Parser.h"
#include "Utils.h"

std::string BinaryConverter::DestToBin(const std::string &dest) {
    std::string destBin = "000";

    const int m = FindChar(dest, 'M');
    const int d = FindChar(dest, 'D');
    const int a = FindChar(dest, 'A');

    if (m != -1) {
        destBin[2] = '1';
    }
    if (d != -1) {
        destBin[1] = '1';
    }
    if (a != -1) {
        destBin[0] = '1';
    }

    return destBin;
}

std::string BinaryConverter::JumpToBin(const std::string& jump) {
    if (jump == "JGT") {
        return "001";
    }
    if (jump == "JEQ") {
        return "010";
    }
    if (jump == "JGE") {
        return "011";
    }
    if (jump == "JLT") {
        return "100";
    }
    if (jump == "JNE") {
        return "101";
    }
    if (jump == "JLE") {
        return "110";
    }
    if (jump == "JMP") {
        return "111";
    }

    return "000";
}

std::string BinaryConverter::CompToBin(const std::string& comp) {
    if (comp == "0") {
        return "0101010";
    }
    if (comp == "-1") {
        return "0111111";
    }
    if (comp == "-1") {
        return "0111010";
    }
    if (comp == "D") {
        return "0001100";
    }
    if (comp == "A") {
        return "0110000";
    }
    if (comp == "M") {
        return "1110000";
    }
    if (comp == "!D") {
        return "0001101";
    }
    if (comp == "!A") {
        return "0110001";
    }
    if (comp == "!M") {
        return "1110001";
    }
    if (comp == "-D") {
        return "0001111";
    }
    if (comp == "-A") {
        return "0110011";
    }
    if (comp == "-M") {
        return "1110011";
    }
    if (comp == "D+1" || comp == "1+D") {
        return "0011111";
    }
    if (comp == "A+1" || comp == "1+A") {
        return "0110111";
    }
    if (comp == "M+1" || comp == "1+M") {
        return "1110111";
    }
    if (comp == "D-1") {
        return "0001110";
    }
    if (comp == "A-1") {
        return "0110010";
    }
    if (comp == "M-1") {
        return "1110010";
    }
    if (comp == "D+A" || comp == "A+D") {
        return "0000010";
    }
    if (comp == "D+M" || comp == "M+D") {
        return "1000010";
    }
    if (comp == "D-A") {
        return "0010011";
    }
    if (comp == "D-M") {
        return "1010011";
    }
    if (comp == "A-D") {
        return "0000111";
    }
    if (comp == "M-D") {
        return "1000111";
    }
    if (comp == "D&A" || comp == "A&D") {
        return "0000000";
    }
    if (comp == "D&M" || comp == "M&D") {
        return "1000000";
    }
    if (comp == "D|A" || comp == "A|D") {
        return "0010101";
    }
    if (comp == "D|M" || comp == "M|D") {
        return "1010101";
    }

    return "0000000";
}

std::string BinaryConverter::CCommandToBin(const std::string& command) {
    const auto [dest, comp, jump] = Parser::ParseCCommand(command);

    std::string commandBin = "111";
    commandBin += CompToBin(comp);
    commandBin += DestToBin(dest);
    commandBin += JumpToBin(jump);

    return commandBin;
}

std::string BinaryConverter::ACommandToBin(const std::string& command) {
    return std::bitset<16>(Parser::ParseACommand(command)).to_string();
}
