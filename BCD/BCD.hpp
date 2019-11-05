#ifndef BCD_HPP_INCLUDED
#define BCD_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>

class BCD
{
private:
    char const * digit[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

public:
    std::string DecToBCDUnsigned(uint32_t decimal);
    std::string BCDToDecUnsigned(std::string bcd);

    std::string DecToBCDSigned(uint32_t decimal);
    std::string BCDToDecSigned(std::string bcd);

    std::string DecToString(uint32_t decimal);
    uint32_t GetMaxPower10(uint32_t decimal);
};

#endif // BCD_HPP_INCLUDED
