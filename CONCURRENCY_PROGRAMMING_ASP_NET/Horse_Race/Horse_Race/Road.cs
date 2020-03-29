﻿using System;
using System.Collections.Generic;
using System.Text;

namespace Horse_Race
{
    class Road
    {

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PRIVATE VARIABLES
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        Int32 road_size;
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PRIVATE CONSTRUCTORS
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PUBLIC CONSTRUCTORS
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        public Road()
        {
            this.road_size = 10000;
        }

        public Road(Int32 road_size)
        {
            this.road_size = road_size;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PUBLIC SETTERS
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        void Set_Road_Size(Int32 road_size)
        {
            this.road_size = road_size;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PUBLIC FUNCTIONS
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        public void Start_Race()
        {
            while (true)
            {
                //for (UInt32 i = 0; i < this.Threads.Length; ++i)
                //{

                //}
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
        Int32 Get_Road_Size()
        {
            return this.road_size;
        }
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
