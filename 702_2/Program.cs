using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _702_2
{
    struct DataCalendaristica
    {
        int luna;
        int an;
        int zi;
        public DataCalendaristica(int z, int l, int a)
        {
            zi = z;
            an = a;
            luna = l;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            // diferenta dintre doua date calendaristice

            DataCalendaristica d1 = new DataCalendaristica(7, 1, 2020);


            DateTime d2 = DateTime.Now;

            DateTime d3 = new DateTime(1990, 07, 31);



            TimeSpan span = d2.Subtract(d3);
            Console.WriteLine($"Numarul de zile dintre {d2.ToShortDateString()} si {d3.ToShortDateString()} este {span.TotalDays}"); 
        }
    }
}
