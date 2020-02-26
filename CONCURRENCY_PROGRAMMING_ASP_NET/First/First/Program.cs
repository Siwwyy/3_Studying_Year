using System;
using System.Threading;

namespace First
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");
            Counter Obj = new Counter();
            SingleThreadAction Sta = new SingleThreadAction(Obj);
            Mutex mutex = new Mutex();


            for (int i = 0; i < 1000; ++i)
            {
                Thread t = new Thread(Sta.Do);
                //mutex.WaitOne();
                t.Start();  //how to initialize thread system
                //then use t.Run();
                //t.Join();
                //mutex.ReleaseMutex();
            }
            // Thread.Sleep(3000);
            Console.WriteLine("Value: {0}", Obj.Get_Value());
        }
    }
}


//using System;
//using System.Threading;
//namespace JoinDemo
//{
//    class First
//    {
//        static void Main(string[] args)
//        {
//            Thread t1 = new Thread(Func1);
//            t1.Start();
//            Thread t2 = new Thread(Func2);
//            t2.Start();
//            t1.Join();
//            t2.Join();
//        }
//        private static void Func2(object obj)
//        {
//            Console.WriteLine("Thread 2 is executed");
//        }
//        private static void Func1(object obj)
//        {
//            Console.WriteLine("Thread 1 is executed");
//        }
//    }
//}