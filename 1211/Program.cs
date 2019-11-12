using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
namespace _1211
{
    class Program
    {
        static void Main(string[] args)
        {
            // se dau 5 numere. se cere sa se afiseze 
            // in ordine descrecatoare cele mai mari 3 dintre ele.

            // 15, 6, 9, 8, 22 => 22, 15, 9


            try
            {
                //int a, b, c, d, e;
                //(a, b, c, d, e) = (15, 6, 9, 8, 22);

                //int x, y, z;
                //(x, y, z) = Max3(a, b, c, d, e);

                //Console.WriteLine((x, y, z));

                // "3n+1"
                // se da un nr. a natural
                // x_n, x_0 = a, 
                // x_n = x_(n-1) / 2 daca x_(n-1) este par
                // x_n = 3 * x_(n-1) + 1 daca x_(n-1) este impar
                int x0 = 100;

                int lungime, maxim;
                int a = 1, b = 1;

                Stopwatch sw = new Stopwatch();
                sw.Start();
                int lungimeMaxima = 0;
                int nrLngMax = 0;
                for(x0 = a; x0 <= b; x0++)
                {
                    (lungime, maxim) = TreiNPlus1(x0);
                    Console.WriteLine($"Lungimea sirului este: {lungime}");

                    if(lungime > lungimeMaxima)
                    {
                        lungimeMaxima = lungime;
                        nrLngMax = x0;
                    }
                }
                sw.Stop();

                Console.WriteLine("Durata: {0}", sw.ElapsedMilliseconds);
                Console.WriteLine("Cea mai lunga secventa se obtine pentru numarul {0} si are lungimea {1}", nrLngMax, lungimeMaxima);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }


            Random rnd = new Random();
            int coin0 = 0, coin1 = 0;
            for (int i = 0; i < 1000000; i++)
            {
                if (rnd.Next(2) == 0)
                {
                    coin0++;
                }
                else
                    coin1++;
            }
            Console.WriteLine($"coin0 = {coin0}, coin1 = {coin1}");
        }

        private static (int, int) TreiNPlus1(int a)
        {
            int n = 1, maxim = 0;
            Console.Write($"{a}, ");
            maxim = a;
            while (a != 1)
            {
                if (a % 2 == 0)
                    a = a / 2;
                else
                    a = 3 * a + 1;
                if (a > maxim)
                    maxim = a;

                Console.Write($"{a}, ");
                n++;
            }
            // TODO: Dupa ultima valoare trebuie afisat punct.
            Console.WriteLine();

            return (n, maxim);
        }

        private static (int, int, int) Max3(int a, int b, int c, int d, int e)
        {
            int x = 0, y = 0, z = 0;

            // a
            x = a;

            // b
            if (b < x)
                y = b;
            else
            {
                y = x;
                x = b;
            }



            // c
            if (c >= x)
            {
                z = y;
                y = x;
                x = c;
            }
            else if (c >= y)
            {
                z = y;
                y = c;
            }
            else
                z = c;

            // d
            if(d >= x)
            {
                z = y;
                y = x;
                x = d;
            }
            else if(d >= y)
            {
                z = y;
                y = d;
            }
            else if(d >= z)
            {
                z = d;
            }


            // e
            if (e >= x)
            {
                z = y;
                y = x;
                x = e;
            }
            else if (e >= y)
            {
                z = y;
                y = e;
            }
            else if (e >= z)
            {
                z = e;
            }
            return (x, y, z);
        }
    }
}
