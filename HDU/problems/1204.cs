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
            while ((line = Console.ReadLine()) != null)
            {
                int n, m;
                double p, q, r, ans;
                string[] s = new string[4];
                s = line.Split(' ');
                n = int.Parse(s[0]);
                m = int.Parse(s[1]);
                p = double.Parse(s[2]);
                q = double.Parse(s[3]);
                if (n == 0) { Console.WriteLine("0.00"); continue; }
                if (m == 0) { Console.WriteLine("1.00"); continue; }
                if (p == 0 || q == 1) { Console.WriteLine("0.00");continue; }
                if (p == q) { Console.WriteLine("{0:f2}", (double)n / (n + m));continue; }
                r = q * (1 - p) / p / (1 - q);
                ans = (1 - Math.Pow(r, n)) / (1 - Math.Pow(r, n + m));
                Console.WriteLine("{0:f2}",ans);
             }
        }
    }
}
