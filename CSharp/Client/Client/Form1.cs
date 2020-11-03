using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Client
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void button1_Click(object sender, EventArgs e)
		{
			try
			{
				TcpClient tcpClient = new TcpClient();
				tcpClient.Connect("10.156.147.174", 2118);
				NetworkStream networkStream = tcpClient.GetStream();

				MessageBox.Show("연결성공");
				Byte[] SendData = Encoding.UTF8.GetBytes(textBox1.Text);
				networkStream.Write(SendData, 0, SendData.Length); //Write->Flush
				networkStream.Flush();
				MessageBox.Show("아무튼 성공");
			}
			catch
			{
				MessageBox.Show("연결실패");
			}
		}

		private void textBox1_TextChanged(object sender, EventArgs e)
		{

		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}
	}
}
