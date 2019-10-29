using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Kalkulator_NET
{
    public partial class Form1 : Form
    {

        private bool status;
        public Form1()
        {
            status = true;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Wpisz("1");
        }

        private void Wpisz(String my_value)
        {
            if(this.txt_wynik.Text == "0")
            {
                this.txt_wynik.Text = "";
                this.txt_wynik.Text += my_value;
            }
            else
            {
                this.txt_wynik.Text += my_value;
            }
        }
    }
}
