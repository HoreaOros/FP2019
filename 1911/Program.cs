using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace _1911
{
    class Program
    {
        static void Main(string[] args)
        {
            // Tablouri unidimensionale

            int[] tab; // definesc variabila cu ajutorul
            // careia ma refer la vector (tablou unidimensional)

            tab = CreateIntArray(10);// aloc memorie pentru elementele
            // tabloului


            // stack vs. heap;

            for (int i = 0; i < tab.Length; i++)
            {
                tab[i] = i;
            }

            PrintArray(tab);
            Shuffle(tab);
            PrintArray(tab);


            int[] v;
            v = CreateIntArray(10);
            InitArrayRandom(v, 0 , 100);
            PrintArray(v);
            
            Console.WriteLine($"Cea mai mare valoare este: {v.Maxim()}");

            Console.WriteLine($"Sunt {CountPrimes(v)} numere prime");
        }

        private static int CountPrimes(int[] v)
        {
            List<int> primes = new List<int>();
            int count = 0;

            foreach (var item in v)
            {
                if (item.IsPrime())
                {
                    count++;
                    primes.Add(item);
                }
            }

            // ??
            Console.WriteLine("Primes: ");
            foreach (var item in primes)
            {
                Console.Write($"{item} ");
            }
            Console.WriteLine();

            return count;
        }

        private static void InitArrayRandom(int[] v, int minValue, int maxValue)
        {
            Random rnd = new Random();

            for (int i = 0; i < v.Length; i++)
            {
                v[i] = rnd.Next(minValue, maxValue);
            }
         }

        private static void Shuffle(int[] tab)
        {
            //            --To shuffle an array a of n elements(indices 0..n - 1):
            //for i from n−1 downto 1 do
            //     j ← random integer such that 0 ≤ j ≤ i
            //     exchange a[j] and a[i]
            Random rnd = new Random();
            int j, aux;
            for(int i = tab.Length - 1; i >= 1; i--)
            {
                j = rnd.Next(0, i + 1);
                aux = tab[i];
                tab[i] = tab[j];
                tab[j] = aux;
            }
        }

        private static void PrintArray(int[] tab)
        {
            // nu pot modifica elementele vectorului
            foreach (var item in tab)
            {
                Console.Write($"{item} ");
            }
            Console.WriteLine();
        }

        private static int[] CreateIntArray(int v)
        {
            return new int[v]; // toate elementele sunt 0;
        }
    }
}
