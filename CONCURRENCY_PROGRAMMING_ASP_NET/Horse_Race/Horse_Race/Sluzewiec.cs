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
		Int32 road_size;
		String[] Placement;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			PRIVATE FUNCTIONS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		private void Initialize_Horse_Participants()
		{
			Horse_Participants = new Horse[5];
			Horse_Participants[0] = new Horse("Mark 1",Get_Random_Value(1, 10));
			Horse_Participants[1] = new Horse("Henry 2", Get_Random_Value(1, 10));
			Horse_Participants[2] = new Horse("Peter 3", Get_Random_Value(1, 10));
			Horse_Participants[3] = new Horse("Oliver 4", Get_Random_Value(1, 10));
			Horse_Participants[4] = new Horse("Marcus 5", Get_Random_Value(1, 10));
		}

		private Int32 Get_Random_Value(int beginning, int end)
		{
			Random rand = new Random();
			return (Int32)(rand.Next(beginning, end));
		}

		private void Print_Roads()
		{
			for (UInt32 i = 0; i < (UInt32)Horse_Participants.Length; ++i)
			{
				for (UInt32 j = 0; j < (UInt32)Horse_Participants[i].Position; ++j)
				{
					Console.Write("-");
				}
				Console.Write(" => {0}", Horse_Participants[i].Horse_Name);
				Console.Write("\n");
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
			this.road_size = 30000;
			this.Placement = new String[5];
		}
		public Sluzewiec(Int32 road_size)
		{
			Initialize_Horse_Participants();
			this.road_size = road_size;
			this.Placement = new String[5];
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
			for(UInt32 i = 0; i < (UInt32)Horse_Participants.Length; ++i)
			{
				Horse_Participants[i].Print();
			}
		}

		public void Start_Race()
		{
			UInt32 placement_counter = 0;
			while(placement_counter < 5)
			{
				//Print_Roads();
				for (UInt32 i = 0; i < (UInt32)Horse_Participants.Length; ++i)
				{
					if(this.Horse_Participants[i].Position == this.road_size)
					{
						this.Placement[placement_counter] = this.Horse_Participants[i].Horse_Name;
						++placement_counter;
					}
					else
					{
						Horse_Participants[i]++;
					}
				}
				//Thread.Sleep(300);
				//Console.Clear();
			}
			Console.Clear();
			Console.WriteLine("Placement is following ");
			for (UInt32 i = 0; i < (UInt32)Placement.Length; ++i)
			{
				Console.WriteLine("Place {0} takes horse {1}", (i+1), this.Placement[i]);
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
		public Int32 Road_size
		{ 
			get
			{
				return this.road_size;
			}
			set
			{
				this.road_size = value;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
	}
}
