using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            while (t-- > 0)
            {
                string line = Console.ReadLine();
                string[] s = line.Split('-');
                int y, m, d;
                y = int.Parse(s[0]);
                m = int.Parse(s[1]);
                d = int.Parse(s[2]);
                if (y % 4 == 0 && y % 400!=0 && m == 2 && d == 29)
                {
                    Console.WriteLine("-1");
                    continue;
                }
                DateTime a = new DateTime(y, m, d);
                DateTime b = new DateTime(y + 18, m, d);
                TimeSpan x = b - a;
                Console.WriteLine("{0}",x.Days);
            }
        }
    }
}