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
            int a, b;
            string line;
            string[] s = new string[3];
            while ((line = Console.ReadLine())!=null)
            {
                s = line.Split(' ');
                a = int.Parse(s[0]);
                b = int.Parse(s[1]);
                Console.WriteLine("{0}",a+b);
            }
        }
    }
}
