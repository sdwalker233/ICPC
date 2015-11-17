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
            double x;
            while ((line = Console.ReadLine()) != null)
            {
                x = double.Parse(line);
                x = Math.Abs(x);
                Console.WriteLine("{0:F2}", x);
            }
        }
    }
}
