using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;

namespace UsePython
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void button1_Click(object sender, EventArgs e)
		{
			if (textBox1.Text == "")
				return;
			try
			{
				File.WriteAllText("temp.py", textBox1.Text, Encoding.UTF8); // textBox1.Text을 temp.py에 저장

				ProcessStartInfo processInfo = new ProcessStartInfo("py.exe"); // docs ProcessStartInfo 예제 참고
				processInfo.Arguments = "temp.py";
				processInfo.WindowStyle = ProcessWindowStyle.Minimized; // 최소화 모드
				processInfo.UseShellExecute = false;
				processInfo.RedirectStandardInput = true;
				processInfo.RedirectStandardOutput = true;
				processInfo.RedirectStandardError = true;

				Process pyProcess = new Process();
				pyProcess.StartInfo = processInfo; // 위에 설정한 StartInfo 자료형 객체 대입
				pyProcess.Start(); // 프로세스 시작 Process.Start("py.exe", "temp.py");

				StreamReader myStreamReader = pyProcess.StandardError; //
				MessageBox.Show(myStreamReader.ReadLine()); //

				StreamWriter myStreamWriter = pyProcess.StandardInput;
				myStreamReader = pyProcess.StandardOutput;
				MessageBox.Show(myStreamReader.ReadLine());
				
				pyProcess.WaitForExit();
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.ToString());
			}
		}
	}
}
