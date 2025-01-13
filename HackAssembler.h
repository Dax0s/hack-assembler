#ifndef HACKASSEMBLER_H
#define HACKASSEMBLER_H

#include <string>

class HackAssembler {
    std::string m_input;
    std::string m_output;

    static std::string GenerateOutputFileName(const std::string& input);
public:
    explicit HackAssembler(std::string input);

    void Assemble() const;
};

#endif //HACKASSEMBLER_H
