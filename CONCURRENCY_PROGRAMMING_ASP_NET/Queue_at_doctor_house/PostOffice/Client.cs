using System;
using System.Collections.Generic;
using System.Text;

namespace PostOffice
{
    class Client
    {
        public int Id { get; set; }

        private PostOffice postOffice;

        public Client(int id, PostOffice po)
        {
            this.Id = id;
            this.postOffice = po;
        }

        public void Task()
        {
            Console.WriteLine("Klient " + this + " wchodzi na pocztę");
            postOffice.serveMe(this);
            Console.WriteLine("Klient " + this + " idzie do domu");
        }

        override public String ToString()
        {
            return Id.ToString();
        }


    }
}
