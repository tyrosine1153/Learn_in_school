using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharpWinForms
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}

		private void button1_Click(object sender, EventArgs e)
		{
			webBrowser1.Navigate(textBox1.Text);
		}

		private void back_Click(object sender, EventArgs e)
		{
			webBrowser1.GoBack();
		}

		private void forward_Click(object sender, EventArgs e)
		{
			webBrowser1.GoForward();
		}
	}
}
