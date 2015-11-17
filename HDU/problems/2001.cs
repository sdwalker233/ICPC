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
            string line;
            double x1, x2, y1, y2;
            while ((line = Console.ReadLine()) != null)
            {
                string[] s = line.Split(' ');
                x1 = double.Parse(s[0]);
                y1 = double.Parse(s[1]);
                x2 = double.Parse(s[2]);
                y2 = double.Parse(s[3]);
                double dis = Math.Sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                Console.WriteLine("{0:F2}", dis);
            }
        }

    }
}
