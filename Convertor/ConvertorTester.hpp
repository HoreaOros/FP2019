#ifndef CONVERTORTESTER_HPP_INCLUDED
#define CONVERTORTESTER_HPP_INCLUDED

// dependencies
#include <iostream>
#include <string>
#include <vector>

// tested class
#include "Convertor.hpp"

class ConvertorTester
{
private:
    std::vector<std::string> succesfulTests;
    std::vector<std::string> failedTests;

    // digit <-> char
    void DigitToChar();
    void CharToDigit();
    void StringToDec();
    void DecToString();

    // utilitaries
    void MaximumChar();
    void VerifyBase();
    void ToUpperCase();
    void ReverseString();
    void ReturnProcedures();

    // base conversions
        // integer parts only
    void DecToAnyInteger();
    void AnyToDecInteger();
        // fractional part only
    void DecToAnyFractional();
    void AnyToDecFractional();
        // combining integer and fractional parts
    void DecToAnyFloat();
    void AnyToDecFloat();

    // specialized functions
    void DumpHex();
    void DumpBin();
    void DumpChar();

public:
    void TestClass();
    void PrintResults();
};

#endif // CONVERTORTESTER_HPP_INCLUDED
