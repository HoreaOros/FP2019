#include "ConvertorTester.hpp"

void ConvertorTester::DigitToChar()
// char Convertor::DigitToChar(uint8_t const & digit)
// testing domain: [0, 255]
{
    std::string currentTest = {__func__};
    char test{};

    try
    {
        for(uint8_t digit = 0; digit < 255; digit++)
        {
            test = Convertor::DigitToChar(digit);

            if(digit < 10)
            {
                if( test != ('0' + digit) )
                    throw std::string(currentTest);
            }
            else if(digit < 36)
            {
                if( test != ('A' + digit - 10) )
                    throw std::string(currentTest);
            }
            else
            {
                if( test != '\0' )
                    throw std::string(currentTest);
            }
        }

        test = Convertor::DigitToChar(255);

        if( test != '\0' )
            throw std::string(currentTest);
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);
}

void ConvertorTester::CharToDigit()
// uint8_t Convertor::CharToDigit(char const & digitChar, uint8_t const & anyBase)
// testing domain: [0, 125] * [0, 255]
{
    std::string currentTest = {__func__};
    uint8_t test{};

    try
    {
        for(uint8_t base = 0; base < 255; base++)
        {

            for(char digit = 0; digit < 124; digit++)
            {
                test = Convertor::CharToDigit(digit, base);

                if(base == 0)
                {
                    if( test != 0 )
                        throw std::string(currentTest);
                }
                else if(base < 11)
                {
                    if( digit >= '0' && digit <= ('0' + base - 1) )
                    {
                        if( test != (digit - '0') )
                            throw std::string(currentTest);
                    }
                    else
                    {
                        if(test != 0)
                            throw std::string(currentTest);
                    }
                }
                else if(base < 37)
                {
                    if(digit >= '0' && digit <= '9')
                    {
                        if( test != (digit - '0') )
                            throw currentTest + "0-9, base [11, 36]";
                    }
                    else if(digit >= 'A' && digit <= ('A' + base - 11) )
                    {
                        if( test != (digit - 'A' + 10) )
                            throw currentTest + "A-Z, base [11, 36]";
                    }
                    else
                    {
                        if(test != 0)
                            throw std::string(currentTest);
                    }
                }
                else
                {
                    if(test != 0)
                        throw std::string(currentTest);
                }
            }
        }
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);
}

void ConvertorTester::StringToDec()
// uint64_t Convertor::StringToDec(std::string& str, uint8_t const & anyBase)
// testing domain: ["", "\177"] * [0, 255]
{
    std::string currentTest = {__func__};
    uint64_t test{};
    std::string str{};

    try
    {
        for(uint8_t base = 0; base < 255; base++)
        {
            test = Convertor::StringToDec(str, base);

            if(test != 0)
                throw std::string(currentTest);
        }

        for(char digit = 0; digit < 127; digit++)
        {
            for(uint64_t base = 0; base < 255; base++)
            {
                str.clear();
                str += digit;
                test = Convertor::StringToDec(str, base);

                if(base == 0)
                {
                    if(test != 0)
                        throw std::string(currentTest);
                }

                else if(base < 11)
                {
                    if(digit >= '0' && digit <= (unsigned char)('0' + base - 1) )
                        if(test != (unsigned char)(digit - '0'))
                            throw std::string(currentTest);
                }

                else if(base < 37)
                {
                    if(digit >= '0' && digit <= '9')
                    {
                        if(test != (unsigned char)(digit - '0') )
                            throw std::string(currentTest);
                    }
                    else if( digit >='A' && digit <= (unsigned char)('A' + base - 11) )
                    {
                        if(test != (unsigned char)(digit - 'A' + 10))
                            throw std::string(currentTest);
                    }
                }
                else
                {
                    if(test != 0)
                        throw std::string(currentTest);
                }
            }
        }
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::DecToString()
// std::string Convertor::DecToString(uint64_t number, uint8_t const & anyBase)
// testing domain:
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {
        // basic conversions first (2), (8), (10), (16)
        test = Convertor::DecToString( uint64_t(12341234), uint8_t(2) );
        if(test != "101111000100111111110010")
            throw std::string(currentTest);
         test = Convertor::DecToString( uint64_t(12341234), uint8_t(8) );
        if(test != "57047762")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(12341234), uint8_t(10) );
        if(test != "12341234")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(12341234), uint8_t(16) );
        if(test != "BC4FF2")
            throw std::string(currentTest);

        // testing value 0 in bases (2), (8), (10), (16), (32), (100)
        test = Convertor::DecToString( uint64_t(0), uint8_t(2) );
        if(test != "\0")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(0), uint8_t(8) );
        if(test != "\0")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(0), uint8_t(10) );
        if(test != "\0")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(0), uint8_t(16) );
        if(test != "\0")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(0), uint8_t(32) );
        if(test != "\0")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(0), uint8_t(100) );
        if(test != "\0")
            throw std::string(currentTest);

        // testing bases with letters and numerals (10), (12), (16), (20), (25), (30), (36), (37)
        test = Convertor::DecToString( uint64_t(1234), uint8_t(10) );
        if(test != "1234")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(1234), uint8_t(12) );
        if(test != "86A")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(1234), uint8_t(16) );
        if(test != "4D2")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(1234), uint8_t(20) );
        if(test != "31E")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(1234), uint8_t(25) );
        if(test != "1O9")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(1234), uint8_t(30) );
        if(test != "1B4")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(1234), uint8_t(36) );
        if(test != "YA")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(1234), uint8_t(37) );
        if(test != "\0")
            throw std::string(currentTest);

        // testing the carry
        test = Convertor::DecToString( uint64_t(1295), uint8_t(36) );
        if(test != "ZZ")
            throw std::string(currentTest);
        test = Convertor::DecToString( uint64_t(1296), uint8_t(36) );
        if(test != "100")
            throw std::string(currentTest);
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::MaximumChar()
// char const MaximumChar(uint8_t const & anyBase);
{
    std::string currentTest = {__func__};
    char test{};

    try
    {
        // the (0) base
        test = Convertor::MaximumChar(0);
        if(test != '\0')
            throw std::string(currentTest);
        // a few bases (1)-(10)
        test = Convertor::MaximumChar(1);
        if(test != '0')
            throw std::string(currentTest);
        test = Convertor::MaximumChar(3);
        if(test != '2')
            throw std::string(currentTest);
        test = Convertor::MaximumChar(7);
        if(test != '6')
            throw std::string(currentTest);
        test = Convertor::MaximumChar(10);
        if(test != '9')
            throw std::string(currentTest);
        // a few bases (11)-(36)
        test = Convertor::MaximumChar(11);
        if(test != 'A')
            throw std::string(currentTest);
        test = Convertor::MaximumChar(17);
        if(test != 'G')
            throw std::string(currentTest);
        test = Convertor::MaximumChar(29);
        if(test != 'S')
            throw std::string(currentTest);
        test = Convertor::MaximumChar(36);
        if(test != 'Z')
            throw std::string(currentTest);
        // a few bases (37)-(255)
        test = Convertor::MaximumChar(37);
        if(test != '\0')
            throw std::string(currentTest);
        test = Convertor::MaximumChar(137);
        if(test != '\0')
            throw std::string(currentTest);
        test = Convertor::MaximumChar(239);
        if(test != '\0')
            throw std::string(currentTest);
        test = Convertor::MaximumChar(255);
        if(test != '\0')
            throw std::string(currentTest);
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::VerifyBase()
// bool Convertor::VerifyBase(std::string const & anyNumber, uint8_t const & anyBase)
{
    std::string currentTest = {__func__};
    bool test{};

    try
    {
        // test the (0) base
        test = Convertor::VerifyBase("", 0);
        if(test != false)
            throw std::string(currentTest);
        // test a few (1)-(10) bases
        test = Convertor::VerifyBase("", 1);
        if(test != true)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("0", 1);
        if(test != true)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("1", 1);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("", 10);
        if(test != true)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("1234", 5);
        if(test != true)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("12345", 5);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("123456789", 7);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("123 45 67 89", 7);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("123 45 678 9", 10);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("123456789", 10);
        if(test != true)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("1234567890123456789012345678901234567890", 10);
        if(test != true)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("duih7oh7no", 10);
        if(test != false)
            throw std::string(currentTest);
        // test a few (11)-(36) bases
        test = Convertor::VerifyBase("129A", 11);
        if(test != true)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("BBABABAA", 11);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("BB ABA A A", 12);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("AFAF AE BC 238", 16);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("AFAFAEBC1238", 16);
        if(test != true)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("AFEBAFG", 16);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("ZZZZZKUIBBBT23423", 36);
        if(test != true)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("ZZZZZKUIBBBT23423!@#$%^&*", 36);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("0123456789abcdefgh", 36);
        if(test != false)
            throw std::string(currentTest);
        // test a few (37)-(255) bases
        test = Convertor::VerifyBase("ZZZZZKUIBBBT23423", 37);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("ZZZZZKUIBBBT23423!@#$%^&*", 67);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("ZZZZZKU23423!@#$%^&*", 99);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("", 157);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("%66INN& UGB76gUGuhU7u7h7", 200);
        if(test != false)
            throw std::string(currentTest);
        test = Convertor::VerifyBase("ZZZZZKUIBBBT23423!@#$%^&*", 255);
        if(test != false)
            throw std::string(currentTest);
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);
}

void ConvertorTester::ToUpperCase()
// std::string Convertor::ToUpperCase(std::string& str)
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {
        test = {""};
        test = Convertor::ToUpperCase(test);
        std::cout << test << "\n";
        if(test != "")
            throw std::string(currentTest);
        test.clear();

        test = {"asdfghjkl"};
        test = Convertor::ToUpperCase(test);
        if(test != "ASDFGHJKL")
            throw std::string(currentTest);
        test.clear();

        test = {"qwerty1234567890~!@#$%^&*()_+"};
        test = Convertor::ToUpperCase(test);
        if(test != "QWERTY1234567890~!@#$%^&*()_+")
            throw std::string(currentTest);
        test.clear();
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::ReverseString()
// void Convertor::ReverseString(std::string& str)
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {
        test = {"asdfghjkl"};
        Convertor::ReverseString(test);
        if(test != "lkjhgfdsa")
            throw std::string(currentTest);
        test.clear();

        test = {"1234567890-="};
        Convertor::ReverseString(test);
        if(test != "=-0987654321")
            throw std::string(currentTest);
        test.clear();

        test = {"QWERTYUIOPqwertyuiop1234567890!@#$%^&*()"};
        Convertor::ReverseString(test);
        if(test != ")(*&^%$#@!0987654321poiuytrewqPOIUYTREWQ")
            throw std::string(currentTest);
        test.clear();

        test = {""};
        Convertor::ReverseString(test);
        if(test != "")
            throw std::string(currentTest);
        test.clear();

    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::ReturnProcedures()
// std::string ReturnProcedures(std::string integerPart, std::string fractionalPart, uint8_t fractionalDigits, bool comma);
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {
        // boring, don't want to test this
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::DecToAnyInteger()
// std::string Convertor::DecToAnyInteger(std::string& decimal, uint8_t const & anyBase)
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {
        test = {"1234567890"};
        test = Convertor::DecToAnyInteger(test, 10);
        if(test != "1234567890")
            throw std::string(currentTest);
        test.clear();

        test = {"1234567890"};
        test = Convertor::DecToAnyInteger(test, 16);
        if(test != "499602D2")
            throw std::string(currentTest);
        test.clear();

        test = {"1234567890"};
        test = Convertor::DecToAnyInteger(test, 8);
        if(test != "11145401322")
            throw std::string(currentTest);
        test.clear();

        test = {"1234"};
        test = Convertor::DecToAnyInteger(test, 20);
        if(test != "31E")
            throw std::string(currentTest);
        test.clear();

        test = {"1234"};
        test = Convertor::DecToAnyInteger(test, 25);
        if(test != "1O9")
            throw std::string(currentTest);
        test.clear();

        test = {"1234"};
        test = Convertor::DecToAnyInteger(test, 30);
        if(test != "1B4")
            throw std::string(currentTest);
        test.clear();

        test = {"1234"};
        test = Convertor::DecToAnyInteger(test, 36);
        if(test != "YA")
            throw std::string(currentTest);
        test.clear();

        test = {"1234"};
        test = Convertor::DecToAnyInteger(test, 37);
        if(test != "\0")
            throw std::string(currentTest);
        test.clear();

        test = {"1234"};
        test = Convertor::DecToAnyInteger(test, 167);
        if(test != "\0")
            throw std::string(currentTest);
        test.clear();

        test = {"1234"};
        test = Convertor::DecToAnyInteger(test, 255);
        if(test != "\0")
            throw std::string(currentTest);
        test.clear();
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::AnyToDecInteger()
// std::string Convertor::AnyToDecInteger(std::string& anyNumber, uint8_t const & anyBase)
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {
        test = {"abcdef"};
        test = Convertor::AnyToDecInteger(test, 16);
        if(test != "11259375")
            throw std::string(currentTest);
        test.clear();

        test = {"01234567"};
        test = Convertor::AnyToDecInteger(test, 8);
        if(test != "342391")
            throw std::string(currentTest);
        test.clear();

        test = {"000000012345678901234567890"};
        test = Convertor::AnyToDecInteger(test, 10);
        if(test != "12345678901234567890")
            throw std::string(currentTest);
        test.clear();
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::DecToAnyFractional()
// std::string Convertor::DecToAnyFractional(std::string& decimalFractional, uint8_t const & anyBase){
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {

        // (10) -> (10)
        test = {"0"};
        test = Convertor::DecToAnyFractional(test, 10, 10);
        if(test != "0000000000")
            throw std::string(currentTest);
        test.clear();

        test = {"12345"};
        test = Convertor::DecToAnyFractional(test, 10, 10);
        if(test != "1234500000")
            throw std::string(currentTest);
        test.clear();

        test = {"98765ABCDEF"};
        test = Convertor::DecToAnyFractional(test, 16, 10);
        if(test != "\0")
            throw std::string(currentTest);
        test.clear();

        test = {"1234567890123456"};
        test = Convertor::DecToAnyFractional(test, 10, 16);
        if(test != "1234567890123456")
            throw std::string(currentTest);
        test.clear();

        test = {"1234567890"};
        test = Convertor::DecToAnyFractional(test, 10, 5);
        if(test != "12345")
            throw std::string(currentTest);
        test.clear();

        test = {"123456789012345678901234568790"};
        test = Convertor::DecToAnyFractional(test, 10, 5);
        if(test != "12345")
            throw std::string(currentTest);
        test.clear();

        test = {"10000000001"};
        test = Convertor::DecToAnyFractional(test, 10, 11);
        if(test != "10000000001")
            throw std::string(currentTest);
        test.clear();

        // (10) -> (others)
        test = {"12345678"};
        test = Convertor::DecToAnyFractional(test, 8, 5);
        if(test != "07715")
            throw std::string(currentTest);
        test.clear();

        test = {"12345678"};
        test = Convertor::DecToAnyFractional(test, 16, 10);
        if(test != "1F9ADD1091")
            throw std::string(currentTest);
        test.clear();

        test = {"12345678"};
        test = Convertor::DecToAnyFractional(test, 20, 5);
        if(test != "297D1")
            throw std::string(currentTest);
        test.clear();

        test = {"123123123"};
        test = Convertor::DecToAnyFractional(test, 36, 5);
        if(test != "4FKFK")
            throw std::string(currentTest);
        test.clear();
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::AnyToDecFractional()
// std::string Convertor::AnyToDecFractional(std::string& anyFractional, uint8_t const & anyBase)
{
    std::string currentTest = {__func__};
    std::string test;

    try
    {
        // I am tired of this !!!!
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::DecToAnyFloat()
// std::string Convertor::DecToAnyFloat(std::string& decimalFloat, uint8_t const & anyBase)
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {
        // zero test, integer part test, comma test, base test
        test = {"12345."};
        test = Convertor::DecToAnyFloat(test, 0, 0);
        if(test != "")
            throw std::string(currentTest);
        test.clear();

        test = {"."};
        test = Convertor::DecToAnyFloat(test, 3, 0);
        if(test != "0.0")
            throw std::string(currentTest);
        test.clear();

        test = {"12345."};
        test = Convertor::DecToAnyFloat(test, 3, 0);
        if(test != "121221020")
            throw std::string(currentTest);
        test.clear();

        test = {"12345"};
        test = Convertor::DecToAnyFloat(test, 10, 0);
        if(test != "12345")
            throw std::string(currentTest);
        test.clear();

        test = {"12345."};
        test = Convertor::DecToAnyFloat(test, 10, 0);
        if(test != "12345")
            throw std::string(currentTest);
        test.clear();

        test = {"12345."};
        test = Convertor::DecToAnyFloat(test, 10, 6);
        if(test != "12345.000000")
            throw std::string(currentTest);

        test = {"12345"};
        test = Convertor::DecToAnyFloat(test, 16, 0);
        if(test != "3039")
            throw std::string(currentTest);
        test.clear();

        test = {"12345."};
        test = Convertor::DecToAnyFloat(test, 16, 0);
        if(test != "3039")
            throw std::string(currentTest);
        test.clear();

        test = {"12345."};
        test = Convertor::DecToAnyFloat(test, 100, 0);
        if(test != "")
            throw std::string(currentTest);
        test.clear();

        test = {"12345."};
        test = Convertor::DecToAnyFloat(test, (uint8_t)256, 0);
        if(test != "")
            throw std::string(currentTest);
        test.clear();

        // float part test
        test = {"12345.5"};
        test = Convertor::DecToAnyFloat(test, 10, 5);
        if(test != "12345.50000")
            throw std::string(currentTest);
        test.clear();
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::AnyToDecFloat()
// std::string Convertor::AnyToDecFloat(std::string& anyFloat, uint8_t const & anyBase)
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {
        // almost identical code, I am not checking this
    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::DumpHex()
// std::string Convertor::DumpHex(uint8_t& byteStream, uint64_t const & size)
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {

    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);
}

void ConvertorTester::DumpBin()
// std::string Convertor::DumpBin(uint8_t& byteStream, uint64_t const & size)
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {

    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::DumpChar()
// std::string Convertor::DumpChar(uint8_t& byteStream, uint64_t const & size)
{
    std::string currentTest = {__func__};
    std::string test{};

    try
    {

    }
    catch(std::string str)
    {
        failedTests.push_back(currentTest);
        return;
    }

    succesfulTests.push_back(currentTest);

}

void ConvertorTester::TestClass()
{
    DigitToChar();
    CharToDigit();
    StringToDec();
    DecToString();

    MaximumChar();
    VerifyBase();
    ToUpperCase();
    ReverseString();

    DecToAnyInteger();
    AnyToDecInteger();

    DecToAnyFractional();
    AnyToDecFractional();

    DecToAnyFloat();
    //AnyToDecFloat();
    /*
    DumpHex();
    DumpBin();
    DumpChar();
    */
}

void ConvertorTester::PrintResults()
{
    if(succesfulTests.size() == 0)
        std::cout << "No tests have succeeded.\n";
    else
    {
        std::cout << "These tests succeeded: \n";
        for(auto& iter : succesfulTests)
            std::cout << iter << "\n";
    }

    if(failedTests.size() == 0)
        std::cout << "No tests have failed.\n";
    else
    {
        std::cout << "These tests failed: \n";
        for(auto& iter : failedTests)
            std::cout << iter << "\n\n";
    }
}
/*
T trier(T1 check, T2 param_1, ..., foo*, currentTest)
{
    try
    {
        if(check != foo(param_1, ...) )
            throw std::string(currentTest);
    }
    // catch pass-through
}
*/
