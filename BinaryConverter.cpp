#include "BinaryConverter.h"

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

std::string BinaryConverter::JumpToBin(std::string dest) {
    dest = ClearWhitespace(dest);

    if (dest == "JGT") {
        return "001";
    }
    if (dest == "JEQ") {
        return "010";
    }
    if (dest == "JGE") {
        return "011";
    }
    if (dest == "JLT") {
        return "100";
    }
    if (dest == "JNE") {
        return "101";
    }
    if (dest == "JLE") {
        return "110";
    }
    if (dest == "JMP") {
        return "111";
    }

    return "000";
}
