#include <iostream>
using namespace std;

bool IsPrime(uint32_t n)
{
    // invalid inputs
    if(n < 2)
        return false;

    // the series is: 2, 3, 5, 7, ... (+= 2) ... i * i == n (i ~ sqrt(n))
    for(uint32_t i = 2; i * i <= n; i += ((i % 2)? 2 : 1))
        // divisor found -> not prime
        if((n % i) == 0)
            return false;

    // no divisors found -> is prime
    return true;
}

int main()
{
    for(uint32_t i = 1; i < 101; i++)
        if(i % 5 == 0)
            std::cout << "prime(" << i << "): " << IsPrime(i) << "\n";
        else
            std::cout << "prime(" << i << "): " << IsPrime(i) << "  ";
}
