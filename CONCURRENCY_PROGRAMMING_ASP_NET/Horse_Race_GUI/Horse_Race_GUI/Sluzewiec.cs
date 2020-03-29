using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Horse_Race_GUI
{
    class Sluzewiec
    {
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PRIVATE VARIABLES
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        Horse[] Horse_Participants;
        List<String> list;
        Thread[] Threads;
        Thread Print_Thread;
        Barrier Barrier;
        Int32 road_size;

        //LOCKERS
        object Name_Locker = new object();
        object Position_Locker = new object();
        object Console_Locker = new object();
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PRIVATE FUNCTIONS
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        private void Initialize_Horse_Participants()
        {
            Horse_Participants = new Horse[5];
            Horse_Participants[0] = new Horse("Mark 1", Get_Random_Value(1, 6));
            Horse_Participants[1] = new Horse("Henry 2", Get_Random_Value(1, 6));
            Horse_Participants[2] = new Horse("Peter 3", Get_Random_Value(1, 6));
            Horse_Participants[3] = new Horse("Oliver 4", Get_Random_Value(1, 6));
            Horse_Participants[4] = new Horse("Marcus 5", Get_Random_Value(1, 6));
        }

        private Int32 Get_Random_Value(int beginning, int end)
        {
            Random rand = new Random();
            return (Int32)(rand.Next(beginning, end));
        }

        private void Print_Roads()
        {
            while (Thread.CurrentThread.IsBackground == false)
            {
                lock (Console_Locker)
                {
                    for (UInt32 i = 0; i < (UInt32)Horse_Participants.Length; ++i)
                    {
                        for (UInt32 j = 0; j < (UInt32)Horse_Participants[i].Position; ++j)
                        {
                           // Console.Write("-");
                        }
                        lock (Name_Locker)
                        {
                            //Console.Write(" => {0} {1}", Horse_Participants[i].Horse_Name, Horse_Participants[i].Position);

                        }
                        //Console.Write("\n");
                    }
                    Thread.Sleep(300);
                    //Console.Clear();
                }
            }
        }

        private void Run(object index)
        {
            while (Horse_Participants[Convert.ToUInt32(index)].Position < this.road_size)
            {
                Horse_Participants[Convert.ToUInt32(index)].Make_Move();
                Thread.Sleep(300);
                this.Barrier.SignalAndWait();
            }
            lock (Name_Locker)
            {
                list.Add(Horse_Participants[Convert.ToUInt32(index)].Horse_Name);
            }
            this.Barrier.RemoveParticipant();
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PUBLIC CONSTRUCTORS
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        public Sluzewiec()
        {
            Initialize_Horse_Participants();
            this.Barrier = new Barrier(participantCount: Horse_Participants.Length);
            this.road_size = 1000;
            this.list = new List<String>();

            Threads = new Thread[this.Horse_Participants.Length];
            for (UInt32 i = 0; i < this.Horse_Participants.Length; ++i)
            {
                Threads[i] = new Thread(Run);
            }
        }
        public Sluzewiec(Int32 road_size)
        {
            Initialize_Horse_Participants();
            this.road_size = road_size;
            this.list = new List<String>();
            this.Barrier = new Barrier(participantCount: Horse_Participants.Length);

            Threads = new Thread[this.Horse_Participants.Length];
            for (UInt32 i = 0; i < this.Horse_Participants.Length; ++i)
            {
                Threads[i] = new Thread(Run);
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PUBLIC SETTERS
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PUBLIC FUNCTIONS
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        public void Print()
        {
            for (UInt32 i = 0; i < (UInt32)Horse_Participants.Length; ++i)
            {
                Horse_Participants[i].Print();
            }
        }

        public void Start_Race()
        {
            Print_Thread = new Thread(Print_Roads);
            Print_Thread.Start();
            for (UInt32 i = 0; i < this.Threads.Length; ++i)
            {
                Threads[i].Start(i);
            }
            for (UInt32 i = 0; i < this.Threads.Length; ++i)
            {
                Threads[i].Join();
            }
            Print_Thread.IsBackground = true;
        }

        public void Print_Results()
        {
            lock (Console_Locker)
            {
                //Console.Clear();
                //Console.WriteLine("Placement is following ");
                int i = 0;
                foreach (var horse_placement in list)
                {
                   // Console.WriteLine("Place {0} takes horse {1}", (i + 1), horse_placement);
                    ++i;
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PUBLIC OPERATORS
		*/
        //UNARY

        //BINARY

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PUBLIC GETTERS
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PUBLIC PROPERTIES
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////
    }
}
