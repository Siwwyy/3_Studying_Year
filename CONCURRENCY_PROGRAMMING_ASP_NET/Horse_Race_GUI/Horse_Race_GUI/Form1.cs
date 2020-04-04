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
        List<String> list_injury;
        Thread[] Threads;
        Barrier Barrier;
        Int32 road_size;
        ProgressBar[] progressBars;
        bool end_race = false;
        static Random rand = new Random();
        //LOCKERS
        object Name_Locker = new object();
        object Position_Locker = new object();
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

        private Int32 Get_Random_Value(int beginning, int end)
        {
            return (Int32)(rand.Next(beginning, end));
        }

        private void Run(object index)
        {
            while (Horse_Participants[Convert.ToUInt32(index)].Position < this.road_size && Horse_Participants[Convert.ToUInt32(index)].injury == false)
            {
                if (Get_Random_Value(1, 30) == 5)
                {
                    Horse_Participants[Convert.ToUInt32(index)].injury = true;
                }
                else
                {
                    Horse_Participants[Convert.ToUInt32(index)].Make_Move();
                }
                Thread.Sleep(300);
                this.Barrier.SignalAndWait();
            }
            lock (Name_Locker)
            {
                if (Horse_Participants[Convert.ToUInt32(index)].injury == true)
                {
                    list_injury.Add(Horse_Participants[Convert.ToUInt32(index)].Horse_Name);
                    this.Threads[Convert.ToUInt32(index)].IsBackground = true;
                }
                else
                {
                    list.Add(Horse_Participants[Convert.ToUInt32(index)].Horse_Name);
                }
                if (list.Count + list_injury.Count == Horse_Participants.Length)
                {
                    this.end_race = true;
                }
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
            this.list_injury = new List<String>();

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
            this.list_injury = new List<String>();
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
            this.timer1.Enabled = true;
            for (UInt32 i = 0; i < this.Threads.Length; ++i)
            {
                Threads[i].Start(i);
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
            this.button2.Enabled = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.button1.Enabled = false;
            this.button2.Enabled = true;
            Start_Race();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (end_race == false)
            {
                this.button2.Enabled = false;
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
            else
            {
                int i = 0;
                foreach (var horse_placement in list)
                {
                    String temp = "Place " + (i + 1) + " takes horse " + horse_placement + '\n';
                    placement_textbox.Text += temp;
                    ++i;
                }
                foreach (var horse_injury in list_injury)
                {
                    String temp = "Injuried horeses " + horse_injury + '\n';
                    placement_textbox.Text += temp;
                    Console.WriteLine("Injuried horeses: {0}", horse_injury);
                }
                this.timer1.Enabled = false;
                this.button2.Enabled = true;
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

        private void button2_Click(object sender, EventArgs e)
        {
            placement_textbox.Text = "";
            this.timer1.Enabled = false;
            for (UInt32 i = 0; i < this.Horse_Participants.Length; ++i)
            {
                lock (Position_Locker)
                {
                    Horse_Participants[i].Position = this.road_size;
                }
            }

            for (UInt32 i = 0; i < this.Threads.Length; ++i)
            {
                Threads[i].Join();
            }

            for (UInt32 i = 0; i < (UInt32)progressBars.Length; ++i)
            {
                this.progressBars[i].Value = this.progressBars[i].Minimum;
            }

            for (UInt32 i = 0; i < this.Horse_Participants.Length; ++i)
            {
                Threads[i] = new Thread(Run);
            }
            this.list = new List<String>();
            this.list_injury = new List<String>();
            Initialize_Horse_Participants();
            this.Barrier = new Barrier(participantCount: Horse_Participants.Length);
            end_race = false;
            Start_Race();
        }
    }
}
