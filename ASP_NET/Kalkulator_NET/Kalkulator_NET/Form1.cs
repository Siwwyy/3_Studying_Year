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

        private double pierwsza;
        private double druga;
        private double wynik;
        private char dzialanie;
        public Form1()
        {
            dzialanie = ' ';
            InitializeComponent();
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

        private void btn1_Click(object sender, EventArgs e)
        {
            Wpisz("1");
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            Wpisz("8");
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            Wpisz("2");
        }

        private void btn3_Click(object sender, EventArgs e)
        {
            Wpisz("3");
        }

        private void btn6_Click(object sender, EventArgs e)
        {
            Wpisz("6");
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Wpisz("7");
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            Wpisz("5");
        }

        private void btn4_Click(object sender, EventArgs e)
        {
            Wpisz("4");
        }

        private void btn7_Click(object sender, EventArgs e)
        {
            Wpisz("7");
        }

        private void btn0_Click(object sender, EventArgs e)
        {
            Wpisz("0");
        }

        private void btn_wykasuj_Click(object sender, EventArgs e)
        {
            this.txt_wynik.Text = "0";
        }

        private void btn_kropka_Click(object sender, EventArgs e)
        {
            Wpisz(".");
        }

        private void btn_dodaj_Click(object sender, EventArgs e)
        {
            pierwsza = Double.Parse(txt_wynik.Text);
            this.txt_wynik.Text = "";
            dzialanie = '+';
        }

        private void btn_odejmij_Click(object sender, EventArgs e)
        {
            pierwsza = Double.Parse(txt_wynik.Text);
            this.txt_wynik.Text = "";
            dzialanie = '-';
        }

        private void btn_pomnoz_Click(object sender, EventArgs e)
        {
            pierwsza = Double.Parse(txt_wynik.Text);
            this.txt_wynik.Text = "";
            dzialanie = '*';
        }

        private void btn_podziel_Click(object sender, EventArgs e)
        {
            pierwsza = Double.Parse(txt_wynik.Text);
            this.txt_wynik.Text = "";
            dzialanie = '/';
        }

        private void btn_wynik_Click(object sender, EventArgs e)
        {
            if(dzialanie == '+')
            {
                druga = Double.Parse(txt_wynik.Text);
                wynik = pierwsza + druga;
                this.txt_wynik.Text = wynik.ToString();
            }
            else if (dzialanie == '-')
            {
                druga = Double.Parse(txt_wynik.Text);
                wynik = pierwsza - druga;
                this.txt_wynik.Text = wynik.ToString();
            }
            else if (dzialanie == '*')
            {
                druga = Double.Parse(txt_wynik.Text);
                wynik = pierwsza * druga;
                this.txt_wynik.Text = wynik.ToString();
            }
            else if (dzialanie == '/')
            {
                druga = Double.Parse(txt_wynik.Text);
                wynik = pierwsza / druga;
                this.txt_wynik.Text = wynik.ToString();
            }
            pierwsza = 0;
            druga = 0;
            wynik = 0;
        }
    }
}