using System;
using System.Collections.Generic;
using System.Text;

namespace First
{
    class SingleThreadAction
    {
        Counter counter;
        public SingleThreadAction(Counter counter)
        {
            this.counter = counter;
        }

        public void Do()
        {
            for (int i = 0; i < 40; ++i)
            {
                lock (counter)
                {
                    counter.Increment();
                }
            }
        }
    }
}