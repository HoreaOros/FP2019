using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1401
{
    class Program
    {
        static void Main(string[] args)
        {
            DataCalendaristica d1 = new DataCalendaristica(14, 1, 2020);
            DataCalendaristica d2 = new DataCalendaristica(1, 1, 2001);


            Console.WriteLine(d1);
            Console.WriteLine(d2);
            // afisam numarul de zile dintre cele doua date calendaristice
            Console.WriteLine(d2.Zile(d1));


            // sortare prin numarare (counting sort)
            int[] v = new int[10000000];
            int max = 100;
            Random rnd = new Random();
            for (int i = 0; i < v.Length; i++)
            {
                v[i] = rnd.Next(max);
            }
            //for (int i = 0; i < v.Length; i++)
            //{
            //    Console.Write($"{v[i]} ");
            //}


            // vector de frecventa;
            int[] f = new int[max];

            for (int i = 0; i < v.Length; i++)
            {
                f[v[i]]++;
            }
            for (int i = 0; i < f.Length; i++)
            {
                Console.Write($"{f[i]} ");
            }

            for (int i = 0; i < f.Length; i++)
            {
                for (int j = 0; j < f[i]; j++)
                {
                    Console.Write($"{i} ");
                }
            }
        }
    }
}
