using System;

namespace _1401
{
    class DataCalendaristica
    {
        private int zi;
        private int luna;
        private int an;

        // constructor
        public DataCalendaristica(int zi, int luna, int an)
        {
            this.zi = zi;
            this.luna = luna;
            this.an = an;
        }

        internal int Zile(DataCalendaristica d)
        {
            int count = 0;

            while (!this.EsteEgalCu(d))
            {
                d.ScadOZi();
                count++;
            }

            return count;
        }

        private void ScadOZi()
        {
            if (this.zi > 1)
            {
                this.zi--;
            }
            else
                switch(this.luna)
                {
                    case 1:
                        this.zi = 31;
                        this.luna = 12;
                        this.an--;
                        break;
                    case 2:
                    case 4:
                    case 6:
                    case 8:
                    case 9:
                    case 11:
                        this.zi = 31;
                        this.luna--;
                        break;
                    case 3:
                        this.luna--;
                        if ((an % 4 == 0 && an % 100 != 0) || an % 400 == 0)
                            this.zi = 29;
                        else
                            this.zi = 28;
                        break;
                    case 5:
                    case 7:
                    case 10:
                    case 12:
                        this.luna--;
                        this.zi = 30;
                        break;
                }
        }

        private bool EsteEgalCu(DataCalendaristica d)
        {
            return this.zi == d.zi && this.luna == d.luna && this.an == d.an;
            //if (this.zi == d.zi && this.luna == d.luna && this.an == d.an)
            //{
            //    return true;
            //}
            //else
            //    return false;
        }

        public override string ToString()
        {
            return zi.ToString() + "-" + luna.ToString() + "-" + an.ToString();
        }
    }
}