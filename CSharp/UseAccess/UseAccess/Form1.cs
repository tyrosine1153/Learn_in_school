using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UseAccess
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			// TODO: 이 코드는 데이터를 '비디오_관리DataSet1.비디오_대여관리' 테이블에 로드합니다. 필요 시 이 코드를 이동하거나 제거할 수 있습니다.
			this.비디오_대여관리TableAdapter.Fill(this.비디오_관리DataSet1.비디오_대여관리);
			// TODO: 이 코드는 데이터를 '비디오_관리DataSet1.비디오_대여관리' 테이블에 로드합니다. 필요 시 이 코드를 이동하거나 제거할 수 있습니다.
			this.비디오_대여관리TableAdapter.Fill(this.비디오_관리DataSet1.비디오_대여관리);

		}

		private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
		{

		}

		private void fillByToolStripButton_Click(object sender, EventArgs e)
		{
			try
			{
				this.비디오_대여관리TableAdapter.FillBy(this.비디오_관리DataSet1.비디오_대여관리, "김수정");
			}
			catch (System.Exception ex)
			{
				System.Windows.Forms.MessageBox.Show(ex.Message);
			}

		}

		private void 비디오대여관리BindingSource_CurrentChanged(object sender, EventArgs e)
		{

		}

		private void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
		{

		}
	}
}
