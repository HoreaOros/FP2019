using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0511
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 4;
            int b = 7;
            int c = 4;

            //Console.WriteLine($"Cel mai mare numar dintre {a} si {b} este {Maxim(a, b)}");

            Console.WriteLine($"Cel mai mare numar dintre {a}, {b} si {c} este {Maxim3(a, b, c)}");


            // se dau doua numere. sa se afiseze in ordine descrscatoare
            OrderDesc(a, b);

            OrderDesc(a, b, c);

        }

        private static void OrderDesc(int a, int b, int c)
        {
            if(a > b)
                if(b > c)
                    Console.WriteLine($"{a} - {b} - {c}");
                else if(a > c)
                        Console.WriteLine($"{a} - {c} - {b}");
                    else
                        Console.WriteLine($"{c} - {a} - {b}");
            else
                if(a > c)
                    Console.WriteLine($"{b} - {a} - {c}");
                else if( b > c)
                    Console.WriteLine($"{b} - {c} - {a}");
                else
                    Console.WriteLine($"{c} - {b} - {a}");
        }

        private static void OrderDesc(int a, int b)
        {
            if(a  > b)
                Console.WriteLine($"{a} - {b}");
            else
                Console.WriteLine($"{b} - {a}");
        }

        private static int Maxim3(int a, int b, int c)
        {
            //return Maxim(Maxim(a, b), c);
            int max;
            if (a > b)
                if (a > c)
                    max = a;
                else
                    max = c;
            else if (b > c)
                    max = b;
                else
                    max = c;
            return max;
        }

        private static int Maxim(int a, int b)
        {
            // V1.
            //if (a > b)
            //    return a;
            //else
            //    return b;

            // V2
            //int max;
            //if (a < b)
            //    max = b;
            //else
            //    max = a;
            //return max;


            // V3
            //int max;
            //max = (a > b) ? a : b; // operatorul ternar ?:
            //return max;

            int max;

            max = Math.Max(a, b);
            return max;
        }
    }
}
