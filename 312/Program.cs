using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.Generic;
// BinPacking

namespace _312
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, C;


            n = int.Parse(Console.ReadLine());
            C = int.Parse(Console.ReadLine());

            int[] w = new int[n];

            string line;

            line = Console.ReadLine();
            // 1; ;2 3 
            string[] tokens;
            int i = 0;
            char[] sep = {' ', '\t', ',', ';' };
            tokens = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
            foreach (var item in tokens)
            {
                w[i++] = int.Parse(item);
            }

            int bins;
            bins = NextFit(w, C);
            Console.WriteLine($"Next Fit: {bins}");

            bins = FirstFit(w, C);
            Console.WriteLine($"First Fit: {bins}");

            bins = BestFit(w, C);
            Console.WriteLine($"Best Fit: {bins}");

            bins = WorstFit(w, C);
            Console.WriteLine($"Worst Fit: {bins}");


            Array.Sort(w, new DescComparer());
            foreach (var item in w)
            {
                Console.WriteLine(item);
            }

            bins = NextFit(w, C);
            Console.WriteLine($"Next Fit Desc: {bins}");

            bins = FirstFit(w, C);
            Console.WriteLine($"First Fit Desc: {bins}");

            bins = BestFit(w, C);
            Console.WriteLine($"Best Fit Desc: {bins}");

            bins = WorstFit(w, C);
            Console.WriteLine($"Worst Fit Desc: {bins}");


        }

        private static int WorstFit(int[] w, int C)
        {
            int[] bins = new int[w.Length];
            int b = 1, j;
            int ramas, minRamas = 0, bin = -1;
            for (int i = 0; i < w.Length; i++)
            {
                j = 0;
                // caut in containerele deschise
                // pe cel in care incape obiectul curent
                // si care lasa cel mai putin spatiu liber
                // 
                minRamas = C; bin = -1;
                for (j = 0; j < b; j++)
                {
                    if (bins[j] + w[i] <= C)
                    {
                        ramas = C - (bins[j] + w[i]);
                        if (ramas < minRamas)
                        {
                            minRamas = ramas;
                            bin = j;
                        }

                    }
                }
                if (bin == -1)
                {
                    // daca nu incape in nici un container
                    // deschid un container nou
                    b++;
                    bins[b - 1] = w[i];
                    Console.WriteLine($"{w[i]} goes in container {b}");
                }
                else
                {
                    bins[bin] += w[i];
                    Console.WriteLine($"{w[i]} goes in container {bin + 1}");
                }

            }


            return b;
        }

        /// <summary>
        /// Bin packing - Best Fit algorithm
        /// </summary>
        /// <param name="w">lista cu valorile obiectelor</param>
        /// <param name="C">Container capacity</param>
        /// <returns>numarul de containere folosite</returns>
        /// <remarks>
        /// Lista obiectelor se parcurge de la stanga la dreapta
        /// Pastram lista cu containerele deschise
        /// Fiecare se obiect se pune intr-un container in asa
        /// fel incat sa lase cel mai multe spatiu liber.
        /// Daca nu exista nici un container in care sa incapa 
        /// se deschide alt container. 
        /// </remarks>
        private static int BestFit(int[] w, int C)
        {
            int[] bins = new int[w.Length];
            int b = 1, j;
            int ramas, maxRamas = 0, bin = -1;
            for (int i = 0; i < w.Length; i++)
            {
                j = 0;
                // caut in containerele deschise
                // pe cel in care incape obiectul curent
                // si care lasa cel mai mult spatiu liber
                // 
                    
                maxRamas = 0; bin = -1;
                for (j = 0; j < b; j++)
                {
                    if (bins[j] + w[i] <= C)
                    {
                        ramas = C - (bins[j] + w[i]);
                        if (ramas > maxRamas)
                        {
                            maxRamas = ramas;
                            bin = j;
                        }
                            
                    }
                }
                if (bin == -1)
                {
                    // daca nu incape in nici un container
                    // deschid un container nou
                    b++;
                    bins[b - 1] = w[i];
                    Console.WriteLine($"{w[i]} goes in container {b}");
                }
                else
                {
                    bins[bin] += w[i];
                    Console.WriteLine($"{w[i]} goes in container {bin + 1}");
                }

            }


            return b;
        }

        private static int FirstFit(int[] w, int C)
        {
            int[] bins = new int[w.Length];
            int b = 1, j;

            for (int i = 0; i < w.Length; i++)
            {
                j = 0; 
                while (j < b && bins[j] + w[i] > C)
                {
                    j++;
                }
                if (j < b)
                {
                    bins[j] += w[i];
                    Console.WriteLine($"{w[i]} goes in container {j + 1}");
                }
                else
                {
                    b++;
                    bins[b - 1] = w[i];
                    Console.WriteLine($"{w[i]} goes in container {b}");
                }

            }


            return b;
        }

        private static int NextFit(int[] w, int C)
        {
            int bins = 1;
            int currentCapacity = 0;

            for (int i = 0; i < w.Length; i++)
            {
                // verific daca obiectul curent incape
                // in containterul deschis.

                if (currentCapacity + w[i] <= C)// daca da, -- il adaug in container
                {
                    currentCapacity += w[i];
                    Console.WriteLine($"{w[i]} goes in container {bins}");
                }
                    
                else
                {// daca nu, -- deschid un nou container si adaug obiectul in containerul tocmai deschis.
                    bins++;
                    currentCapacity = w[i];
                    Console.WriteLine($"{w[i]} goes in container {bins}");
                }

                
                
            }

            return bins;
        }
    }
}
