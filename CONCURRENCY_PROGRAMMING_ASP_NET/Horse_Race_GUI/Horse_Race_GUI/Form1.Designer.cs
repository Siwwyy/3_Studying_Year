namespace Horse_Race_GUI
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.horse1 = new System.Windows.Forms.PictureBox();
            this.horse2 = new System.Windows.Forms.PictureBox();
            this.horse3 = new System.Windows.Forms.PictureBox();
            this.horse4 = new System.Windows.Forms.PictureBox();
            this.horse5 = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.horse1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.horse2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.horse3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.horse4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.horse5)).BeginInit();
            this.SuspendLayout();
            // 
            // horse1
            // 
            this.horse1.Image = ((System.Drawing.Image)(resources.GetObject("horse1.Image")));
            this.horse1.Location = new System.Drawing.Point(12, 12);
            this.horse1.Name = "horse1";
            this.horse1.Size = new System.Drawing.Size(100, 50);
            this.horse1.TabIndex = 0;
            this.horse1.TabStop = false;
            // 
            // horse2
            // 
            this.horse2.Image = ((System.Drawing.Image)(resources.GetObject("horse2.Image")));
            this.horse2.Location = new System.Drawing.Point(12, 68);
            this.horse2.Name = "horse2";
            this.horse2.Size = new System.Drawing.Size(100, 50);
            this.horse2.TabIndex = 1;
            this.horse2.TabStop = false;
            // 
            // horse3
            // 
            this.horse3.Image = ((System.Drawing.Image)(resources.GetObject("horse3.Image")));
            this.horse3.Location = new System.Drawing.Point(12, 124);
            this.horse3.Name = "horse3";
            this.horse3.Size = new System.Drawing.Size(100, 50);
            this.horse3.TabIndex = 2;
            this.horse3.TabStop = false;
            // 
            // horse4
            // 
            this.horse4.Image = ((System.Drawing.Image)(resources.GetObject("horse4.Image")));
            this.horse4.Location = new System.Drawing.Point(12, 180);
            this.horse4.Name = "horse4";
            this.horse4.Size = new System.Drawing.Size(100, 50);
            this.horse4.TabIndex = 3;
            this.horse4.TabStop = false;
            // 
            // horse5
            // 
            this.horse5.Image = ((System.Drawing.Image)(resources.GetObject("horse5.Image")));
            this.horse5.Location = new System.Drawing.Point(12, 236);
            this.horse5.Name = "horse5";
            this.horse5.Size = new System.Drawing.Size(100, 50);
            this.horse5.TabIndex = 4;
            this.horse5.TabStop = false;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(1524, 265);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 5;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(1499, 31);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 6;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(1499, 72);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 20);
            this.textBox2.TabIndex = 7;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(1499, 112);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 20);
            this.textBox3.TabIndex = 8;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(1499, 158);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(100, 20);
            this.textBox4.TabIndex = 9;
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(1499, 204);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(100, 20);
            this.textBox5.TabIndex = 10;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.ClientSize = new System.Drawing.Size(1611, 300);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.horse5);
            this.Controls.Add(this.horse4);
            this.Controls.Add(this.horse3);
            this.Controls.Add(this.horse2);
            this.Controls.Add(this.horse1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.horse1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.horse2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.horse3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.horse4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.horse5)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox horse1;
        private System.Windows.Forms.PictureBox horse2;
        private System.Windows.Forms.PictureBox horse3;
        private System.Windows.Forms.PictureBox horse4;
        private System.Windows.Forms.PictureBox horse5;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox5;
    }
}

