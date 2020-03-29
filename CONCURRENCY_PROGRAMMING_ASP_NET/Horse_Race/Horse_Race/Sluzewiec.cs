using System;
using System.Threading;
using System.Collections.Generic;
using System.Text;

namespace Horse_Race
{
    class Sluzewiec
    {
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PRIVATE VARIABLES
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        Horse[] Horse_Participants;
        String[] Placement;
        Thread[] Threads;
        Thread Print_Thread;
        Barrier Barrier;
        Road Road;
        Int32 road_size;

        //LOCKERS
        object Print_Locker = new object();
        object Position_Locker = new object();
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
            while (true)
            {
                lock (Print_Locker)
                {
                    Console.Clear();
                }
                for (UInt32 i = 0; i < (UInt32)Horse_Participants.Length; ++i)
                {
                    lock (Print_Locker)
                    {
                        lock (Position_Locker)
                        {
                            for (UInt32 j = 0; j < (UInt32)Horse_Participants[i].Position; ++j)
                            {
                                Console.Write("-");
                            }
                            Console.Write(" => {0} {1}", Horse_Participants[i].Horse_Name, Horse_Participants[i].Position);
                        }
                        Console.Write("\n");
                    }
                }
                Thread.Sleep(500);
            }

        }

        private void Race()
        {
            while (true)
            {
                for (UInt32 i = 0; i < this.Threads.Length; ++i)
                {
                    lock (Position_Locker)
                    {
                        if (this.Horse_Participants[i].Position >= this.road_size)
                        {
                            //TO DO SOMETHING
                            if (this.Threads[i].IsBackground != true)
                            {
                                this.Threads[i].IsBackground = true;
                            }
                        }
                    }
                }
            }
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
            this.Placement = new String[Horse_Participants.Length];
            this.Barrier = new Barrier(participantCount: Horse_Participants.Length);
            this.Road = new Road();
            this.road_size = 1000;

            Threads = new Thread[this.Horse_Participants.Length];
            for (UInt32 i = 0; i < this.Horse_Participants.Length; ++i)
            {
                Threads[i] = new Thread(this.Horse_Participants[i].Run);
            }
        }
        public Sluzewiec(Int32 road_size)
        {
            Initialize_Horse_Participants();
            this.Placement = new String[Horse_Participants.Length];
            this.Barrier = new Barrier(participantCount: Horse_Participants.Length);
            this.Road = new Road(road_size);
            this.road_size = road_size;

            Threads = new Thread[this.Horse_Participants.Length];
            for (UInt32 i = 0; i < this.Horse_Participants.Length; ++i)
            {
                Threads[i] = new Thread(this.Horse_Participants[i].Run);
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
            while (true)
            {
                lock (Print_Locker)
                {
                    for (UInt32 i = 0; i < (UInt32)Horse_Participants.Length; ++i)
                    {
                        Horse_Participants[i].Print();
                    }
                }

                Thread.Sleep(500);
                lock (Print_Locker)
                {
                    Console.Clear();
                }
            }
        }

        public void Start_Race()
        {
            UInt32 placement_counter = 0;



            Print_Thread = new Thread(Print_Roads);
            Thread Race_Thread = new Thread(Race);
            Race_Thread.Start();
            Print_Thread.Start();
            for (UInt32 i = 0; i < this.Threads.Length; ++i)
            {
                Threads[i].Start(Position_Locker);
            }


            Race_Thread.Join(); //wait until this thread end own work





            this.Barrier.Dispose();
        }

        public void Print_Results()
        {
            Console.Clear();
            Console.WriteLine("Placement is following ");
            for (UInt32 i = 0; i < (UInt32)Placement.Length; ++i)
            {
                Console.WriteLine("Place {0} takes horse {1}", (i + 1), this.Placement[i]);
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
