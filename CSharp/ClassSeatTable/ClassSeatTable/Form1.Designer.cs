using System.Windows.Forms;

namespace ClassSeatTable
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
			this.textBox1 = new System.Windows.Forms.TextBox();
			this.button1 = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// textBox1
			// 
			this.textBox1.Location = new System.Drawing.Point(749, 12);
			this.textBox1.Name = "textBox1";
			this.textBox1.Size = new System.Drawing.Size(75, 21);
			this.textBox1.TabIndex = 0;
			this.textBox1.Text = "학생 수";
			this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(749, 39);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(75, 23);
			this.button1.TabIndex = 1;
			this.button1.Text = "돌리기";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.button1_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(836, 497);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.textBox1);
			this.Name = "Form1";
			this.Text = "Form1";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		private Panel MakePanel(int i) {
			Panel panel1;
			panel1 = new System.Windows.Forms.Panel();
			// 
			// panel1
			// 
			panel1.BackColor = System.Drawing.SystemColors.MenuHighlight;
			panel1.Location = new System.Drawing.Point(33 + 140 * (i%5), 33 + 80 * (i/5));
			panel1.Name = "panel1";
			panel1.Size = new System.Drawing.Size(131, 77);
			panel1.TabIndex = 1;

			Controls.Add(panel1);
			return panel1;
		}
		private Label MakeLable(int i) {
			Label label1;
			label1 = new System.Windows.Forms.Label();

			label1.AutoSize = true;
			label1.Location = new System.Drawing.Point(33 + 140 * (i % 5), 33 + 80 * (i / 5));
			label1.Name = "label1";
			label1.Size = new System.Drawing.Size(38, 12);
			label1.TabIndex = 0;
			label1.Text = $"{i+1}";

			Controls.Add(label1);
			return label1;
		}
		#endregion

		private TextBox textBox1;
		private Button button1;
	}
}
