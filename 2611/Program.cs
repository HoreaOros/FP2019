using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2611
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] v;

            v = CreateIntArray(100000);
            InitArrayRandom(v, 0, 100);
            PrintArray(v);

            // Array.Sort(v);

            // InsertionSort(v);

            // SelectionSort(v);

            BubbleSort(v);
            PrintArray(v);







        }

        private static void BubbleSort(int[] v)
        {
            //       for i = 1:n,
            //       swapped = false
            //       for j = n:i + 1,
            //        if a[j] < a[j - 1],
            //            swap a[j, j - 1]
            //            swapped = true
            //    → invariant: a[1..i] in final position
            //    break if not swapped
            //      end
            bool swapped = false;
            int aux;
            for (int i = 0; i < v.Length; i++)
            {
                swapped = false;
                for (int j = v.Length - 1; j >= i + 1; j--)
                {
                    if (v[j] < v[j - 1])
                    {
                        aux = v[j - 1]; v[j - 1] = v[j]; v[j] = aux;
                        swapped = true;
                    }
                }
                if (!swapped)
                    break;
            }
        }

        private static void SelectionSort(int[] v)
        {
            //    for i = 1:n,
            //      k = i
            //      for j = i + 1:n, if a[j] < a[k], k = j
            //          → invariant: a[k] smallest of a[i..n]
            //          swap a[i, k]
            //     → invariant: a[1..i] in final position
            //      end
            int k, aux;
            for (int i = 0; i < v.Length; i++)
            {
                k = i;
                for (int j = i + 1; j < v.Length; j++)
                {
                    if (v[j] < v[k])
                    {
                        k = j;
                    }
                }
                aux = v[i];
                v[i] = v[k];
                v[k] = aux;
                PrintArray(v);
            }
        }

        private static void InsertionSort(int[] v)
        {
            //            for i = 2:n,
            //              for (k = i; k > 1 and a[k] < a[k - 1]; k--)
            //                  swap a[k, k - 1]
            //               → invariant: a[1..i] is sorted
            //            end
            int aux;
            for(int i = 1; i < v.Length; i++)
            {
                for (int k = i; k > 0 && v[k] < v[k - 1]; k--)
                {
                    aux = v[k];
                    v[k] = v[k - 1];
                    v[k - 1] = aux;
                }

                PrintArray(v);
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
        private static void InitArrayRandom(int[] v, int minValue, int maxValue)
        {
            Random rnd = new Random();

            for (int i = 0; i < v.Length; i++)
            {
                v[i] = rnd.Next(minValue, maxValue);
            }
        }
        private static int[] CreateIntArray(int v)
        {
            return new int[v]; // toate elementele sunt 0;
        }
    }
}
