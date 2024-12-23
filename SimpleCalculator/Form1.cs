using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace SimpleCalculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        string Result0 = "";

        private void Plus_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "" || textBox2.Text != "")
                Result0 = Convert.ToString(Convert.ToDouble(textBox1.Text) + Convert.ToDouble(textBox2.Text));
        }

        private void Minus_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "" || textBox2.Text != "")
                Result0 = Convert.ToString(Convert.ToDouble(textBox1.Text) - Convert.ToDouble(textBox2.Text));
        }

        private void Divide_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "")
                textBox1.Text = "0";

            if (textBox1.Text != "" && Convert.ToDouble(textBox2.Text) != 0)
                Result0 = Convert.ToString(Convert.ToDouble(textBox1.Text) / Convert.ToDouble(textBox2.Text));
            else 
                Result0 = "Cannot divide by zero";
        }

        private void Multiply_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "" || textBox2.Text != "")
                Result0 = Convert.ToString(Convert.ToDouble(textBox1.Text) * Convert.ToDouble(textBox2.Text));
        }

        private void Result_Click(object sender, EventArgs e)
        {
            textBox3.Text = Result0;
        }
    }
}
