namespace MDI多窗体设计
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void 创建子窗体ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form frm1 = new Form();
            frm1.MdiParent = this;
            frm1.Show();

            Form frm2 = new Form();
            frm2.MdiParent = this;
            frm2.Show();

            Form frm3 = new Form();
            frm3.MdiParent = this;
            frm3.Show();
        }

        private void 水平平铺ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void 垂直平铺ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileVertical);
        }

        private void 重叠排列ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.Cascade);
        }
    }
}