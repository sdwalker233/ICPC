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
            string[] s = new string[110];
            int[] a = new int[110];
            int b, c, n, i, j, cnt;
            while ((line = Console.ReadLine()) != null)
            {
                cnt = 0;
                s = line.Split(' ');
                n = int.Parse(s[0]);
                b = int.Parse(s[1]);
                c = int.Parse(s[2]);
                line = Console.ReadLine();
                s = line.Split(' ');
                for(i=0;i< n; i++)
                {
                    a[i] = int.Parse(s[i]);
                }
                for(i=0;i< n; i++)
                {
                    for(j=i+1;j< n; j++)
                    {
                        if (Math.Abs(a[i] - a[j]) % b == c) cnt++;
                    }
                }
                Console.WriteLine(cnt);
            }
        }
    }
}
