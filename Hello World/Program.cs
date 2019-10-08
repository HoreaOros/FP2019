using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hello_World
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World of C#!");
            Console.Beep(1000, 1000);

            int n; // [-2^31 -- > 2^31 - 1]

            string line;


            Console.WriteLine("Introduceti un numar: ");
            line = Console.ReadLine();

            try
            {
                n = int.Parse(line);
                Console.WriteLine("Ati introdus: {0}", n);
            }
            catch (FormatException)
            {
                Console.WriteLine("Nu ati introdus un numar");
            }
            catch(OverflowException)
            {
                Console.WriteLine("Numarul introdus nu este in limitele lui int");
            }
        }
    }
}
