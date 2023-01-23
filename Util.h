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
            throw std::logic_error("output size does not match with input size");
        
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

    static std::string ConvertToPaddedString(uint64_t val, int numOfDigits)
    {
        auto unpaddedStr = std::to_string(val);
        auto padding = numOfDigits - unpaddedStr.length();

        if (padding < 0)
            throw std::invalid_argument("invalid number of digits");

        return std::string(padding, '0') + unpaddedStr; // must be tested with zero value
    }

    static std::string ConvertToLxVarString(uint64_t val, int lxVar)
    {
        if (lxVar <= 0)
            throw std::invalid_argument("variable length must be greater than zero");

        auto unpaddedStr = std::to_string(val);
        return ConvertToPaddedString(unpaddedStr.length(), lxVar) + unpaddedStr;
    }

    static double CalcAmount(const std::string& strAmount, const int floatDigits)
    {
        return std::stod(strAmount);
    }
};

#endif // UTIL_H
