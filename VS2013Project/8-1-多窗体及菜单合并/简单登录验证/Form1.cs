using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 简单登录验证
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void tbUser__Validating(object sender, CancelEventArgs e)
        {
            if (tbUser.Text.ToLower() != "admin")
                errorProvider1.SetError(tbUser, "用户名错误");
            else
                errorProvider1.SetError(tbUser, string.Empty);
        }
        private void tbPassWord__Validating(object sender, CancelEventArgs e)
        {
            if (tbPassWord.Text.ToLower() != "123456")
                errorProvider2.SetError(tbPassWord, "密码错误");
            else
                errorProvider2.SetError(tbPassWord, string.Empty);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(tbUser.Text.ToLower()=="admin"&&tbPassWord.Text.ToLower()=="123456")
                MessageBox.Show("登录成功!", "admin,欢迎您!", MessageBoxButtons.OK);
            else
                MessageBox.Show("非法登录", "请输入合法的用户名密码", MessageBoxButtons.OK);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            tbUser.Text="";
            tbPassWord.Text="";
        }
    }
}
