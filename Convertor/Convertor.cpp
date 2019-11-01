#include "Convertor.hpp"
#include <iostream>

char Convertor::DigitToChar(uint8_t const & digit)
{
    // supported bases are from 1 to 36
    if(digit < 10)
        return ( '0' + digit );
    else if (digit < 36)
        return ( 'A' + (digit - 10) );

    return '\0'; // unhandled bases
}

uint8_t Convertor::CharToDigit(char const & digitChar, uint8_t const & anyBase)
{
    std::string str{digitChar};
    ToUpperCase(str);

    if( VerifyBase(str, anyBase) )
    {
        if(anyBase == 0)
            return 0;
        else if(anyBase < 11)
        {
            if( !(digitChar >= '0' && digitChar <= ('0' + anyBase - 1) ) )
                return 0;
            else
                return (digitChar - '0');
        }
        else if(anyBase < 37)
        {
            if( !(digitChar >= '0' && digitChar <= '9') && !(digitChar >= 'A' && digitChar <= ('A' + anyBase - 11) ) )
                return 0;
            else
            {
                if(digitChar >= '0' && digitChar <= '9')
                    return (digitChar - '0');
                else
                    return (digitChar - 'A' + 10);
            }
        }
    }

    return 0;
}

uint64_t Convertor::StringToDec(std::string& str, uint8_t const & anyBase)
{
    uint64_t result{0};
    uint64_t power{1};

    ToUpperCase(str);

    if(VerifyBase(str, anyBase) && str.size() != 0)
    {
        for(uint64_t i = str.size() - 1; i > 0; i--)
        {
            result += CharToDigit(str[i], anyBase) * power;
            power *= anyBase;
        }

        result += CharToDigit(str[0], anyBase) * power;
    }

    return result;
}

std::string Convertor::DecToString(uint64_t number, uint8_t const & anyBase)
{
    std::string result{};
    if(anyBase > 36)
        return result;

    while(number)
    {
        result += DigitToChar(number % anyBase);
        number /= anyBase;
    }

    ReverseString(result);

    return result;
}

char const Convertor::MaximumChar(uint8_t const & anyBase)
{
    if(anyBase == 0)
        return '\0';
    else if(anyBase < 11)
    {
        return ('0' + anyBase - 1);
    }
    else if(anyBase < 37)
    {
        return ('A' + anyBase - 11);
    }
    else
        return '\0';
}

bool Convertor::VerifyBase(std::string const & anyNumber, uint8_t const & anyBase)
{
    if(anyBase == 0)
        return false;

    char const maxChar = MaximumChar(anyBase);

    if(anyBase < 11)
    {
        for(auto& iter : anyNumber)
        {
            if( !(iter >= '0' && iter <= maxChar) )
                return false;
        }
    }
    else if(anyBase < 37)
    {
        for(auto& iter : anyNumber)
        {
            if( !( (iter >= '0' && iter <= '9') || (iter >= 'A' && iter <= maxChar) ) )
                return false;
        }
    }
    else
    {
        return false;
    }

    return true;
}

std::string Convertor::ToUpperCase(std::string& str)
{
    uint8_t const bitMask = 0b00100000;

    for(auto& iter : str)
    {
        if(iter >= 'a' && iter <= 'z')
            iter ^= bitMask;
    }

    return str;
}

void Convertor::ReverseString(std::string& str)
{
    uint64_t const size = { str.size() };

    for(uint64_t i = 0; i < size / 2; i++)
    {
        std::swap( str[i], str[size - i - 1] );
    }
}

std::string Convertor::DecToAnyInteger(std::string& decimal, uint8_t const & anyBase)
{
    if(anyBase < 37)
    {
        if( VerifyBase(decimal, 10) )
        {
            std::string result{};
            uint64_t numericalProcessing{StringToDec(decimal, 10)};

            while(numericalProcessing)
            {
                result += DigitToChar(numericalProcessing % anyBase);
                numericalProcessing /= anyBase;
            }

            ReverseString(result);

            return result;
        }
    }
    return std::string{};
}

std::string Convertor::AnyToDecInteger(std::string& anyNumber, uint8_t const & anyBase)
{
    if(anyBase < 37)
    {
        ToUpperCase(anyNumber);

        if( VerifyBase(anyNumber, anyBase) )
        {
            std::string result{};
            uint64_t numericalProcessing{StringToDec(anyNumber, anyBase)};

            while(numericalProcessing)
            {
            result += DigitToChar(numericalProcessing % 10);
                numericalProcessing /= 10;
            }

            ReverseString(result);

            return result;
        }
    }
    return std::string{};
}

std::string Convertor::DecToAnyFractional(std::string& decimalFractional, uint8_t const & anyBase, uint8_t const & fractionalDigits)
{
    if(anyBase < 37 && VerifyBase(decimalFractional, 10))
    {
        ToUpperCase(decimalFractional);

        std::string result{};
        double numericalProcessing{};
        double power {0.1};
        uint8_t digit{};

        for(auto& digit : decimalFractional)
        {
            numericalProcessing += power * CharToDigit(digit, 10);
            power /= 10;
        }

        while(result.size() < fractionalDigits)
        {
            if(numericalProcessing == 0.0)
                result += '0';

            numericalProcessing *= anyBase;
            digit = (uint8_t)numericalProcessing;
            numericalProcessing -= (double)digit;

            result += DigitToChar(digit);
        }
        return result;
    }
    return std::string{};
}

std::string Convertor::AnyToDecFractional(std::string& anyFractional, uint8_t const & anyBase, uint8_t const & fractionalDigits)
{
    if(anyBase < 37 && VerifyBase(anyFractional, anyBase))
    {
        ToUpperCase(anyFractional);

        std::string result{};
        double numericalProcessing{};
        double power {1.0 / anyBase};
        uint8_t digit{};

        for(auto& digit : anyFractional)
        {
            numericalProcessing += power * CharToDigit(digit, anyBase);
            power /= anyBase;
        }

        while(result.size() < fractionalDigits)
        {
            if(numericalProcessing == 0.0)
                result += '0';

            numericalProcessing *= 10;
            digit = (uint8_t)numericalProcessing;
            numericalProcessing -= (double)digit;

            result += DigitToChar(digit);
        }
        return result;
    }

    return std::string{};
}

std::string Convertor::DecToAnyFloat(std::string& decimalFloat, uint8_t const & anyBase, uint8_t const & fractionalDigits)
{
    if(anyBase > 0 && anyBase < 37 && VerifyBase(decimalFloat, 10))
    {
        std::string integerPart{};
        std::string fractionalPart{};
        bool comma{false};

            // break decimal float into its integer and fractional part
            // and individually call each specialized function
        uint64_t i{0};
        for(; i < decimalFloat.size(); i++)
        {
            if(decimalFloat[i] == '.')
            {
                comma = {true};
                break;
            }

            integerPart += decimalFloat[i];
        }
            // now substitute the input with the result
        integerPart = DecToAnyInteger(integerPart, anyBase);

        for(++i; i < decimalFloat.size(); i++)
        {
            fractionalPart += decimalFloat[i];
        }
        fractionalPart = DecToAnyFractional(fractionalPart, anyBase, fractionalDigits);

        // finally, just concatenate the two parts
            // handle the "." type of input
        if(integerPart == "" && fractionalPart == "")
            return std::string{"0.0"};
            // and the "normal" input
        return (integerPart + ( (comma)? "." : "" ) + fractionalPart);
     }
     return std::string{};
}

std::string Convertor::AnyToDecFloat(std::string& anyFloat, uint8_t const & anyBase, uint8_t const & fractionalDigits)
{
    if(anyBase > 0 && anyBase < 37 && VerifyBase(anyFloat, anyBase))
    {
        std::string integerPart{};
        std::string fractionalPart{};
        bool comma{false};

            // break decimal float into its integer and fractional part
            // and individually call each specialized function
        uint64_t i{0};
        for(; i < anyFloat.size(); i++)
        {
            if(anyFloat[i] == '.')
            {
                comma = {true};
                break;
            }

            integerPart += anyFloat[i];
        }
        integerPart = AnyToDecInteger(integerPart, anyBase);

        for(++i; i < anyFloat.size(); i++)
        {
            fractionalPart += anyFloat[i];
        }
        fractionalPart = AnyToDecFractional(fractionalPart, anyBase, fractionalDigits);

        std::cout << integerPart << " + " << fractionalPart << " -- ";

        // finally, just concatenate the two parts
            // handle the "." type of input
        if(integerPart == "" && fractionalPart == "")
            return std::string{"0.0"};
            // and the "normal" input
        return (integerPart + ( (comma)? "." : "" ) + fractionalPart);
     }
    return std::string{};
}

std::string Convertor::DumpHex(uint8_t& byteStream, uint64_t const & size)
{
    return std::string{};
}

std::string Convertor::DumpBin(uint8_t& byteStream, uint64_t const & size)
{
    return std::string{};
}

std::string Convertor::DumpChar(uint8_t& byteStream, uint64_t const & size)
{
    return std::string{};
}
