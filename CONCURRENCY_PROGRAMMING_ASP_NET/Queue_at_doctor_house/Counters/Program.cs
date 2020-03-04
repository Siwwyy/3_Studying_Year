using System;
using System.Threading;

namespace Counters
{
    class Program
    {
        static void Main(string[] args)
        {
            Counter counter = new Counter();
            
            for (int i = 0; i < 1000; i++)
            {
                BadSingleThread st = new BadSingleThread(counter);
                Thread t = new Thread(st.Action);
                t.Start();
                t = new Thread(() =>
                {
                    for (int i = 0; i < 40; i++)
                    {
                        lock (counter)
                        {
                            counter.Add();
                        }
                    }
                });
                t.Start();
            }

            Thread.Sleep(3000);
            Console.WriteLine(counter.State());

        }
    }
}
