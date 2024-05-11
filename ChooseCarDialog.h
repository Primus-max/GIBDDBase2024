#pragma once
#include "car.h"
#include "CarRepository.h"
#include "ChooseCarDialogHelper.h"


namespace GIBDDBase2024 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ChooseCarDialog
	/// </summary>
	public ref class ChooseCarDialog : public System::Windows::Forms::Form
	{
	public:
		ChooseCarDialog(void)
		{
			InitializeComponent();			
		}

	public: 
		delegate void CarSelectedEventHandler(int carId);
		event CarSelectedEventHandler^ CarSelected;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ChooseCarDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ ChooseCarDialogDataGridView;
	protected:

	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ brand;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ reg_number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ color;




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
			this->ChooseCarDialogDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->brand = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->reg_number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->color = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ChooseCarDialogDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// ChooseCarDialogDataGridView
			// 
			this->ChooseCarDialogDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ChooseCarDialogDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->id,
					this->brand, this->reg_number, this->color
			});
			this->ChooseCarDialogDataGridView->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->ChooseCarDialogDataGridView->Location = System::Drawing::Point(0, 38);
			this->ChooseCarDialogDataGridView->Name = L"ChooseCarDialogDataGridView";
			this->ChooseCarDialogDataGridView->Size = System::Drawing::Size(349, 423);
			this->ChooseCarDialogDataGridView->TabIndex = 0;
			this->ChooseCarDialogDataGridView->CellDoubleClick += gcnew DataGridViewCellEventHandler(this, &ChooseCarDialog::ChooseCarDialogDataGridView_CellDoubleClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(68, 10);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(241, 9);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// id
			// 
			this->id->Frozen = true;
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Width = 50;
			// 
			// brand
			// 
			this->brand->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->brand->Frozen = true;
			this->brand->HeaderText = L"Марка";
			this->brand->Name = L"brand";
			this->brand->ReadOnly = true;
			this->brand->Width = 102;
			// 
			// reg_number
			// 
			this->reg_number->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->reg_number->HeaderText = L"Номер";
			this->reg_number->Name = L"reg_number";
			this->reg_number->ReadOnly = true;
			// 
			// color
			// 
			this->color->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->color->HeaderText = L"Цвет";
			this->color->Name = L"color";
			this->color->ReadOnly = true;
			// 
			// ChooseCarDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(349, 461);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->ChooseCarDialogDataGridView);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(365, 500);
			this->MinimumSize = System::Drawing::Size(365, 500);
			this->Name = L"ChooseCarDialog";
			this->Text = L"Выбор авто";
			this->Load += gcnew System::EventHandler(this, &ChooseCarDialog::Dialog_Loaded);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ChooseCarDialogDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Dialog_Loaded(System::Object^ sender, System::EventArgs^ e) {
		FillCarListViewAtChooseDialog(ChooseCarDialogDataGridView);		
	}

	private: Void ChooseCarDialogDataGridView_CellDoubleClick(Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;
		int carId = System::Convert::ToInt32(ChooseCarDialogDataGridView->Rows[e->RowIndex]->Cells["id"]->Value);
		CarSelected(carId);
		this->Close();
	}

	};
}
