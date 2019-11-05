#ifndef TESTBCD_HPP
#define TESTBCD_HPP

#include <vector>
#include <string>

#include "BCD.hpp"

class TestBCD
{
private:
    std::vector<std::string> succesfullTests{};
    std::vector<std::string> failedTests{};

    void DecToBCDUnsigned();
    void BCDToDecUnsigned();

    void DecToBCDSigned();
    void BCDToDecSigned();

    void DecToString();
    void GetMaxPower10();

public:
    void TestClass();
    void PrintResults();
};

#endif // TESTBCD_HPP
