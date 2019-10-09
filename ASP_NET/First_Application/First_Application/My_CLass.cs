using System;
using System.Collections.Generic;
using System.Text;

namespace First_Application
{
    class My_Class
    {
        private string Name;
        private string Surname;

        /*
            CASE OF CONSTRUCTORS
        */
        public My_Class()
        {
            this.Name = default;
            this.Surname = default;
        }

        public My_Class(string name, string surname)
        {
            this.Name = name;
            this.Surname = surname;
        }//Parametrized constructor up here
         ////////////////////////////////////////////
         ///
        /*
            CASE OF SETTERS
        */
        public void Set_Name(string Name)
        {
            this.Name = Name;
        }

        public void Set_Surname(string Surname)
        {
            this.Surname = Surname;
        }
        ////////////////////////////////////////////
        ///
        /*
            CASE OF PROPERTIES
        */
        public string Name_Property
        {
            set
            {
                if (value != " ")
                {
                    this.Name = value;
                }
                else
                {
                    Console.WriteLine("Check the correctness of the entered name!");
                }
            }
            get
            {
                return this.Name;
            }
        }

        public string Surname_Property
        {
            set
            {
                if (value != " ")
                {
                    this.Surname = value;
                }
                else
                {
                    Console.WriteLine("Check the correctness of the entered surname!");
                }
            }
            get
            {
                return this.Surname;
            }
        }
        ////////////////////////////////////////////
        ///
        /*
           CASE OF GETTERS
        */
        public string Get_Name()
        {
            return this.Name;
        }
        public string Get_Surname()
        {
            return this.Surname;
        }
        ////////////////////////////////////////////
    }
}
