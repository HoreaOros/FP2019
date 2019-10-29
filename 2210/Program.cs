

using System;

namespace MyNameSpace
{
    class T { }
}

namespace _2210
{
    enum Day
    {
        Luni = 1,
        Marti,
        Miercuri, 
        Joi,
        Vineri,
        Sambata,
        Duminica = 0
    }
    class Program
    {
        static void Main(string[] args)
        {
            int n;

            //n = GetIntegerFromConsole();

            MyNameSpace.T t = new MyNameSpace.T();

            //Console.WriteLine("Suma cifrelor numarului: {0}", SumaCifre(n));


            string line;
            System.Console.WriteLine("Introduceti ziua saptamanii: ");
            line = System.Console.ReadLine();

            Day zi;

            zi = (Day)System.Enum.Parse(typeof(Day), line);

            //if(zi == Day.Luni)
            //    Console.WriteLine("A inceput o noua saptamana");
            //else if(zi == Day.Marti || zi == Day.Miercuri || zi == Day.Joi)
            //    Console.WriteLine("Suntem in mijlocul satpamanii");
            //else if(zi == Day.Vineri)
            //    Console.WriteLine("Se apropie weekendul");
            //else
            //    Console.WriteLine("Finally, weekend");

            switch (zi)
            {
                case Day.Luni:
                    Console.WriteLine("A inceput o noua saptamana");
                    break;
                case Day.Marti:
                case Day.Miercuri:
                case Day.Joi:
                    Console.WriteLine("Suntem in mijlocul saptamanii");
                    break;
                case Day.Vineri:
                    Console.WriteLine("Se apropie weekendul");
                    break;
                case Day.Sambata:
                case Day.Duminica:
                    Console.WriteLine("Finally, weekend");
                    break;
                default:
                    Console.WriteLine("ERROR!!");
                    break;
            }

        }

        static int SumaCifre(int n)
        {
            if (n == 0)
                return 0;
            else
                return n % 10 + SumaCifre(n / 10);
        }

        private static int GetIntegerFromConsole()
        {
            int n = 0;
            string line;
            bool ok = true;

            Console.WriteLine("Introduceti un numar intreg: ");
            line = Console.ReadLine();

            try
            {
                n = int.Parse(line);
            }
            catch(FormatException)
            {
                Console.WriteLine("Nu ati introdus un numar intreg. Mai incercati o data.");
                ok = false;
            }
            catch(OverflowException)
            {
                Console.WriteLine("Numarul nu este in limitele lui int");
                ok = false;
            }

            if (ok == false)
                n = GetIntegerFromConsole();

            return n;
        }
    }
}
