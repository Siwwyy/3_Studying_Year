using System;

namespace Temp_Horse_Race
{



    class Program
    {
        static void Main(string[] args)
        {
            Sluzewiec Sluzewiec = new Sluzewiec(15);
            Sluzewiec.Start_Race();
            Sluzewiec.Print_Results();
        }
    }
}
