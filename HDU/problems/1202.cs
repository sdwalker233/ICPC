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
                int n = int.Parse(line);
                int i;
                double a, b, ans = 0, sum = 0;
                for(i=1;i<= n; i++)
                {
                    line = Console.ReadLine();
                    string[] s = new string[2];
                    s = line.Split(' ');
                    a = double.Parse(s[0]);
                    b = double.Parse(s[1]);
                    if (b < 0) continue;
                    if (b >= 90) b = 4;
                    else if (b >= 80) b = 3;
                    else if (b >= 70) b = 2;
                    else if (b >= 60) b = 1;
                    else b = 0;
                    ans += a * b;
                    sum += a;
                }
                if (sum < 1e-8)
                {
                    Console.WriteLine("-1");
                }
                else Console.WriteLine("{0:f2}", ans / sum);
            }
        }
    }
}