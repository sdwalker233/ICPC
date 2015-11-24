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
            string[] s = new string[10];
            int y, m, d;
            while ((line = Console.ReadLine()) != null)
            {
                DateTime Date1,Date2;
                s = line.Split('/');
                y = int.Parse(s[0]);
                m = int.Parse(s[1]);
                d = int.Parse(s[2]);
                Date1 = new DateTime(y, m, d);
                Date2 = new DateTime(y, 1, 1);
                TimeSpan x = Date1 - Date2;
                Console.WriteLine("{0}", x.Days + 1);
            }
        }
    }
}
