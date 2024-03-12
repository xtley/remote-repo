namespace _8_1_多窗体及菜单合并
{
    partial class 窗体3
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.分组3ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.显示3ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.构造3ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.维护3ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.分组3ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(697, 32);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            this.menuStrip1.Visible = false;
            // 
            // 分组3ToolStripMenuItem
            // 
            this.分组3ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.显示3ToolStripMenuItem,
            this.构造3ToolStripMenuItem,
            this.维护3ToolStripMenuItem});
            this.分组3ToolStripMenuItem.MergeAction = System.Windows.Forms.MergeAction.Replace;
            this.分组3ToolStripMenuItem.MergeIndex = 1;
            this.分组3ToolStripMenuItem.Name = "分组3ToolStripMenuItem";
            this.分组3ToolStripMenuItem.Size = new System.Drawing.Size(69, 28);
            this.分组3ToolStripMenuItem.Text = "分组3";
            // 
            // 显示3ToolStripMenuItem
            // 
            this.显示3ToolStripMenuItem.Name = "显示3ToolStripMenuItem";
            this.显示3ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.显示3ToolStripMenuItem.Text = "显示3";
            // 
            // 构造3ToolStripMenuItem
            // 
            this.构造3ToolStripMenuItem.Name = "构造3ToolStripMenuItem";
            this.构造3ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.构造3ToolStripMenuItem.Text = "构造3";
            // 
            // 维护3ToolStripMenuItem
            // 
            this.维护3ToolStripMenuItem.Name = "维护3ToolStripMenuItem";
            this.维护3ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.维护3ToolStripMenuItem.Text = "维护3";
            // 
            // 窗体3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(697, 588);
            this.Controls.Add(this.menuStrip1);
            this.Name = "窗体3";
            this.Text = "窗体3";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 分组3ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 显示3ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 构造3ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 维护3ToolStripMenuItem;


    }
}