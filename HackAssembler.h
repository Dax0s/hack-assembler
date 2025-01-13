#ifndef HACKASSEMBLER_H
#define HACKASSEMBLER_H

#include <string>
#include <unordered_map>

class HackAssembler {
    std::string m_input;
    std::string m_output;

    static std::string GenerateOutputFileName(const std::string& input);
public:
    explicit HackAssembler(std::string input);

    static std::unordered_map<std::string, int> CreateSymbolTable();

    void Assemble() const;
};

#endif //HACKASSEMBLER_H
