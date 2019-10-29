using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2910
{
    class Program
    {
        static void Main(string[] args)
        {
            // instructiuni pentru controlul executiei programului

            // if ... else


            int an = 2089657133;
            if((an % 4 == 0 && an % 100 != 0) || (an % 400 == 0))
                Console.WriteLine("An bisect");
            else
                //Console.WriteLine("Anul {0} nu este bisect", an);
                Console.WriteLine($"Anul {an} nu este bisect"); // string interpolation

            // ||   | false true
            // -------------------
            //false | false true
            //true  | true  true

            // &&   | false true
            // -------------------
            //false | false false
            //true  | false true


            // short circuit evaluation

            int i = 0;

            
            if(i < 0 && ++i == 1)
                Console.WriteLine("OK");

            Console.WriteLine($"i={i}");



            if (isPrimeReloaded2(an))
                Console.WriteLine($"{an} este prim");
            else
                Console.WriteLine($"{an} nu este prim") ;

            // while (cond) ...

            // do ... while (cond)

            // for(...)

            // switch ///


            // break, continue





        }

        private static bool isPrimeReloaded2(int n)
        {
            int contor = 0;

            for (int d = 2; d * d <= n; d++)
            {
                if (n % d == 0)
                {
                    contor++;
                    break;
                }
                    
            }

            if (contor == 0)
                return true;
            else
                return false;
        }

        private static bool isPrimeReloaded(int n)
        {
            int contor = 2;

            for (int d = 2; d <= n / 2; d++)
            {
                if (n % d == 0)
                    contor++;
            }

            if (contor == 2)
                return true;
            else
                return false;
        }

        private static bool isPrime(int n)
        {
            int contor = 0;

            for (int d = 1; d <= n; d++)
            {
                if (n % d == 0)
                    contor++;
            }

            if (contor == 2)
                return true;
            else
                return false;
        }
    }
}
