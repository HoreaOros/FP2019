using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _701
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] matrice;
            int n = 10;

            // matrice patratica
            matrice = new int[n, n]; // dimensiunile matricii pot
            // fi stabilite la executie.


            Init(matrice);
            Print(matrice);

            // suma elementelor de pe diagonala principala

            try
            {
                Console.WriteLine(SumaDPFast(matrice));
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            // produsul elementelor de pe digonala secundara.
            Console.WriteLine(ProdusDS(matrice));
            // suma elementelor pare de sub diagonala principala
            // suma elementelor (numere prime) de 
            // deasupra diagonalei principale si deasupra diagonalei secundare
            // TODO

            // DP => i == j
            // DS => i + j == n - 1
            // DDP => i < j
            // SDP => i > j
            // DDS => i + j < n - 1;
            // SDS => i + j > n - 1

            // inmultirea matricilor
            int[,] A = new int[,] {
                    {1, 2, 3 },
                    {2, 3, 0 } };
            int[,] B = new int[,]
            {
                {2, 3},
                {4, 0},
                {1, 2}
            };
            int[,] C;

            C = MultiplyMatrix(A, B);
            Print(C);
        }

        private static int[,] MultiplyMatrix(int[,] a, int[,] b)
        {
            if (a.GetLength(1) != b.GetLength(0))
            {
                throw new Exception("arguments do not match");
            }


            int[,] c = new int[a.GetLength(0), b.GetLength(1)];

            for (int i = 0; i < c.GetLength(0); i++)
            {
                for (int j = 0; j < c.GetLength(1); j++)
                {
                    int suma = 0;
                    for (int k = 0; k < a.GetLength(1); k++)
                    {
                        suma += a[i, k] * b[k, j];
                    }
                    c[i, j] = suma;
                }
            }

            return c;
        }

        private static int ProdusDS(int[,] matrice)
        {
            int produs = 1;
            if (matrice.GetLength(0) != matrice.GetLength(1))
            {
                throw new Exception("matricea nu este patratica");
            }
            int n;
            n = matrice.GetLength(0);
            for (int i = 0; i < matrice.GetLength(0); i++)
            {
                for (int j = 0; j < matrice.GetLength(1); j++)
                {
                    if (i + j == n - 1)
                    {
                        produs *= matrice[i, j];
                    }
                }
            }
            return produs;
        }

        private static int SumaDPFast(int[,] matrice)
        {
            int suma = 0;
            if (matrice.GetLength(0) != matrice.GetLength(1))
            {
                throw new Exception("matricea nu este patratica");
            }
            for (int i = 0; i < matrice.GetLength(0); i++)
            {
                suma += matrice[i, i];
            }
            return suma;
        }

        /// <summary>
        /// Calculeaza suma elementelor de pe diagonala principala
        /// </summary>
        /// <param name="matrice">un tablou bidimensional patratic</param>
        /// <returns></returns>
        private static int SumaDP(int[,] matrice)
        {
            int suma = 0;
            if (matrice.GetLength(0) != matrice.GetLength(1))
            {
                throw new Exception("matricea nu este patratica");
            }
            for (int i = 0; i < matrice.GetLength(0); i++)
            {
                for (int j = 0; j < matrice.GetLength(1); j++)
                {
                    if (i == j)
                    {
                        suma += matrice[i, j];
                    }
                }
            }
            return suma;
        }

        private static void Print(int[,] matrice)
        {
            for (int i = 0; i < matrice.GetLength(0); i++)
            {
                for (int j = 0; j < matrice.GetLength(1); j++)
                {
                    Console.Write("{0} ", matrice[i, j]);
                }
                Console.WriteLine();
            }
        }

        private static void Init(int[,] matrice)
        {
            for (int i = 0; i < matrice.GetLength(0); i++)
            {
                for (int j = 0; j < matrice.GetLength(1); j++)
                {
                    matrice[i, j] = Math.Max(i, j);
                }
            }
        }
    }
}
