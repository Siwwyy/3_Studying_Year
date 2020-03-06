using System;
using System.Collections.Generic;
using System.Text;

namespace Counters
{
    class BadSingleThread
    {
        private Counter c;

        public BadSingleThread(Counter c)
        {
            this.c = c;
        }
        public void Action()
        {
            for (int i = 0; i < 40; i++)
            {
                //DO SOMETHING
                lock (c) //this)
                {
                    c.Add();
                }
                //DO SOMETHING
            }
        }
    }
}
