namespace _8_1_多窗体及菜单合并
{
    partial class 窗体1
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
            this.分组1ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.显示1ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.构造1ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.维护1ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.分组1ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(857, 32);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            this.menuStrip1.Visible = false;
            // 
            // 分组1ToolStripMenuItem
            // 
            this.分组1ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.显示1ToolStripMenuItem,
            this.构造1ToolStripMenuItem,
            this.维护1ToolStripMenuItem});
            this.分组1ToolStripMenuItem.MergeAction = System.Windows.Forms.MergeAction.MatchOnly;
            this.分组1ToolStripMenuItem.MergeIndex = 1;
            this.分组1ToolStripMenuItem.Name = "分组1ToolStripMenuItem";
            this.分组1ToolStripMenuItem.Size = new System.Drawing.Size(69, 28);
            this.分组1ToolStripMenuItem.Text = "分组1";
            // 
            // 显示1ToolStripMenuItem
            // 
            this.显示1ToolStripMenuItem.Name = "显示1ToolStripMenuItem";
            this.显示1ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.显示1ToolStripMenuItem.Text = "显示1";
            // 
            // 构造1ToolStripMenuItem
            // 
            this.构造1ToolStripMenuItem.Name = "构造1ToolStripMenuItem";
            this.构造1ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.构造1ToolStripMenuItem.Text = "构造1";
            // 
            // 维护1ToolStripMenuItem
            // 
            this.维护1ToolStripMenuItem.Name = "维护1ToolStripMenuItem";
            this.维护1ToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
            this.维护1ToolStripMenuItem.Text = "维护1";
            // 
            // 窗体1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(857, 802);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "窗体1";
            this.Text = "窗体1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 分组1ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 显示1ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 构造1ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 维护1ToolStripMenuItem;
    }
}