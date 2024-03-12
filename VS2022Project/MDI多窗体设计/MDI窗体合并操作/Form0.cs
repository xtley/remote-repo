using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MDI窗体合并操作
{
    public partial class Form0 : Form
    {
        public Form0()
        {
            InitializeComponent();
        }

        private void 窗体1ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form frm1 = new Form();
            frm1.MdiParent = this;
            frm1.Text = "窗体1";
            frm1.Show();

            排列ToolStripMenuItem.DropDownItems.Clear();
            ToolStripMenuItem 水平平铺ToolStripMenuItem = new ToolStripMenuItem("水平平铺");
            水平平铺ToolStripMenuItem.Click += new System.EventHandler(水平平铺ToolStripMenuItem_Click);
            排列ToolStripMenuItem.DropDownItems.Add(水平平铺ToolStripMenuItem);
            ToolStripMenuItem 垂直平铺ToolStripMenuItem = new ToolStripMenuItem("垂直平铺");
            垂直平铺ToolStripMenuItem.Click += new System.EventHandler(垂直平铺ToolStripMenuItem_Click);
            排列ToolStripMenuItem.DropDownItems.Add(垂直平铺ToolStripMenuItem);
            ToolStripMenuItem 层叠ToolStripMenuItem = new ToolStripMenuItem("层叠");
            层叠ToolStripMenuItem.Click += new System.EventHandler(层叠ToolStripMenuItem_Click);
            排列ToolStripMenuItem.DropDownItems.Add(层叠ToolStripMenuItem);
            ToolStripMenuItem 显示1ToolStripMenuItem = new ToolStripMenuItem("显示1");
            排列ToolStripMenuItem.DropDownItems.Add(显示1ToolStripMenuItem);
            ToolStripMenuItem 构造1ToolStripMenuItem = new ToolStripMenuItem("构造1");
            排列ToolStripMenuItem.DropDownItems.Add(构造1ToolStripMenuItem);
            ToolStripMenuItem 维护1ToolStripMenuItem = new ToolStripMenuItem("维护1");
            排列ToolStripMenuItem.DropDownItems.Add(维护1ToolStripMenuItem);
        }

        private void 窗体2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            排列ToolStripMenuItem.Text = "分组2";
            排列ToolStripMenuItem.DropDownItems.Clear();
            ToolStripMenuItem 显示2ToolStripMenuItem = new ToolStripMenuItem("显示2");
            排列ToolStripMenuItem.DropDownItems.Add(显示2ToolStripMenuItem);
            ToolStripMenuItem 构造2ToolStripMenuItem = new ToolStripMenuItem("构造2");
            排列ToolStripMenuItem.DropDownItems.Add(构造2ToolStripMenuItem);
            ToolStripMenuItem 维护2ToolStripMenuItem = new ToolStripMenuItem("维护2");
            排列ToolStripMenuItem.DropDownItems.Add(维护2ToolStripMenuItem);
        }

        private void 窗体3ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            排列ToolStripMenuItem.Text = "分组3";
            排列ToolStripMenuItem.DropDownItems.Clear();
            ToolStripMenuItem 显示3ToolStripMenuItem = new ToolStripMenuItem("显示3");
            排列ToolStripMenuItem.DropDownItems.Add(显示3ToolStripMenuItem);
            ToolStripMenuItem 构造3ToolStripMenuItem = new ToolStripMenuItem("构造3");
            排列ToolStripMenuItem.DropDownItems.Add(构造3ToolStripMenuItem);
            ToolStripMenuItem 维护3ToolStripMenuItem = new ToolStripMenuItem("维护3");
            排列ToolStripMenuItem.DropDownItems.Add(维护3ToolStripMenuItem);
        }

        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void Form0_Load(object sender, EventArgs e)
        {
           

            Form frm2 = new Form();
            frm2.MdiParent = this;
            frm2.Text = "窗体2";
            frm2.Show();

            Form frm3 = new Form();
            frm3.MdiParent = this;
            frm3.Text = "窗体3";
            frm3.Show();

            LayoutMdi(MdiLayout.TileVertical);
        }

        private void 排列ToolStripMenuItem_Click(object sender, EventArgs e)
        {

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
        private void 水平平铺ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);
        }
        private void 垂直平铺ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileVertical);
        }
        private void 层叠ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.Cascade);
        }
    }
}
