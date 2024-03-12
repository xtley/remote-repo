namespace _8_1_多窗体及菜单合并
{
    partial class 窗体2
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
            this.分组2ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.显示2ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.构造2ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.维护2ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.分组2ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(775, 32);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            this.menuStrip1.Visible = false;
            // 
            // 分组2ToolStripMenuItem
            // 
            this.分组2ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.显示2ToolStripMenuItem,
            this.构造2ToolStripMenuItem,
            this.维护2ToolStripMenuItem});
            this.分组2ToolStripMenuItem.MergeAction = System.Windows.Forms.MergeAction.Insert;
            this.分组2ToolStripMenuItem.MergeIndex = 1;
            this.分组2ToolStripMenuItem.Name = "分组2ToolStripMenuItem";
            this.分组2ToolStripMenuItem.Size = new System.Drawing.Size(69, 28);
            this.分组2ToolStripMenuItem.Text = "分组2";
            // 
            // 显示2ToolStripMenuItem
            // 
            this.显示2ToolStripMenuItem.Name = "显示2ToolStripMenuItem";
            this.显示2ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.显示2ToolStripMenuItem.Text = "显示2";
            // 
            // 构造2ToolStripMenuItem
            // 
            this.构造2ToolStripMenuItem.Name = "构造2ToolStripMenuItem";
            this.构造2ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.构造2ToolStripMenuItem.Text = "构造2";
            // 
            // 维护2ToolStripMenuItem
            // 
            this.维护2ToolStripMenuItem.Name = "维护2ToolStripMenuItem";
            this.维护2ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.维护2ToolStripMenuItem.Text = "维护2";
            // 
            // 窗体2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(775, 674);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "窗体2";
            this.Text = "窗体2";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 分组2ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 显示2ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 构造2ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 维护2ToolStripMenuItem;
    }
}