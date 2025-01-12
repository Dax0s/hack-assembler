#ifndef BINARYCONVERTER_H
#define BINARYCONVERTER_H

#include <string>

class BinaryConverter {
public:
    static std::string DestToBin(const std::string& dest);
    static std::string JumpToBin(const std::string& jump);
    static std::string CompToBin(const std::string& comp);

    static std::string CommandToBin(const std::string& command);
};

#endif //BINARYCONVERTER_H
