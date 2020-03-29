using System;
using System.Threading;
using System.Threading.Tasks;

namespace Horse_Race
{
    class Program
    {
        //static int value = 0;
        //static object obj = new object();
        //static Thread Print_Thread = new Thread(Print);
        //static Thread Increaser_Thread = new Thread(Increaser);
        //static Thread Increaser_Thread2 = new Thread(Increaser);
        //static Thread Increaser_Thread3 = new Thread(Increaser);
        //static Thread Checker_Thread = new Thread(Checker);
        //static void Main(string[] args)
        //{
        //    Sluzewiec Obj = new Sluzewiec(30);
        //    //Obj.Print();
        //    Obj.Start_Race();
        //    Obj.Print_Results();

        //    //Print_Thread.Start();
        //    //Increaser_Thread.Start();
        //    //Increaser_Thread2.Start();
        //    //Increaser_Thread3.Start();
        //    //Checker_Thread.Start();

        //}

        //static void Print()
        //{
        //    while (true)
        //    {
        //        lock (obj)
        //        {
        //            Console.WriteLine("Value: " + value);
        //        }
        //        Thread.Sleep(1000);
        //    }


        //}

        //static void Checker()
        //{
        //    while(true)
        //    {
        //        lock (obj)
        //        {
        //            if (value > 100)
        //            {
        //                Console.WriteLine("123123132132132 ");
        //                Increaser_Thread.IsBackground = true;
        //                Increaser_Thread2.IsBackground = true;
        //                Increaser_Thread3.IsBackground = true;
        //                Print_Thread.IsBackground = true;
        //                Checker_Thread.IsBackground = true;
        //            }
        //        }
        //    }
        //}

        //static void Increaser()
        //{
        //    while (true)
        //    {
        //        lock (obj)
        //        {
        //            //Console.WriteLine("Increased by Thread ID: " + Thread.CurrentThread.ManagedThreadId);
        //            value++;
        //        }
        //        Thread.Sleep(300);
        //    }

        //}

        //static Barrier barrier = new Barrier(5, b =>
        // Console.WriteLine("--- All horse have reached the barrier ---"));
        //static Random random = new Random();

        //static void Main()
        //{
        //    Task horse1 = Task.Run(() => Race("Horse1", random.Next(1, 100)));
        //    Task horse2 = Task.Run(() => Race("Horse2", random.Next(1, 100)));
        //    Task horse3 = Task.Run(() => Race("Horse3", random.Next(1, 100)));
        //    Task horse4 = Task.Run(() => Race("Horse4", random.Next(1, 100)));
        //    Task horse5 = Task.Run(() => Race("Horse5", random.Next(1, 100)));

        //    // this is solely here to stop the app closing until all threads have completed
        //    Task.WaitAll(horse1, horse2, horse3, horse4, horse5);
        //}

        //static void Race(string horse, int speed)
        //{
        //    int line = 1000000;
        //    Console.WriteLine(horse + " is at the start gate");
        //    barrier.SignalAndWait();

        //    // wait a random amount of time before the horse reaches the finish line
        //    Task.Delay(line);


        //    Console.WriteLine(horse + " reached finishing line");
        //    barrier.SignalAndWait();
        //}
        //static Barrier barrier = new Barrier(participantCount: 5);
        //static void Main(string[] args)
        //{
        //    Task[] tasks = new Task[5];

        //    for (int i = 0; i < 5; ++i)
        //    {
        //        int j = i;
        //        tasks[j] = Task.Factory.StartNew(() =>
        //        {
        //            GetDataAndStoreData(j);
        //        });
        //    }

        //    Task.WaitAll(tasks);

        //    Console.WriteLine("Backup completed");
        //    Console.ReadLine();


        //}

        //static void GetDataAndStoreData(int index)
        //{
        //    Console.WriteLine("Getting data from server: " + index);
        //    Thread.Sleep(TimeSpan.FromSeconds(2));

        //    int i = 0;
        //    while(i < 10000)
        //    {
        //        ++i;
        //    }

        //    barrier.SignalAndWait();

        //    Console.WriteLine("Send data to Backup server: " + index + " " +i );

        //    barrier.SignalAndWait();
        //}

        //static int[] Horses_Pos = new int[5];
        //static int[] Horses_Speed = new int[5];
        //static bool[] Success = new bool[5];
        //static int road_length = 100;
        //static Thread[] Horse_Threads = new Thread[5];
        //static bool suc = false;

        //static Barrier barrier = new Barrier(participantCount: 5, (a) =>
        //{
        //    bool if_break = true;
        //    for (int i = 0; i < Horses_Pos.Length; i++)
        //    {
        //        if (Horses_Pos[i] < road_length)
        //        {
        //            if_break = false;
        //            //Success[i] = true;
        //            Horse_Threads[i].IsBackground = true;
        //            Console.WriteLine("Horse number: " + (i + 1) + " | " + Horses_Pos[i]);
        //        }
        //    }

        //    if(if_break == true)
        //    {
        //        suc = true;
        //    }
        //});
        //static void Main(string[] args)
        //{
        //    Horses_Pos[0] = 0;
        //    Horses_Pos[1] = 0;
        //    Horses_Pos[2] = 0;
        //    Horses_Pos[3] = 0;
        //    Horses_Pos[4] = 0;

        //    Horses_Speed[0] = 2;
        //    Horses_Speed[1] = 4;
        //    Horses_Speed[2] = 3;
        //    Horses_Speed[3] = 6;
        //    Horses_Speed[4] = 1;

        //    Success[0] = false;
        //    Success[1] = false;
        //    Success[2] = false;
        //    Success[3] = false;
        //    Success[4] = false;


        //    Horse_Threads[0] = new Thread(() => Run_Horse(0));
        //    Horse_Threads[1] = new Thread(() => Run_Horse(1));
        //    Horse_Threads[2] = new Thread(() => Run_Horse(2));
        //    Horse_Threads[3] = new Thread(() => Run_Horse(3));
        //    Horse_Threads[4] = new Thread(() => Run_Horse(4));

        //    Horse_Threads[0].Start();
        //    Horse_Threads[1].Start();
        //    Horse_Threads[2].Start();
        //    Horse_Threads[3].Start();
        //    Horse_Threads[4].Start();

        //    for (int i = 0; i < Horses_Pos.Length; i++)
        //    {
        //        Horse_Threads[i].Join();
        //    }
        //    Console.WriteLine();
        //    for (int i = 0; i < Horses_Pos.Length; i++)
        //    {
        //        Console.WriteLine("Horse number: " + (i+1) + " | " +Horses_Pos[i] + " | " + Success[i]);
        //    }
        //}

        //private static void Run_Horse(object obj)
        //{
        //   // while (Success[Convert.ToInt32(obj)] == false)
        //    while (suc == false)
        //    {
        //        Horses_Pos[Convert.ToInt32(obj)] += Horses_Speed[Convert.ToInt32(obj)];
        //        //Console.WriteLine("Thread ID: " + Convert.ToInt32(obj));
        //        //Console.WriteLine("Horse number: " + (Convert.ToInt32(obj) + 1) + " | " + Horses_Pos[Convert.ToInt32(obj)]);
        //        barrier.SignalAndWait();
        //    }
        //}


        //static Barrier barrier = new Barrier(5, b => Console.WriteLine("--- All horse have reached the barrier ---"));
        //static Random random = new Random();

        //static void Main()
        //{
        //    Task horse1 = Task.Run(() => Race("Horse1", random.Next(1, 1000)));
        //    Task horse2 = Task.Run(() => Race("Horse2", random.Next(1, 1000)));
        //    Task horse3 = Task.Run(() => Race("Horse3", random.Next(1, 1000)));
        //    Task horse4 = Task.Run(() => Race("Horse4", random.Next(1, 1000)));
        //    Task horse5 = Task.Run(() => Race("Horse5", random.Next(1, 1000)));

        //    // this is solely here to stop the app closing until all threads have completed
        //    Task.WaitAll(horse1, horse2, horse3, horse4, horse5);
        //}

        //static void Race(string horse, int speed)
        //{
        //    Console.WriteLine(horse + " is at the start gate" + " " + speed);
        //    barrier.SignalAndWait();

        //    // wait a random amount of time before the horse reaches the finish line
        //    Task.Delay(speed);
        //    Console.WriteLine(horse + " reached finishing line");
        //    barrier.SignalAndWait();
        //}


        static Barrier _barrier = new Barrier(3, b => Console.WriteLine());

        static int[] arr = new int[3];

        static void Main()
        {
            arr[0] = 1;
            arr[1] = 2;
            arr[2] = 3;
            var t = new Thread(Speak); t.Start(0);
            var t1 = new Thread(Speak); t1.Start(1);
            var t2 = new Thread(Speak); t2.Start(2);
        }

        static void Speak(object obj)
        {
            //for (int i = 0; i < 5; i++)
            //{
            //    Console.Write(i + " ");
            //    _barrier.SignalAndWait();
            //}
            while (arr[Convert.ToInt32(obj)] < 15)
            {
                Console.WriteLine("Value: " + arr[Convert.ToInt32(obj)] + " | Object numer: " + obj);
                if (Convert.ToInt32(obj) == 0)
                {
                    arr[Convert.ToInt32(obj)] += 4;

                }
                else
                {
                    arr[Convert.ToInt32(obj)] += Convert.ToInt32(obj);
                }
                Thread.Sleep(1000);
                _barrier.SignalAndWait();
            }
            Console.WriteLine("Value: " + arr[Convert.ToInt32(obj)] + " | Object numer: " + obj);

            _barrier.RemoveParticipant();

        }
    }
}
