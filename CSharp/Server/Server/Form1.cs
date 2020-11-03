using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Server
{
	public partial class Form1 : Form
	{
		Thread temp;
		TcpListener ReceiveListener;
		public Form1()
		{
			InitializeComponent();
		}
		private void button1_Click(object sender, EventArgs e)
		{
			temp = new Thread(new ThreadStart(startServer));
			temp.Start();
			MessageBox.Show("일단 성공");
		}

		private void startServer()
		{
			ReceiveListener = new TcpListener(2118);//연결이 오는걸 받는거
			ReceiveListener.Start();//handler가 동작하기 전까지 대기하고있음
			while (true)
			{
				TcpClient handler = ReceiveListener.AcceptTcpClient();//연결요청 수락
				NetworkStream networkStream = handler.GetStream();
				Byte[] ReadByte;
				ReadByte = new byte[handler.ReceiveBufferSize];
				int BytesRead = networkStream.Read(ReadByte, 0, (int)ReadByte.Length);
				string ReceiveString = Encoding.GetEncoding("utf-8").GetString(ReadByte);
				textBox1.Text += (ReceiveString + "\r\n");
				//server에서 listener를 생성, 
			}
		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}

		private void Form1_FormClosing(object sender, FormClosingEventArgs e)
		{
			if (ReceiveListener != null) {
				ReceiveListener.Stop();
				ReceiveListener = null;
			}
			if (temp != null)
			{
				temp.Abort();
				temp = null;
			}
		}
	}
}
