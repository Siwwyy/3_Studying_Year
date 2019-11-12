using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace _MY_PAGE.Models
{
    public class Model_Pojazdu
    {
        public int ID { get; set; }
        public int Marka_ID { get; set; }
        public int Kraj_Pochodzenia_ID { get; set; }
        public int Sprzedawca_ID { get; set; }
        public int Rodzaj_Paliwa_ID { get; set; }
        public String Nazwa_Model { get; set; }


        public virtual Marka_Pojazdu Marka { get; set; }
        public virtual Rodzaj_Paliwa Fuel_Type { get; set; }
        public virtual Sprzedawca Seller { get; set; }
        public virtual Kraj_Pochodzenia Country_Of_Origin { get; set; }
        public virtual Informacje_w_ogloszeniu Informations { get; set; }

    }
}