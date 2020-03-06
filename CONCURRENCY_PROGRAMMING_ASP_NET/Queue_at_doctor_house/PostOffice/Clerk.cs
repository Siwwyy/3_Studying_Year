using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace PostOffice
{
    class Clerk
    {
        public string Name { get; set; }
        private Random rand = new Random();
       
        public Clerk(string v)
        {
            this.Name = v;
        }

        public void serve(Client c)
        {
            //Możemy założyć lock, kto jest monitorem ?
            Console.WriteLine("Urzędnik " + Name + " obsługuje klineta " + c);
            // Różny czas czekania dla różnych spraw
            Thread.Sleep(rand.Next() % 500);
        }
    }
}
