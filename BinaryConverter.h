#ifndef BINARYCONVERTER_H
#define BINARYCONVERTER_H

#include <string>

class BinaryConverter {
public:
    static std::string DestToBin(const std::string& dest);
    static std::string JumpToBin(const std::string& dest);
};

#endif //BINARYCONVERTER_H
