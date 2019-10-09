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
            //string my_string = "";
            //while (true)
            //{
            //    my_string = Console.ReadLine();
            //    if (my_string == "quit")
            //    {
            //        break;
            //    }
            //    else
            //    {
            //        //POPRAW w DOMU!!!!!!
            //        int length = my_string.Length;
            //       // if (my_string_heh == "+")
            //        if (my_string.Contains("+"))
            //        {
            //            int index_ = my_string.IndexOf('+');
            //            string my_string_one = my_string.Substring(0, index_);
            //         //   string my_string_heh = my_string.Substring(index_, index_- 1);
            //            string my_string_two = my_string.Substring(index_, (length - 2));
            //            int value_first = Int32.Parse(my_string_one);
            //            int value_second = Int32.Parse(my_string_two);
            //            int result = 0;
            //            result = (value_first + value_second);
            //            Console.WriteLine("Result: {0}", result);
            //        }
            //        if (my_string.Contains("-"))
            //        {
            //            int index_ = my_string.IndexOf('-');
            //            string my_string_one = my_string.Substring(0, index_);
            //            //   string my_string_heh = my_string.Substring(index_, index_- 1);
            //            string my_string_two = my_string.Substring(index_, (length - 2));
            //            int value_first = Int32.Parse(my_string_one);
            //            int value_second = Int32.Parse(my_string_two);
            //            int result = 0;
            //            result = (value_first - value_second);
            //            Console.WriteLine("Result: {0}", result);
            //        }
            //        if (my_string.Contains("*"))
            //        {
            //            int index_ = my_string.IndexOf('*');
            //            string my_string_one = my_string.Substring(0, index_);
            //            //   string my_string_heh = my_string.Substring(index_, index_- 1);
            //            string my_string_two = my_string.Substring(index_+1, (length - 2));
            //            int value_first = Int32.Parse(my_string_one);
            //            int value_second = Int32.Parse(my_string_two); 
            //            int result = 0;
            //            result = (value_first * value_second);
            //            Console.WriteLine("Result: {0}", result);
            //        }
            //        if (my_string.Contains("/"))
            //        {
            //            int index_ = my_string.IndexOf('/');
            //            string my_string_one = my_string.Substring(0, index_);
            //            //   string my_string_heh = my_string.Substring(index_, index_- 1);
            //            string my_string_two = my_string.Substring(index_+1, (length - 2));
            //            int value_first = Int32.Parse(my_string_one);
            //            int value_second = Int32.Parse(my_string_two); 
            //            int result = 0;
            //            result = (value_first / value_second);
            //            Console.WriteLine("Result: {0}", result);
            //        }
            //    }
            //    //int result = (value_first + value_second);
            //    //int result1 = (value_first - value_second);
            //    //int result2 = (value_first * value_second);
            //    //int result3 = (value_first / value_second);
            //    //    int result4 = (value_first + value_second);
            //  //  Console.WriteLine("Result: {0}", result1);
            //  //  Console.WriteLine("Result: {0}", result2);
            //  //  Console.WriteLine("Result: {0}", result3);
            //  ////  Console.WriteLine("Result: {0}", result);
            //}

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
                    //Console.WriteLine("{0}", sign_length);
                    if (sign.Contains("+"))
                    {
                        int index_ = sign.IndexOf('+');
                        //Console.WriteLine("{0}", index_);
                        Int32 value_first = Int32.Parse(sign.Substring(0, index_));
                        //Console.WriteLine("{0}", value_first);
                        Int32 value_second = Int32.Parse(sign.Substring(index_ + 1, (sign_length - index_ - 1)));
                        //Console.WriteLine("{0}", value_second);
                        Console.WriteLine("Result is following: {0}", (float)(value_first + value_second));
                    }
                    else if (sign.Contains("-"))
                    {
                        Int32 index_ = sign.IndexOf('-');
                        //Console.WriteLine("{0}", index_);
                        Int32 value_first = Int32.Parse(sign.Substring(0, index_));
                        //Console.WriteLine("{0}", value_first);
                        Int32 value_second = Int32.Parse(sign.Substring(index_ + 1, (sign_length - index_ - 1)));
                        //Console.WriteLine("{0}", value_second);
                        Console.WriteLine("Result is following: {0}", (float)(value_first - value_second));
                    }
                    else if (sign.Contains("*"))
                    {
                        Int32 index_ = sign.IndexOf('*');
                        //Console.WriteLine("{0}", index_);
                        Int32 value_first = Int32.Parse(sign.Substring(0, index_));
                        //Console.WriteLine("{0}", value_first);
                        Int32 value_second = Int32.Parse(sign.Substring(index_ + 1, (sign_length - index_ - 1)));
                        //Console.WriteLine("{0}", value_second);
                        Console.WriteLine("Result is following: {0}", (value_first * value_second));
                       // Console.WriteLine("Result is following: {0}", DoubleConverter.ToExactString(value_first * value_second));
                       // Console.WriteLine(String.Format("{0:0.00}","Result is following: {0}"), (value_first * value_second));
                    }
                    else if (sign.Contains("/"))
                    {
                        Int32 index_ = sign.IndexOf('/');
                        //Console.WriteLine("{0}", index_);
                        Int32 value_first = Int32.Parse(sign.Substring(0, index_));
                        //Console.WriteLine("{0}", value_first);
                        Int32 value_second = Int32.Parse(sign.Substring(index_ + 1, (sign_length - index_ - 1)));
                        //Console.WriteLine("{0}", value_second);
                        // Console.WriteLine("Result is following: {0}", (float)(value_first / value_second));
                        //Console.WriteLine(String.Format("{0:0.00}", "Result is following: {0}"), (float)(value_first / value_second));
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
            Console.WriteLine("The end of the program! Thanks for using!");
            Console.ReadKey();
            // Console.WriteLine("Hello World!");
        }
    }
}
