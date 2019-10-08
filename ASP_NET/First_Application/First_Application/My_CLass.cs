using System;
using System.Collections.Generic;
using System.Text;

namespace First_Application
{
    class My_Class
    {
        private int a;
        private string _firstName;
        private string _lastName;

        public My_Class(string first, string last)
        {
            _firstName = first;
            _lastName = last;
        }

        public My_Class(int a)
        {
            this.a = a;
        }

        public string Name => $"{_firstName} {_lastName}";
        

        private int id;

        public int SetGet   //wlasciwosc
        {
            get
            {
                return a;
            }

            set
            {
                a = value;
            }
        }

        int get_a()
        {
            return this.a;
        }
    }
}
