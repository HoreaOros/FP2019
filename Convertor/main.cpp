#include <iostream>

#include "Convertor.hpp"
#include "ConvertorTester.hpp"

int main()
{
    std::string test{};

    ConvertorTester tester;
    tester.TestClass();
    tester.PrintResults();

    std::cout << "\nSome examples for DecToAnyFloat:\n";
    test = "123465.623567";

    for(uint8_t i = 0; i < 37; i += 2)
        std::cout << Convertor::DecToAnyFloat(test, i, 8) << "\n";

    std::cout << "\nSome examples for AnyToDecFloat:\n";
    test = "123465.623567";

    for(uint8_t i = 0; i < 37; i += 2)
        std::cout << Convertor::AnyToDecFloat(test, i, 8) << "\n";
}
