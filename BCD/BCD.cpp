#include "BCD.hpp"

std::string BCD::DecToBCDUnsigned(uint32_t decimal)
{
    std::string result{};
    result += DecToString(decimal);

    uint32_t maxDec = GetMaxPower10(decimal);

    while(maxDec)
    {
        result += digit[decimal / maxDec];
        result += " ";

        decimal %= maxDec;
        maxDec /= 10;
    }
    result += "\n";

    return result;
}

std::string BCD::BCDToDecUnsigned(std::string bcd)
{
    std::string result{};



    return result;
}

std::string BCD::DecToBCDSigned(uint32_t decimal)
{
    std::string result{};

    return result;
}

std::string BCD::BCDToDecSigned(std::string bcd)
{
    std::string result{};

    return result;
}

std::string BCD::DecToString(uint32_t decimal)
{
    std::string result{};
    uint32_t maxDec = GetMaxPower10(decimal);

    bool notFirst{false};
    while(maxDec)
    {
        result += "   ";
        if(notFirst)
            result += " ";

        notFirst = true;

        result += ('0' + decimal / maxDec);

        decimal %= maxDec;
        maxDec /= 10;
    }
    result += "\n";

    return result;
}

uint32_t BCD::GetMaxPower10(uint32_t decimal)
{
    // get a base 10 position for the leftmost digit
    uint32_t maxDec{1};
    // thiw will overstep a digit
    while(decimal / maxDec)
        maxDec *= 10;
    // so bring it back
    maxDec /= 10;
}
