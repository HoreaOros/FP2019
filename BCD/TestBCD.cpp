#include "TestBCD.hpp"

void TestBCD::DecToBCDUnsigned()
{
    std::string currentTest{__func__};
    std::string result{};
    BCD bcd;

    try
    {

    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfullTests.push_back(currentTest);
}

void TestBCD::BCDToDecUnsigned()
{
    std::string currentTest{__func__};
    std::string result{};
    BCD bcd;

    try
    {

    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfullTests.push_back(currentTest);
}

void TestBCD::DecToBCDSigned()
{
    std::string currentTest{__func__};
    std::string result{};
    BCD bcd;

    try
    {

    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfullTests.push_back(currentTest);
}

void TestBCD::BCDToDecSigned()
{
    std::string currentTest{__func__};
    std::string result{};
    BCD bcd;

    try
    {

    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfullTests.push_back(currentTest);
}

void TestBCD::DecToString()
{
    std::string currentTest{__func__};
    std::string result{};
    BCD bcd;

    try
    {

    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfullTests.push_back(currentTest);
}

void TestBCD::GetMaxPower10()
{
    std::string currentTest{__func__};
    uint32_t result{};
    BCD bcd;

    try
    {

    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfullTests.push_back(currentTest);
}

void TestBCD::TestClass()
{
    void DecToBCDUnsigned();
    void BCDToDecUnsigned();

    void DecToBCDSigned();
    void BCDToDecSigned();

    void DecToString();
    void GetMaxPower10();
}

void TestBCD::PrintResults()
{
    std::cout << "Succesfull tests: \n";
    for(auto& iter : succesfullTests)
    {
        std::cout << iter << "\n";
    }

    std::cout << "Failed tests: \n";
    for(auto& iter : failedTests)
    {
        std::cout << iter << "\n";
    }
    std::cout << "\n";
}
