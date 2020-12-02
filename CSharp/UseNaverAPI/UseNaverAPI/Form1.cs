using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UseNaverAPI
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void button1_Click(object sender, EventArgs e)
		{
            string url = "https://openapi.naver.com/v1/papago/n2mt";  // 요청 url
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
            request.Headers.Add("X-Naver-Client-Id", "zZ9fW4Q_RX3DL_Q1XK6s");
            request.Headers.Add("X-Naver-Client-Secret", "Eyj4WpxZrW");
            request.Method = "POST";  // API 메서드 
            string[] inputString = textBox1.Text.Split('\n');
            for (int i = 0; i < inputString.Length; i++)
            {

                //textBox2.Text = query;
                byte[] byteDataParams = Encoding.UTF8.GetBytes("source=ko&target=en&text=" + inputString[i]);  // 요청변수 설정
                request.ContentType = "application/x-www-form-urlencoded";
                request.ContentLength = byteDataParams.Length;
                Stream st = request.GetRequestStream();
                st.Write(byteDataParams, 0, byteDataParams.Length);
                st.Close(); // 웹소캣을 열어서 보내줌

                HttpWebResponse response = (HttpWebResponse)request.GetResponse(); // 리스폰 열어서 받음
                Stream stream = response.GetResponseStream();
                StreamReader reader = new StreamReader(stream, Encoding.UTF8); // 인코딩해서 써줌

                //메세지에서 글자 잘라옴
                string text = reader.ReadToEnd();
                const string key = "translatedText";
                int first = text.IndexOf("translatedText") + key.Length + 3;
                int last = text.Substring(first, text.Length - first).IndexOf("\"");

                stream.Close();
                response.Close();
                reader.Close();
                textBox2.Text = text.Substring(first, last) + "\n";
            }
        }
	}
}
