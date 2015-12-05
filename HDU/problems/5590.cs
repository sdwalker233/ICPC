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
            int t = int.Parse(Console.ReadLine());
            while (t-- > 0)
            {
                int i;
                int n = int.Parse(Console.ReadLine());
                string s1 = Console.ReadLine();
                string s2 = Console.ReadLine();
                for(i=0;i< n; i++)
                {
                    if (!((s1[i] == 'A' && s2[i] == 'U') || (s1[i] == 'T' && s2[i] == 'A') || (s1[i] == 'C' && s2[i] == 'G') || (s1[i] == 'G' && s2[i] == 'C')))
                        break;
                }
                if (i >= n) Console.WriteLine("YES");
                else Console.WriteLine("NO");
            }
        }
    }
}
