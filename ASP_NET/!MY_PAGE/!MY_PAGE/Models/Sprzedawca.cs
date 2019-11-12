using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace _MY_PAGE.Models
{
    public class Sprzedawca
    {
        public int ID { get; set; }
        public String Imie { get; set; }
        public String Nazwiska { get; set; }
        public int Pesel { get; set; }

        public virtual ICollection<Model_Pojazdu> Car_Models { get; set; }  //relation 1 TO ALL

    }
}