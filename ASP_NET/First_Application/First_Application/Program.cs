using System;

namespace First_Application
{
    class Program
    {
        static void Main(string[] args)
        {
        //    Console.WriteLine("Please enter the First Name");
        //    Console.WriteLine("Please enter the Last Name");
        //    string LastName = Console.ReadLine();
        //    Console.WriteLine("Hello {0} {1} !!!", FirstName, LastName);
            string my_string = "";
            while (true)
            {
                my_string = Console.ReadLine();
                if (my_string == "quit")
                {
                    break;
                }
                else
                {
                    //POPRAW w DOMU!!!!!!
                    int length = my_string.Length;
                   // if (my_string_heh == "+")
                    if (my_string.Contains("+"))
                    {
                        int index_ = my_string.IndexOf('+');
                        string my_string_one = my_string.Substring(0, index_);
                     //   string my_string_heh = my_string.Substring(index_, index_- 1);
                        string my_string_two = my_string.Substring(index_, (length - 2));
                        int value_first = Int32.Parse(my_string_one);
                        int value_second = Int32.Parse(my_string_two);
                        int result = 0;
                        result = (value_first + value_second);
                        Console.WriteLine("Result: {0}", result);
                    }
                    if (my_string.Contains("-"))
                    {
                        int index_ = my_string.IndexOf('-');
                        string my_string_one = my_string.Substring(0, index_);
                        //   string my_string_heh = my_string.Substring(index_, index_- 1);
                        string my_string_two = my_string.Substring(index_, (length - 2));
                        int value_first = Int32.Parse(my_string_one);
                        int value_second = Int32.Parse(my_string_two);
                        int result = 0;
                        result = (value_first - value_second);
                        Console.WriteLine("Result: {0}", result);
                    }
                    if (my_string.Contains("*"))
                    {
                        int index_ = my_string.IndexOf('*');
                        string my_string_one = my_string.Substring(0, index_);
                        //   string my_string_heh = my_string.Substring(index_, index_- 1);
                        string my_string_two = my_string.Substring(index_+1, (length - 2));
                        int value_first = Int32.Parse(my_string_one);
                        int value_second = Int32.Parse(my_string_two); 
                        int result = 0;
                        result = (value_first * value_second);
                        Console.WriteLine("Result: {0}", result);
                    }
                    if (my_string.Contains("/"))
                    {
                        int index_ = my_string.IndexOf('/');
                        string my_string_one = my_string.Substring(0, index_);
                        //   string my_string_heh = my_string.Substring(index_, index_- 1);
                        string my_string_two = my_string.Substring(index_+1, (length - 2));
                        int value_first = Int32.Parse(my_string_one);
                        int value_second = Int32.Parse(my_string_two); 
                        int result = 0;
                        result = (value_first / value_second);
                        Console.WriteLine("Result: {0}", result);
                    }
                }
                //int result = (value_first + value_second);
                //int result1 = (value_first - value_second);
                //int result2 = (value_first * value_second);
                //int result3 = (value_first / value_second);
                //    int result4 = (value_first + value_second);
              //  Console.WriteLine("Result: {0}", result1);
              //  Console.WriteLine("Result: {0}", result2);
              //  Console.WriteLine("Result: {0}", result3);
              ////  Console.WriteLine("Result: {0}", result);
            }

            Console.ReadKey();
            // Console.WriteLine("Hello World!");
        }
    }
}
