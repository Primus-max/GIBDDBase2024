#pragma once
#include "ChoosePenaltyDialogHelper.h"
namespace GIBDDBase2024 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ChoosePenaltyDialog
	/// </summary>
	public ref class ChoosePenaltyDialog : public System::Windows::Forms::Form
	{
	public:
		ChoosePenaltyDialog(void)
		{
			InitializeComponent();
		}

	public:
		delegate void PenaltyTypeSelectedEventHandler(int penaltyTypeId);
		event PenaltyTypeSelectedEventHandler^ SelectedPenaltyType;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ChoosePenaltyDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ ChoosePenaltyDialogDataGridView;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PenaltyTypeIdColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PenaltyTypeColumn;
	private: System::Windows::Forms::Label^ label1;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ChoosePenaltyDialogDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->PenaltyTypeIdColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PenaltyTypeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ChoosePenaltyDialogDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// ChoosePenaltyDialogDataGridView
			// 
			this->ChoosePenaltyDialogDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ChoosePenaltyDialogDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->PenaltyTypeIdColumn,
					this->PenaltyTypeColumn
			});
			this->ChoosePenaltyDialogDataGridView->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->ChoosePenaltyDialogDataGridView->Location = System::Drawing::Point(0, 25);
			this->ChoosePenaltyDialogDataGridView->Name = L"ChoosePenaltyDialogDataGridView";
			this->ChoosePenaltyDialogDataGridView->Size = System::Drawing::Size(484, 536);
			this->ChoosePenaltyDialogDataGridView->TabIndex = 1;
			// 
			// PenaltyTypeIdColumn
			// 
			this->PenaltyTypeIdColumn->Frozen = true;
			this->PenaltyTypeIdColumn->HeaderText = L"id";
			this->PenaltyTypeIdColumn->Name = L"PenaltyTypeIdColumn";
			this->PenaltyTypeIdColumn->ReadOnly = true;
			this->PenaltyTypeIdColumn->Width = 50;
			// 
			// PenaltyTypeColumn
			// 
			this->PenaltyTypeColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->PenaltyTypeColumn->HeaderText = L"Нарушение";
			this->PenaltyTypeColumn->Name = L"PenaltyTypeColumn";
			this->PenaltyTypeColumn->ReadOnly = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(226, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Выбор нарушения: двойной клие по ячейки";
			// 
			// ChoosePenaltyDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 561);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ChoosePenaltyDialogDataGridView);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(500, 600);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(500, 600);
			this->Name = L"ChoosePenaltyDialog";
			this->Text = L"Выбор штрафа";
			this->Load += gcnew System::EventHandler(this, &ChoosePenaltyDialog::Dialog_Loaded);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ChoosePenaltyDialogDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: Void ChoosePenaltyCell_DoubleClick(Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;
		int penaltyTypeId = System::Convert::ToInt32(ChoosePenaltyDialogDataGridView->Rows[e->RowIndex]->Cells["PenaltyTypeIdColumn"]->Value);
		SelectedPenaltyType(penaltyTypeId);
		this->Close();
	}

	private: System::Void Dialog_Loaded(System::Object^ sender, System::EventArgs^ e) {
		FillPenaltyTypeListViewAtChooseDialog(ChoosePenaltyDialogDataGridView);
	}
};
}
