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
        Thread Print_Thread;
        Barrier Barrier;
        Int32 road_size;
        PictureBox[] pictureBoxes;
        TextBox[] textBoxes;

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
                        //this.pictureBoxes[i].Left += Horse_Participants[i].Position;
                        //this.textBoxes[i].Text = Horse_Participants[i].Position.ToString();
                        //lock (Name_Locker)
                        WriteTextSafe(Horse_Participants[i].Position.ToString(), i);
                        //{
                        //    //Console.Write(" => {0} {1}", Horse_Participants[i].Horse_Name, Horse_Participants[i].Position);

                        //}
                        //Console.Write("\n");
                    }
                    Thread.Sleep(300);
                    //Console.Clear();
                }
            }
        }

        private delegate void SafeCallDelegate(string text, uint i);
        private void WriteTextSafe(string text, uint i)
        {
            if (this.textBoxes[i].InvokeRequired)
            {
                var d = new SafeCallDelegate(WriteTextSafe);
                this.textBoxes[i].Invoke(d, new object[] { text,i });
            }
            else
            {
                this.textBoxes[i].Text = text;
            }
        }



        //private void SetText()
        //{
        //    WriteTextSafe("This text was set safely.");
        //}

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
            this.pictureBoxes = new PictureBox[5];
            pictureBoxes[0] = horse1;
            pictureBoxes[1] = horse2;
            pictureBoxes[2] = horse3;
            pictureBoxes[3] = horse4;
            pictureBoxes[4] = horse5;

            this.textBoxes = new TextBox[5];
            textBoxes[0] = textBox1;
            textBoxes[1] = textBox2;
            textBoxes[2] = textBox3;
            textBoxes[3] = textBox4;
            textBoxes[4] = textBox5;
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
            this.pictureBoxes = new PictureBox[5];
            pictureBoxes[0] = horse1;
            pictureBoxes[1] = horse2;
            pictureBoxes[2] = horse3;
            pictureBoxes[3] = horse4;
            pictureBoxes[4] = horse5;

            this.textBoxes = new TextBox[5];
            textBoxes[0] = textBox1;
            textBoxes[1] = textBox2;
            textBoxes[2] = textBox3;
            textBoxes[3] = textBox4;
            textBoxes[4] = textBox5;
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

        private void Form1_Load(object sender, EventArgs e)
        {
            //Start_Race();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Start_Race();
        }
    }
}
