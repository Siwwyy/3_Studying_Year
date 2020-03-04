using System;
using System.Collections.Generic;
using System.Text;

namespace Counters
{
    class SingleThread
    {
        private Counter c;

        public SingleThread(Counter c)
        {
            this.c = c;
        }
        public void Action()
        {
            //Console.WriteLine("START");
            for (int i=0; i< 40; i++)
            {
                //DO SOMETHING
                c.Add();
                //DO SOMETHING
            }
        }
    }
}
