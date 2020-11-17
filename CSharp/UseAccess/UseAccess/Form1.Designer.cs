namespace UseAccess
{
	partial class Form1
	{
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		/// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form 디자이너에서 생성한 코드

		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.비디오_관리DataSet1 = new UseAccess.비디오_관리DataSet();
			this.dataGridView1 = new System.Windows.Forms.DataGridView();
			this.비디오대여관리BindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.비디오_대여관리TableAdapter = new UseAccess.비디오_관리DataSetTableAdapters.비디오_대여관리TableAdapter();
			this.번호DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.성명DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.전화번호DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.주소DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.대여일DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.비디오명DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.대여료DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.반환일DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.메모DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			((System.ComponentModel.ISupportInitialize)(this.비디오_관리DataSet1)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.비디오대여관리BindingSource)).BeginInit();
			this.SuspendLayout();
			// 
			// 비디오_관리DataSet1
			// 
			this.비디오_관리DataSet1.DataSetName = "비디오_관리DataSet";
			this.비디오_관리DataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
			// 
			// dataGridView1
			// 
			this.dataGridView1.AutoGenerateColumns = false;
			this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.번호DataGridViewTextBoxColumn,
            this.성명DataGridViewTextBoxColumn,
            this.전화번호DataGridViewTextBoxColumn,
            this.주소DataGridViewTextBoxColumn,
            this.대여일DataGridViewTextBoxColumn,
            this.비디오명DataGridViewTextBoxColumn,
            this.대여료DataGridViewTextBoxColumn,
            this.반환일DataGridViewTextBoxColumn,
            this.메모DataGridViewTextBoxColumn});
			this.dataGridView1.DataSource = this.비디오대여관리BindingSource;
			this.dataGridView1.Location = new System.Drawing.Point(12, 261);
			this.dataGridView1.Name = "dataGridView1";
			this.dataGridView1.RowTemplate.Height = 23;
			this.dataGridView1.Size = new System.Drawing.Size(728, 150);
			this.dataGridView1.TabIndex = 0;
			this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick_1);
			// 
			// 비디오대여관리BindingSource
			// 
			this.비디오대여관리BindingSource.DataMember = "비디오 대여관리";
			this.비디오대여관리BindingSource.DataSource = this.비디오_관리DataSet1;
			// 
			// 비디오_대여관리TableAdapter
			// 
			this.비디오_대여관리TableAdapter.ClearBeforeFill = true;
			// 
			// 번호DataGridViewTextBoxColumn
			// 
			this.번호DataGridViewTextBoxColumn.DataPropertyName = "번호";
			this.번호DataGridViewTextBoxColumn.HeaderText = "번호";
			this.번호DataGridViewTextBoxColumn.Name = "번호DataGridViewTextBoxColumn";
			// 
			// 성명DataGridViewTextBoxColumn
			// 
			this.성명DataGridViewTextBoxColumn.DataPropertyName = "성명";
			this.성명DataGridViewTextBoxColumn.HeaderText = "성명";
			this.성명DataGridViewTextBoxColumn.Name = "성명DataGridViewTextBoxColumn";
			// 
			// 전화번호DataGridViewTextBoxColumn
			// 
			this.전화번호DataGridViewTextBoxColumn.DataPropertyName = "전화번호";
			this.전화번호DataGridViewTextBoxColumn.HeaderText = "전화번호";
			this.전화번호DataGridViewTextBoxColumn.Name = "전화번호DataGridViewTextBoxColumn";
			// 
			// 주소DataGridViewTextBoxColumn
			// 
			this.주소DataGridViewTextBoxColumn.DataPropertyName = "주소";
			this.주소DataGridViewTextBoxColumn.HeaderText = "주소";
			this.주소DataGridViewTextBoxColumn.Name = "주소DataGridViewTextBoxColumn";
			// 
			// 대여일DataGridViewTextBoxColumn
			// 
			this.대여일DataGridViewTextBoxColumn.DataPropertyName = "대여일";
			this.대여일DataGridViewTextBoxColumn.HeaderText = "대여일";
			this.대여일DataGridViewTextBoxColumn.Name = "대여일DataGridViewTextBoxColumn";
			// 
			// 비디오명DataGridViewTextBoxColumn
			// 
			this.비디오명DataGridViewTextBoxColumn.DataPropertyName = "비디오명";
			this.비디오명DataGridViewTextBoxColumn.HeaderText = "비디오명";
			this.비디오명DataGridViewTextBoxColumn.Name = "비디오명DataGridViewTextBoxColumn";
			// 
			// 대여료DataGridViewTextBoxColumn
			// 
			this.대여료DataGridViewTextBoxColumn.DataPropertyName = "대여료";
			this.대여료DataGridViewTextBoxColumn.HeaderText = "대여료";
			this.대여료DataGridViewTextBoxColumn.Name = "대여료DataGridViewTextBoxColumn";
			// 
			// 반환일DataGridViewTextBoxColumn
			// 
			this.반환일DataGridViewTextBoxColumn.DataPropertyName = "반환일";
			this.반환일DataGridViewTextBoxColumn.HeaderText = "반환일";
			this.반환일DataGridViewTextBoxColumn.Name = "반환일DataGridViewTextBoxColumn";
			// 
			// 메모DataGridViewTextBoxColumn
			// 
			this.메모DataGridViewTextBoxColumn.DataPropertyName = "메모";
			this.메모DataGridViewTextBoxColumn.HeaderText = "메모";
			this.메모DataGridViewTextBoxColumn.Name = "메모DataGridViewTextBoxColumn";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.dataGridView1);
			this.Name = "Form1";
			this.Text = "Form1";
			this.Load += new System.EventHandler(this.Form1_Load);
			((System.ComponentModel.ISupportInitialize)(this.비디오_관리DataSet1)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.비디오대여관리BindingSource)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private 비디오_관리DataSet 비디오_관리DataSet1;
		private System.Windows.Forms.DataGridView dataGridView1;
		private System.Windows.Forms.BindingSource 비디오대여관리BindingSource;
		private 비디오_관리DataSetTableAdapters.비디오_대여관리TableAdapter 비디오_대여관리TableAdapter;
		private System.Windows.Forms.DataGridViewTextBoxColumn 번호DataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn 성명DataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn 전화번호DataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn 주소DataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn 대여일DataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn 비디오명DataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn 대여료DataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn 반환일DataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn 메모DataGridViewTextBoxColumn;
	}
}

