#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <cstdint>

class Util
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

    static double CalcAmount(std::string& strAmount, int floatDigits)
    {
        return std::stod(strAmount);
    }
};

#endif // UTIL_H
