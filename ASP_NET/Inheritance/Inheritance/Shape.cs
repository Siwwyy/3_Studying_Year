using System;
using System.Collections.Generic;
using System.Text;

namespace Inheritance
{
    public class Shape
    {
        protected int x;
        protected int y;

        public Shape()
        {
            this.x = 0;
            this.y = 0;
        }

        public void Show()
        {
            Console.WriteLine("{0} {1}",this.x, this.y);
        }

        public int Get_X()
        {
            return this.x;
        }

        public int Get_Y()
        {
            return this.y;
        }
    }


    public class Point : Shape
    {
        public Point():base()
        {
            this.x = 1;
            this.y = 2;
        }
    }


    public class Rectangle : Shape, Polygon
    {
        public Rectangle() : base()
        {
            this.x = 2;
            this.x = 3;
        }

        int Polygon.Area()
        {
            throw new NotImplementedException();
            return (int)(this.x * this.y);
        }

        int Polygon.Perimeter()
        {
            throw new NotImplementedException();
            return (int)((2*this.x) + (2*this.y));

        }
    }


    public class Triangle : Shape, Polygon
    {
        public Triangle() : base()
        {
            this.x = 3;
            this.x = 4;
        }

        int Polygon.Area()
        {
            throw new NotImplementedException();
            return ((int)(0.5 * this.x) * this.y);
        }

        int Polygon.Perimeter()
        {
            throw new NotImplementedException();
            return (int)(this.x+this.y);

        }
    }
}
