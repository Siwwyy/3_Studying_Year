using System;

namespace Inheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");
            //Shape A = new Point();
            //A.Show();
            //Shape B = new Rectangle();
            //B.Show();
            //Shape C = new Triangle();
            //C.Show();

            Shape[] Shapes = new Shape[6];
            Shapes[0] = new Point();
            Shapes[1] = new Rectangle();
            Shapes[2] = new Triangle();
            Shapes[3] = new Point();
            Shapes[4] = new Rectangle();
            Shapes[5] = new Triangle();

            for(int i =0; i < 6; ++i)
            {
                //if(Shapes[i] is Shape)
                if(Shapes[i] is Polygon)    //if this object in shape is connected with interface Polygon, will be displayed
                {
                    Shapes[i].Show();
                }
            }
        }
    }
}
