using System;

namespace First_Application
{
    class Program
    {
        static void Main(string[] args)
        {
            string sign = default;
            while(true)
            {
                sign = Console.ReadLine();
                if (sign == "quit")
                {
                    break;
                }
                else
                {
                    Int32 sign_length = sign.Length;
                    if (sign.Contains("+"))
                    {
                        int index_ = sign.IndexOf('+');
                        Int32 value_first = Int32.Parse(sign.Substring(0, index_));
                        Int32 value_second = Int32.Parse(sign.Substring(index_ + 1, (sign_length - index_ - 1)));
                        Console.WriteLine("Result is following: {0}", (float)(value_first + value_second));
                    }
                    else if (sign.Contains("-"))
                    {
                        Int32 index_ = sign.IndexOf('-');
                        Int32 value_first = Int32.Parse(sign.Substring(0, index_));
                        Int32 value_second = Int32.Parse(sign.Substring(index_ + 1, (sign_length - index_ - 1)));
                        Console.WriteLine("Result is following: {0}", (float)(value_first - value_second));
                    }
                    else if (sign.Contains("*"))
                    {
                        Int32 index_ = sign.IndexOf('*');
                        Int32 value_first = Int32.Parse(sign.Substring(0, index_));
                        Int32 value_second = Int32.Parse(sign.Substring(index_ + 1, (sign_length - index_ - 1)));
                        Console.WriteLine("Result is following: {0}", (value_first * value_second));
                    }
                    else if (sign.Contains("/"))
                    {
                        Int32 index_ = sign.IndexOf('/');
                        Int32 value_first = Int32.Parse(sign.Substring(0, index_));
                        Int32 value_second = Int32.Parse(sign.Substring(index_ + 1, (sign_length - index_ - 1)));
                        Console.WriteLine("Result is following: {0:F3}", (((float)value_first) / ((float)value_second)));
                    }
                    else
                    {
                        //to do something later
                        continue;
                    }
                }
                sign = default;
            }

            Console.WriteLine("Time to show small kind of usage the classes in C#!");

            My_Class Obj = new My_Class("XYZ", "ZYX");
            Console.WriteLine("{0}", Obj.Name_Property);
            Console.WriteLine("{0}", Obj.Surname_Property);
            Obj.Name_Property = "Hello";
            Obj.Surname_Property = "World";
            Console.WriteLine("{0}", Obj.Name_Property);
            Console.WriteLine("{0}", Obj.Surname_Property);

            Console.WriteLine("{0}", Obj.Get_Name());
            Console.WriteLine("{0}", Obj.Get_Surname());

            Obj.Set_Name("University of");
            Obj.Set_Surname("Lodz");

            Console.WriteLine("{0} {1}", Obj.Get_Name(), Obj.Get_Surname());
            Console.WriteLine("\n");

            Console.WriteLine("The end of the program! Thanks for using!");
            Console.ReadKey();
        }
    }
}
