#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <cstdint>

class Util
{
public:
    template<typename T>
    static T HexStringToValue(const std::string& hexStr)
    {
        if (hexStr.length() / 2 != sizeof(T))
            throw std::logic_error("output size does not match with the input size");
        
        T element = 0;
        for (int i = 0; i < sizeof(T); i++)
        {
            std::string byteString = hexStr.substr(i * 2, 2);
            auto slice = (uint8_t) strtol(byteString.c_str(), nullptr, 16);
            element |= (slice << i);
        }
            
        return element;
    }

    template<typename T>
    static std::vector<T> HexStringToVectorValue(const std::string& hexStr)
    {
        std::vector<T> vec;

        for (int i = 0; i < hexStr.length(); i += 2)
        {
            std::string byteString = hexStr.substr(i, 2);
            T element = 0;

            for (int sub = 0; sub < sizeof(T); sub++)
            {
                auto slice = (uint8_t) strtol(byteString.c_str(), nullptr, 16);
                element |= (slice << sub);
            }

            vec.emplace_back(element);
        }
        return vec;
    }

    static double CalcAmount(const std::string& strAmount, const int floatDigits)
    {
        return std::stod(strAmount);
    }
};

#endif // UTIL_H
