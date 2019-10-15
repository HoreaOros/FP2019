using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1510
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World");

            int a, b;

            Console.WriteLine("Introduceti un numar: ");
            a = int.Parse(Console.ReadLine());

            Console.WriteLine("Introduceti inca un numar: ");
            b = int.Parse(Console.ReadLine());


            // Operatori aritmetici
            long r; // -2^63 --> 2^63 - 1

            r = (long)a + b; // (long) operator de conversie explicita
            try
            {
                checked
                {
                    Console.WriteLine("{0} + {1} = {2}", a, b, r);
                }
            }
            catch (OverflowException ex)
            {
                Console.WriteLine(ex.Message);
            }
            // TODO


            int dif, mult, div, mod;


            //a = 7; b = 3; // 7 si 3 sunt constante (literal)
            dif = a - b;
            mult = a * b;
            div = a / b;
            mod = a % b;

            Console.WriteLine("{0} - {1} = {2}", a, b, dif);
            Console.WriteLine("{0} * {1} = {2}", a, b, mult);
            Console.WriteLine("{0} / {1} = {2}", a, b, div);
            Console.WriteLine("{0} % {1} = {2}", a, b, mod);

            float f; // numar real stocat pe 32 de biti

            f = 1.0f * a / b;

            Console.WriteLine("{0} / {1} = {2:0.00}", a, b, f);


            byte by; // intreg fara semn / 8 biti [0,255]
            sbyte sb; // intreg cu semn / 8 biti [-128,127]
            short s; // intreg cu semn / 16 biti [-32768, 32767]
            ushort us; // intreg fara semn / 16 biti [0, 65535]
            int i; // intreg cu semn / 32 biti
            uint ui; // intreg fara semn / 32 biti
            long lng; // intreg cu semn / 64 biti
            ulong ulng; // intreg fara semn / 64 biti


            bool ans; // bool = Boolean {False, True}

            ans = a < b;
            Console.WriteLine("{0} < {1} -> {2}", a, b, ans);

            ans = a > b;
            Console.WriteLine("{0} > {1} -> {2}", a, b, ans);

            ans = a <= b;
            Console.WriteLine("{0} <= {1} -> {2}", a, b, ans);

            ans = a >= b;
            Console.WriteLine("{0} >= {1} -> {2}", a, b, ans);

            ans = a == b; // 
            Console.WriteLine("{0} == {1} -> {2}", a, b, ans);


            ans = a != b; // operatorul de inegalitate
            Console.WriteLine("{0} != {1} -> {2}", a, b, ans);

        }
    }
}
 