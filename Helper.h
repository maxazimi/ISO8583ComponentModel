#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <vector>
#include <cstdint>

enum
{
    ISO1987_07 = 0,
    ISO1987_08,
    ISO1993_07,
    ISO1993_08,
    ISO2003_07,
    ISO2003_08,
    ISO2003_SH,
    ISO2003_SP
};

class Helper
{
public:
    static std::vector<uint8_t> HexToBytes(const std::string& hexStr)
    {
        std::vector<uint8_t> bytes;

        for (unsigned int i = 0; i < hexStr.length(); i += 2)
        {
            std::string byteString = hexStr.substr(i, 2);
            uint8_t byte = (uint8_t) strtol(byteString.c_str(), nullptr, 16);
            bytes.push_back(byte);
        }
        return bytes;
    }
};

#endif // HELPER_H
