using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 单选按钮与消息框
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked==true)
            MessageBox.Show("非常满意!", "", MessageBoxButtons.OK);

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton2.Checked == true)
            MessageBox.Show("基本满意!", "", MessageBoxButtons.OK);
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton3.Checked == true)
            MessageBox.Show("态度一般!", "", MessageBoxButtons.OK);
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton4.Checked == true)
            MessageBox.Show("不满意!", "", MessageBoxButtons.OK);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }
    }
}
