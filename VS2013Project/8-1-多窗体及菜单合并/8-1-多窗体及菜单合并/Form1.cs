using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _8_1_多窗体及菜单合并
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void 水平排列ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void 垂直排列ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileVertical);
        }

        private void 层叠排列ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.Cascade);
        }

        private void 窗体1ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            窗体1 frm = new 窗体1();
            frm.MdiParent = this;
            frm.Text = "窗体1";
            frm.Show();
        }

        private void 窗体2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            窗体2 frm = new 窗体2();
            frm.MdiParent = this;
            frm.Text = "窗体2";
            frm.Show();
        }

        private void 窗体3ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            窗体3 frm = new 窗体3();
            frm.MdiParent = this;
            frm.Text = "窗体3";
            frm.Show();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
         
        }
    }
}
