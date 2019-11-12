using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace _MY_PAGE.Models
{
    public class Marka_Pojazdu
    {
        public int ID { get; set; }
        public String Nazwa_Marka { get; set; }

        public virtual ICollection<Model_Pojazdu> Car_Models { get; set; }  //relation 1 TO ALL
    }
}