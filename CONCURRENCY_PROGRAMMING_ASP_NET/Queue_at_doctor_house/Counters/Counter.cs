using System;
using System.Collections.Generic;
using System.Text;

namespace Counters
{
    class Counter
    {
        //volatile 
        private int value;

        public void Add()
        {
            //lock (this) { //Działa dobrze dla SIingleThread
                //int v = value;
                //v = v + 1;
                //value = v;
                value++;
            //}
        }

        public int State()
        {
            return value;
        }
    }
}
