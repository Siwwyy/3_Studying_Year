using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace _MY_PAGE.Models
{
    public class Informacje_w_ogloszeniu
    {
        public int ID { get; set; }
        public int Model_ID { get; set; }
        public int Cena { get; set; }
        public int Przebieg_od { get; set; }
        public int Przebieg_do { get; set; }
        public int Moc_Silnika { get; set; }

        //public virtual Model_Pojazdu Model { get; set; }


    }
}