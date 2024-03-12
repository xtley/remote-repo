namespace _8_1_多窗体及菜单合并
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.打开OToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.排列ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.窗体ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.帮助ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.窗体1ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.窗体2ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.窗体3ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.水平排列ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.垂直排列ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.层叠排列ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.打开OToolStripMenuItem,
            this.排列ToolStripMenuItem,
            this.窗体ToolStripMenuItem,
            this.帮助ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(761, 32);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 打开OToolStripMenuItem
            // 
            this.打开OToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.窗体1ToolStripMenuItem,
            this.窗体2ToolStripMenuItem,
            this.窗体3ToolStripMenuItem});
            this.打开OToolStripMenuItem.MergeIndex = 1;
            this.打开OToolStripMenuItem.Name = "打开OToolStripMenuItem";
            this.打开OToolStripMenuItem.Size = new System.Drawing.Size(85, 28);
            this.打开OToolStripMenuItem.Text = "打开(O)";
            // 
            // 排列ToolStripMenuItem
            // 
            this.排列ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.水平排列ToolStripMenuItem,
            this.垂直排列ToolStripMenuItem,
            this.层叠排列ToolStripMenuItem});
            this.排列ToolStripMenuItem.MergeIndex = 2;
            this.排列ToolStripMenuItem.Name = "排列ToolStripMenuItem";
            this.排列ToolStripMenuItem.Size = new System.Drawing.Size(58, 28);
            this.排列ToolStripMenuItem.Text = "排列";
            // 
            // 窗体ToolStripMenuItem
            // 
            this.窗体ToolStripMenuItem.MergeIndex = 3;
            this.窗体ToolStripMenuItem.Name = "窗体ToolStripMenuItem";
            this.窗体ToolStripMenuItem.Size = new System.Drawing.Size(58, 28);
            this.窗体ToolStripMenuItem.Text = "窗体";
            // 
            // 帮助ToolStripMenuItem
            // 
            this.帮助ToolStripMenuItem.Name = "帮助ToolStripMenuItem";
            this.帮助ToolStripMenuItem.Size = new System.Drawing.Size(58, 28);
            this.帮助ToolStripMenuItem.Text = "帮助";
            // 
            // 窗体1ToolStripMenuItem
            // 
            this.窗体1ToolStripMenuItem.Name = "窗体1ToolStripMenuItem";
            this.窗体1ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.窗体1ToolStripMenuItem.Text = "窗体1";
            this.窗体1ToolStripMenuItem.Click += new System.EventHandler(this.窗体1ToolStripMenuItem_Click);
            // 
            // 窗体2ToolStripMenuItem
            // 
            this.窗体2ToolStripMenuItem.Name = "窗体2ToolStripMenuItem";
            this.窗体2ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.窗体2ToolStripMenuItem.Text = "窗体2";
            this.窗体2ToolStripMenuItem.Click += new System.EventHandler(this.窗体2ToolStripMenuItem_Click);
            // 
            // 窗体3ToolStripMenuItem
            // 
            this.窗体3ToolStripMenuItem.Name = "窗体3ToolStripMenuItem";
            this.窗体3ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.窗体3ToolStripMenuItem.Text = "窗体3";
            this.窗体3ToolStripMenuItem.Click += new System.EventHandler(this.窗体3ToolStripMenuItem_Click);
            // 
            // 水平排列ToolStripMenuItem
            // 
            this.水平排列ToolStripMenuItem.Name = "水平排列ToolStripMenuItem";
            this.水平排列ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.水平排列ToolStripMenuItem.Text = "水平排列";
            this.水平排列ToolStripMenuItem.Click += new System.EventHandler(this.水平排列ToolStripMenuItem_Click);
            // 
            // 垂直排列ToolStripMenuItem
            // 
            this.垂直排列ToolStripMenuItem.Name = "垂直排列ToolStripMenuItem";
            this.垂直排列ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.垂直排列ToolStripMenuItem.Text = "垂直排列";
            this.垂直排列ToolStripMenuItem.Click += new System.EventHandler(this.垂直排列ToolStripMenuItem_Click);
            // 
            // 层叠排列ToolStripMenuItem
            // 
            this.层叠排列ToolStripMenuItem.Name = "层叠排列ToolStripMenuItem";
            this.层叠排列ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.层叠排列ToolStripMenuItem.Text = "层叠排列";
            this.层叠排列ToolStripMenuItem.Click += new System.EventHandler(this.层叠排列ToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(761, 683);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "MDI窗体及菜单合并";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 打开OToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 窗体1ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 窗体2ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 窗体3ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 排列ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 水平排列ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 垂直排列ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 层叠排列ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 窗体ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 帮助ToolStripMenuItem;
    }
}

