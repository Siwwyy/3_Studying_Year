using System;
using System.Collections.Generic;
using System.Text;

namespace First
{
    class Counter
    {
        private int value;
        public Counter()
        {
            this.value = 0;
        }

        public void Increment()
        {
           // lock(this)
           // {
                ++this.value;
           // }
        }

        public int Get_Value()
        {
            return this.value;
        }
    }
}
