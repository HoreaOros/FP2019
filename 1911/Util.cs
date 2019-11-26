using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1911
{
    static class Util
    {
        public static int Maxim(this int[] v)
        {
            int max;
            max = v[0];
            for (int i = 1; i < v.Length; i++)
            {
                if (v[i] > max)
                {
                    max = v[i];
                }
            }
            return max;
        }
        public static bool IsPrime(this int v)
        {
            if (v < 2)
            {
                return false;
            }
            if (v == 2)
            {
                return true;
            }
            if (v % 2 == 0)
            {
                return false;
            }
            for (int d = 3; d * d <= v; d = d + 2)
            {
                if (v % d == 0)
                {
                    return false;
                }
            }

            return true;
        }
    }
}
