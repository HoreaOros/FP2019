using System;
using System.Collections.Generic;
namespace _312
{
    internal class DescComparer : IComparer<int>
    {
        public int Compare(int x, int y)
        {
            return y - x;
        }
    }
}