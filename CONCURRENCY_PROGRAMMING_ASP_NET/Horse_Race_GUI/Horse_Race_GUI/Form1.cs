using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace Horse_Race_GUI
{
    public partial class Form1 : Form
    { /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PRIVATE VARIABLES
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        Horse[] Horse_Participants;
        List<String> list;
        Thread[] Threads;
        Barrier Barrier;
        Int32 road_size;
        ProgressBar[] progressBars;

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
            Horse_Participants[0] = new Horse("Mark 1", Get_Random_Value(1, 10));
            Horse_Participants[1] = new Horse("Henry 2", Get_Random_Value(1, 10));
            Horse_Participants[2] = new Horse("Peter 3", Get_Random_Value(1, 10));
            Horse_Participants[3] = new Horse("Oliver 4", Get_Random_Value(1, 10));
            Horse_Participants[4] = new Horse("Marcus 5", Get_Random_Value(1, 10));
        }
        static Random rand = new Random();
        private Int32 Get_Random_Value(int beginning, int end)
        {

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
                lock (Position_Locker)
                {
                    Horse_Participants[Convert.ToUInt32(index)].Make_Move();
                }
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
        public Form1()
        {
            InitializeComponent();
            Initialize_Horse_Participants();
            this.Barrier = new Barrier(participantCount: Horse_Participants.Length);
            this.road_size = 1000;
            this.list = new List<String>();

            Threads = new Thread[this.Horse_Participants.Length];
            for (UInt32 i = 0; i < this.Horse_Participants.Length; ++i)
            {
                Threads[i] = new Thread(Run);
            }

            this.progressBars = new ProgressBar[5];
            progressBars[0] = progressBar1;
            progressBars[1] = progressBar2;
            progressBars[2] = progressBar3;
            progressBars[3] = progressBar4;
            progressBars[4] = progressBar5;

            for (UInt32 i = 0; i < (UInt32)progressBars.Length; ++i)
            {
                progressBars[i].Maximum = this.road_size;
            }
        }
        public Form1(Int32 road_size)
        {
            InitializeComponent();
            Initialize_Horse_Participants();
            this.road_size = road_size;
            this.list = new List<String>();
            this.Barrier = new Barrier(participantCount: Horse_Participants.Length);

            Threads = new Thread[this.Horse_Participants.Length];
            for (UInt32 i = 0; i < this.Horse_Participants.Length; ++i)
            {
                Threads[i] = new Thread(Run);
            }

            this.progressBars = new ProgressBar[5];
            progressBars[0] = progressBar1;
            progressBars[1] = progressBar2;
            progressBars[2] = progressBar3;
            progressBars[3] = progressBar4;
            progressBars[4] = progressBar5;

            for (UInt32 i = 0; i < (UInt32)progressBars.Length; ++i)
            {
                progressBars[i].Maximum = this.road_size;
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
            for (UInt32 i = 0; i < this.Threads.Length; ++i)
            {
                Threads[i].Start(i);
            }
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

        private void Form1_Load(object sender, EventArgs e)
        {
            //Start_Race();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Start_Race();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            for (UInt32 i = 0; i < (UInt32)Horse_Participants.Length; ++i)
            {
                if (Horse_Participants[i].Position <= this.progressBars[i].Maximum)
                {
                    lock (Position_Locker)
                    {
                        this.progressBars[i].Value = Horse_Participants[i].Position;
                    }
                }
                else
                {
                    this.progressBars[i].Value = this.progressBars[i].Maximum;
                }
            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            for (UInt32 i = 0; i < this.Threads.Length; ++i)
            {
                if (Threads[i].IsAlive == true)
                {
                    Threads[i].IsBackground = true;
                }
            }
        }
    }
}
