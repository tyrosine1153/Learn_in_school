using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClassSeatTable
{
	public partial class Form1 : Form
	{
		List<Panel> panelList;
		List<Label> labelList;
		public Form1()
		{
			InitializeComponent();
			panelList = new List<Panel>();
			labelList = new List<Label>();
		}
		private void button1_Click(object sender, EventArgs e)
		{
			if (textBox1.Text.GetType() == typeof(int)) { }
			int input = Convert.ToInt32(textBox1.Text);
			MakeSeat(input);
			ShuppleSeat();
		}
		/*
		 자리수 랜덤하게 섞임. 2중 for 문을 이용해서 서로 바꿔주는 방식 
		Visible = false, null
		*/
		private void ShuppleSeat() {
			int labelCnt = labelList.Count;
			for (int i = 0; i < labelCnt; i++) {
				Random r = new Random(); 
				int ran = r.Next(1,labelCnt);
				string temp = this.labelList[i].Text;
				this.labelList[i].Text = this.labelList[ran].Text;
				this.labelList[ran].Text = temp;
			}
		}
		private void MakeSeat(int n) {
			for (int i = 0; i < n; i++)
			{
				labelList.Add(MakeLable(i));
				panelList.Add(MakePanel(i));
			}
		}
	}
}
