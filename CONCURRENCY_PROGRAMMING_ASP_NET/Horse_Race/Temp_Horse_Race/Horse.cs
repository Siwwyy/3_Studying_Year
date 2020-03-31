﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Temp_Horse_Race
{
    class Horse
    {
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PRIVATE VARIABLES
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        String horse_name;
        Int32 speed;
        Int32 position;
        public bool injury = false;
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PRIVATE CONSTRUCTORS
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        private Horse(String name, Int32 speed, Int32 position)
        {
            this.horse_name = name;
            this.speed = speed;
            this.position = position;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
			PUBLIC CONSTRUCTORS
		*/
        /////////////////////////////////////////////////////////////////////////////////////////////
        public Horse()
        {
            this.horse_name = "Henry";
            this.speed = 2;
            this.position = 0;
        }

        public Horse(String name, Int32 speed)
        {
            this.horse_name = name;
            this.speed = speed;
            this.position = 0;
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
            Console.WriteLine("Name | {0} | Speed: {1}", this.horse_name, this.speed);
        }

        public void Run(object Position_Goal)
        {
            Thread.Sleep(1000);
            while (this.position < Convert.ToInt32(Position_Goal))
            {
                this.position += this.speed;
            }
        }

        public void Make_Move()
        {
            this.position += this.speed;
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
        public String Horse_Name
        {
            get
            {
                return this.horse_name;
            }
            set
            {
                this.horse_name = value;
            }
        }
        public Int32 Speed
        {
            get
            {
                return this.speed;
            }
            set
            {
                this.speed = value;
            }
        }
        public Int32 Position
        {
            get
            {
                return this.position;
            }
            set
            {
                this.position = value;
            }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////
    }
}