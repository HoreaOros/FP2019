#ifndef CONVERTOR_HPP_INCLUDED
#define CONVERTOR_HPP_INCLUDED

#include <string>

// this thing is only lacking an SRS and documentation =))

class Convertor
{
public:

    // digit <-> char
    static char DigitToChar(uint8_t const & digit);
    static uint8_t CharToDigit(char const & digitChar, uint8_t const & anyBase);
    static uint64_t StringToDec(std::string& str, uint8_t const & anyBase);
    static std::string DecToString(uint64_t number, uint8_t const & anyBase);

    // utilitaries
    static char const MaximumChar(uint8_t const & anyBase);
    static bool VerifyBase(std::string const & anyNumber, uint8_t const & anyBase);
    static std::string ToUpperCase(std::string& str);
    static void ReverseString(std::string& str);

    // base conversions
        // integer parts only
    static std::string DecToAnyInteger(std::string& decimalInteger, uint8_t const & anyBase);
    static std::string AnyToDecInteger(std::string& anyInteger, uint8_t const & anyBase);
        // fractional part only
    static std::string DecToAnyFractional(std::string& decimalFractional, uint8_t const & anyBase, uint8_t const & fractionalDigits);
    static std::string AnyToDecFractional(std::string& anyFractional, uint8_t const & anyBase, uint8_t const & fractionalDigits);
        // combining integer and fractional parts
    static std::string DecToAnyFloat(std::string& decimalFloat, uint8_t const & anyBase, uint8_t const & fractionalDigits);
    static std::string AnyToDecFloat(std::string& anyFloat, uint8_t const & anyBase, uint8_t const & fractionalDigits);

    // specialized functions
    std::string DumpHex(uint8_t& byteStream, uint64_t const & size);
    std::string DumpBin(uint8_t& byteStream, uint64_t const & size);
    std::string DumpChar(uint8_t& byteStream, uint64_t const & size);
};

#endif // CONVERTOR_HPP_INCLUDED
