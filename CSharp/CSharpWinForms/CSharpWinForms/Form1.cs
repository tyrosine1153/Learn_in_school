using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharpWinForms
{
	public partial class Form1 : Form
	{
		Random random = new Random();
		public bool canMove = false;
		List<PictureBox> enemyList;
		List<PictureBox> bulletList; // 리스트 : List<자료형> 리스트이름;
		List<PictureBox> removeList;
		public Form1()
		{
			InitializeComponent();
			timer1.Start();
			CheckForIllegalCrossThreadCalls = false;
			enemyList = new List<PictureBox>();
			bulletList = new List<PictureBox>(); // 리스트 생성 : 리스트 이름 = new List<자료형>();
			removeList = new List<PictureBox>();
			int enemyNumber = 10;
			for (int i = 0; i < enemyNumber; i++)
			{
				enemyList.Add(MakeEnemy(i));
			}
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
				bulletList.Add(MaKeBullet()); //리스트에 추가하기 : 리스트이름.Add(추가할것);
				canMove = true;
			}
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			// 총알이 올라가고 적이 떨어지다가 둘이 만나면 둘다 사라지는 코드
			foreach (PictureBox enemy in enemyList)
			{
				enemy.Top += 10;
			}
			foreach (PictureBox bullet in bulletList)
			{
				bullet.Top -= 10;

				foreach (PictureBox enemy in enemyList)
				{
					if (bullet.Bounds.IntersectsWith(enemy.Bounds))
					{
						removeList.Add(bullet);
						removeList.Add(enemy);
					}
				}
			}

			foreach (PictureBox toRemove in removeList)
			{
				bulletList.Remove(toRemove);
				this.Controls.Remove(toRemove);
			}
			removeList.Clear();
		}

		private void Form1_KeyUp(object sender, KeyEventArgs e)
		{
		}

		private void pictureBox4_Click(object sender, EventArgs e)
		{

		}
	}
}
