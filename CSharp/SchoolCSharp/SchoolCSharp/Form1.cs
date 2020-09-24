using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SchoolCSharp
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent(); //클래스 내장함수. 파셜클래스로 나누어짐
		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}

		private void textBox1_TextChanged(object sender, EventArgs e)
		{
			
		}

		private void button1_Click(object sender, EventArgs e)
		{
			webBrowser1.Navigate(textBox1.Text);
		}

		private void label1_Click(object sender, EventArgs e)
		{

		}

		private void webBrowser1_DocumentCompleted(object sender, WebBrowserDocumentCompletedEventArgs e)
		{
			
		}

		private void button2_Click(object sender, EventArgs e)
		{
			webBrowser1.GoBack();
		}

		private void button3_Click(object sender, EventArgs e)
		{
			webBrowser1.GoForward();
		}
	}
}
