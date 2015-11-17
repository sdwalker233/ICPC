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
            char a, b, c;
            while ((line = Console.ReadLine()) != null)
            {
                a = line[0];
                b = line[1];
                c = line[2];
                if (a > b) swap(ref a, ref b);
                if (b > c) swap(ref b, ref c);
                if (a > b) swap(ref a, ref b);
                Console.WriteLine("{0} {1} {2}", a, b, c);
            }
        }

        private static void swap(ref char a, ref char b)
        {
            char tmp;
            tmp = a;
            a = b;
            b = tmp;
        }
    }
}
