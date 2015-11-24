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
            int x;
            while ((line = Console.ReadLine()) != null)
            {
                x = int.Parse(line);
                if (x > 100 || x < 0) Console.WriteLine("Score is error!");
                else if (x >= 90) Console.WriteLine("A");
                else if (x >= 80) Console.WriteLine("B");
                else if (x >= 70) Console.WriteLine("C");
                else if (x >= 60) Console.WriteLine("D");
                else if (x >= 0) Console.WriteLine("E");
            }
        }
    }
}
