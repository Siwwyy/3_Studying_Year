using System;
using System.Collections.Generic;
using System.Text;

namespace PostOffice
{
    class PostOffice
    {
        List<Clerk> allClercks;

        public PostOffice()
        {
            allClercks.Add(new Clerk("A"));
            allClercks.Add(new Clerk("B"));
            allClercks.Add(new Clerk("C"));
        }

        public void serveMe(Client client)
        {
            //Czekaj na swoją kolej
            //Wybor urzędnika odpowiedniego do klienta
            Clerk c = nextClerk();
            c.serve(client);
        }

        private Clerk nextClerk()
        {
            throw new NotImplementedException();
        }
    }
}
