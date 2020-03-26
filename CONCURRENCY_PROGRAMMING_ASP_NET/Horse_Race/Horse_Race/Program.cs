using System;
using System.Threading;

namespace Horse_Race
{
    class Program
    {
        static void Main(string[] args)
        {
            Sluzewiec Obj = new Sluzewiec(300);
            //Obj.Print();
            Obj.Start_Race();
        }
    }
}
