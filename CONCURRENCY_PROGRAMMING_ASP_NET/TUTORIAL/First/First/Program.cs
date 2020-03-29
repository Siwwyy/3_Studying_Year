//using System;
//using System.Threading;

//namespace First
//{
//    class Program
//    {
//        static void Main(string[] args)
//        {
//            Thread th = Thread.CurrentThread;
//            th.Name = "MainThread";

//            Console.WriteLine("This is {0}", th.Name);
//            Console.ReadKey();
//        }
//    }
//}

using System;
using System.Threading;

public class Program
{
	public static void Main()
	{
		for (int i = 0; i < Environment.ProcessorCount; ++i)
		{
			var thread = new Thread(DifferentMethod);
			thread.IsBackground = true;
			thread.Start(i);
		}
		Console.WriteLine("Leaving Main");
	}

	static void DifferentMethod(object threadID)
	{
		int i = 0;
		//while (i < 10)
		while(true)
		{
			Console.WriteLine("Hello from different metodd: {0} ", threadID);

			++i;
		}
	}
}
