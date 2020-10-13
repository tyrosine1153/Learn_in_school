using System.Collections.Generic;
using System.Security;
using System.Windows.Forms;

namespace CSharpWinForms
{
	partial class Form1
	{
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		/// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form 디자이너에서 생성한 코드

		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.timer1 = new System.Windows.Forms.Timer(this.components);
			this.pictureBox1 = new System.Windows.Forms.PictureBox();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
			this.SuspendLayout();
			// 
			// timer1
			// 
			this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
			// 
			// pictureBox1
			// 
			this.pictureBox1.Image = global::CSharpWinForms.Properties.Resources._123;
			this.pictureBox1.Location = new System.Drawing.Point(340, 325);
			this.pictureBox1.Name = "pictureBox1";
			this.pictureBox1.Size = new System.Drawing.Size(111, 102);
			this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
			this.pictureBox1.TabIndex = 7;
			this.pictureBox1.TabStop = false;
			this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.pictureBox1);
			this.Name = "Form1";
			this.Text = "Form1";
			this.Load += new System.EventHandler(this.Form1_Load);
			this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown_1);
			this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyUp);
			this.MouseClick += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseClick);
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion
		
		private PictureBox MakeEnemy(int sequence) 
		{
			PictureBox pictureBox2;
			pictureBox2 = new System.Windows.Forms.PictureBox();
			((System.ComponentModel.ISupportInitialize)(pictureBox2)).BeginInit();
			// 
			// pictureBox2
			// 
			pictureBox2.Load(@"C:\Users\jungm\Desktop\캡쳐\123.png");
			pictureBox2.Location = new System.Drawing.Point(12+ sequence * 80, 12);
			pictureBox2.Name = "pictureBox2";
			pictureBox2.Size = new System.Drawing.Size(40, 40);
			pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
			pictureBox2.TabIndex = 8;
			pictureBox2.TabStop = false;

			Controls.Add(pictureBox2);
			((System.ComponentModel.ISupportInitialize)(pictureBox2)).EndInit();

			return pictureBox2;
		}

		private PictureBox MaKeBullet()
		{
			PictureBox pictureBox4; // 클래스 변수화
			pictureBox4 = new System.Windows.Forms.PictureBox();
			((System.ComponentModel.ISupportInitialize)(pictureBox4)).BeginInit();
			// 
			// pictureBox4
			// 
			pictureBox4.Image = global::CSharpWinForms.Properties.Resources._1234;
			pictureBox4.Location = new System.Drawing.Point(pictureBox1.Left + 22, pictureBox1.Top - 47);
			pictureBox4.Name = "pictureBox4";
			pictureBox4.Size = new System.Drawing.Size(45, 47);
			pictureBox4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
			pictureBox4.TabIndex = 8;
			pictureBox4.TabStop = false;
			pictureBox4.Click += new System.EventHandler(pictureBox4_Click);

			Controls.Add(pictureBox4);
			((System.ComponentModel.ISupportInitialize)(pictureBox4)).EndInit();

			return pictureBox4;
		}

		private System.Windows.Forms.PictureBox pictureBox1;
		private System.Windows.Forms.Timer timer1;
		private System.Windows.Forms.PictureBox pictureBox3;
		
	}
}