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
            string line;
            string[] s = new string[110];
            int[] a = new int[110];
            int n, m, i, j, k;
            while ((line = Console.ReadLine()) != null)
            {
                BigInteger[,] dp = new BigInteger[105, 105];
                s = line.Split(' ');
                n = int.Parse(s[0]);
                m = int.Parse(s[1]);
                line = Console.ReadLine();
                s = line.Split(' ');
                for (i = 0; i < n; i++)
                {
                    a[i] = int.Parse(s[i]);
                    dp[i,1] = 1;
                }
                for(i=2;i<= m; i++)
                {
                    for(j=i-1;j< n; j++)
                    {
                        dp[j, i] = 0;
                        for(k=0;k< j; k++)
                        {
                            if (a[k] < a[j])
                            {
                                dp[j, i] = dp[j, i] + dp[k, i - 1];
                            }
                        }
                    }
                }
                BigInteger ans = 0;
                for(i=0;i< n; i++)
                {
                    ans = ans + dp[i, m];
                }
                Console.WriteLine(ans);
            }
        }
    }
}
