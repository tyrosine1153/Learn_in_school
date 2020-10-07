using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharpWinForms
{
	public partial class Form1 : Form
	{
		Random random = new Random();
		public bool canMove = false;
		public Form1()
		{
			InitializeComponent();
			timer1.Start();
			MakePictureArray(10);
		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}


		private void Form1_MouseClick(object sender, MouseEventArgs e)
		{
			pictureBox1.Left = e.X;
			pictureBox1.Top = e.Y;
		}

		private void pictureBox1_Click(object sender, EventArgs e)
		{

		}

		private void Form1_KeyDown_1(object sender, KeyEventArgs e)
		{   
			if (e.KeyData == Keys.Left) 
			{
				pictureBox1.Left -= 10;
			}
			else if (e.KeyData == Keys.Right)
			{
				pictureBox1.Left += 10;
			}
			else if (e.KeyData == Keys.Up)
			{
				pictureBox1.Top -= 10;
			}
			else if (e.KeyData == Keys.Down)
			{
				pictureBox1.Top += 10;
			}
			if (e.KeyData == Keys.Space) 
			{
				canMove = true;
			}
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			for (int i = 0; i < pictureBox2.Length; i++) 
			{
				pictureBox2[i].Top += random.Next(1, 11);
			}
			if (canMove)
				pictureBox3.Top -= 10;
		}
		
		private void Form1_KeyUp(object sender, KeyEventArgs e)
		{
		}
	}
}
