using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Net.Sockets;

namespace UseWebView
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void webBrowser1_DocumentCompleted(object sender, WebBrowserDocumentCompletedEventArgs e)
		{
			if (webBrowser1.Url.AbsoluteUri != e.Url.AbsoluteUri) return;
			int asdf = 0;
			asdf++;
			//webBrowser1.Document.Encoding
			//webBrowser1.DocumentText
			HtmlAgilityPack.HtmlDocument doc = new HtmlAgilityPack.HtmlDocument();
			Stream docStream = this.webBrowser1.DocumentStream;
			StreamReader streamReader = new StreamReader(docStream,
				System.Text.Encoding.GetEncoding(webBrowser1.Document.Encoding));
			string strHtml = streamReader.ReadToEnd();  // 대충 인코딩하고 strHtml에 담는다는 내용

			//대충 필요한 부분만 잘라내는 내용
			HtmlAgilityPack.HtmlNode parseNode = doc.DocumentNode.
				SelectSingleNode("//div[@class='box_type_l']").SelectSingleNode("//table[@class='type_2']");
			List<List<string>> parsedTbl = parseNode.Descendants("tr")//tr기준으로 자름
				.Skip(1) //To Skip Table Header Row 헤더 스킵하려고
				.Where(tr => tr.Elements("td").Count() > 1)// element를 td 기준으로 잘라냄
				.Select(tr => tr.Elements("td")
				.Select(td => td.InnerText.Trim())//InnerHtml : 표 안에있는 글자 <-> OuterHtml
				.ToList()).ToList();
		}

		private void button1_Click(object sender, EventArgs e)
		{
			try
			{
				TcpClient tcpClient = new TcpClient();
				tcpClient.Connect("10.156.146.76", 2101);
				NetworkStream networkStream = tcpClient.GetStream();
				MessageBox.Show("연결성공");

				networkStream.Write(Encoding.UTF8.GetBytes("aam jjunggminssssss"), 0, 10);
				networkStream.Flush();
				MessageBox.Show("아무튼 성공");
			}
			catch
			{
				MessageBox.Show("연결실패");
			}
		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}
	}
}
