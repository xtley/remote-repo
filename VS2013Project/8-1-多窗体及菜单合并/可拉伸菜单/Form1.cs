using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 可拉伸菜单
{
    public partial class Form1 : Form
    {
       
        public Form1()
        {
            InitializeComponent();
        }
        private void 展开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //利用flag来进行点击交替的完成展开关闭
            flag ^= 1;
            bool pos=flag==1?true:false;
            //设置展开还是关闭
            this.导入资源ToolStripMenuItem1.Visible = pos;
            this.导出ToolStripMenuItem1.Visible = pos;

        }
        private int flag = 0;

        private void 导入资源ToolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void 导出ToolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void 文件FToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
    }
}
