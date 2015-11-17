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
            int t;
            t = int.Parse(Console.ReadLine());
            while(t-->0) fuck();
        }

        private static void fuck()
        {
            int n, V, i, j;
            int[] v = new int[100010];
            long sum = 0;
            string line;
            string[] s = new string[100010];
            line = Console.ReadLine();
            s = line.Split(' ');
            n = int.Parse(s[0]);
            V = int.Parse(s[1]);
            line = Console.ReadLine();
            s = line.Split(' ');
            for (i = 0; i < n; i++)
                v[i] = int.Parse(s[i]);
            Array.Sort(v,0,n);
            for (i = 0; i < n; i++)
            {
                //Console.WriteLine(v[i]);
                if (sum + v[i] > V) break;
                sum += v[i];
            }
            Console.WriteLine(i);
        }
    }
}
