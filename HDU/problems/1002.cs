using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int t,i;
            string line;
            string[] s = new string[3];
            BigInteger a, b, c;
            t = int.Parse(Console.ReadLine());
            for (i = 1; i <= t; i++)
            {
                Console.WriteLine("Case {0}:", i);
                line = Console.ReadLine();
                s = line.Split(' ');
                a = BigInteger.Parse(s[0]);
                b = BigInteger.Parse(s[1]);
                c = a + b;
                Console.WriteLine("{0} + {1} = {2}", a, b, c);
                if (i < t) Console.WriteLine("");
            }
        }
    }
}