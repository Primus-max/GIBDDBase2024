#pragma once
#include "MainFormHelper.h"
#include "СarManager.h"
#include "PenaltyManager.h"

namespace GIBDDBase2024 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MainForm : public Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ CarTabControl;
	private: System::Windows::Forms::TabPage^ CarTabPage;
	private: System::Windows::Forms::TabPage^ PenaltiesTabPage;
	private: System::Windows::Forms::Button^ AddCarBatton;


	private: System::Windows::Forms::DataGridView^ CarsDataGridView;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ reg_number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ brand;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ length;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clearance;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ engine_capacity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ engine_power;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ wheel_diameter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ region;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ color;
	private: System::Windows::Forms::DataGridView^ PenaltiesDataGridView;








	private: System::Windows::Forms::TabPage^ PenaltyTypes;
	private: System::Windows::Forms::DataGridView^ PenaltyTypesDataGridView;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penaltyTypeId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penaltyType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penalty_type_price;

	private: System::Windows::Forms::Button^ DeleteCarBtn;

	private: System::Windows::Forms::Button^ UpdateCarBtn;
	private: System::Windows::Forms::Label^ DescriptionControlsCars;
	private: System::Windows::Forms::Label^ DescriptionControlsPenalties;
	private: System::Windows::Forms::Button^ DeletePenaltyButton;
	private: System::Windows::Forms::Button^ UpdatePenaltyBatton;
	private: System::Windows::Forms::Button^ AddPenaltyBatton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penalty_type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ date_p;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ amount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ carId;





	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->CarTabControl = (gcnew System::Windows::Forms::TabControl());
			this->CarTabPage = (gcnew System::Windows::Forms::TabPage());
			this->DescriptionControlsCars = (gcnew System::Windows::Forms::Label());
			this->DeleteCarBtn = (gcnew System::Windows::Forms::Button());
			this->UpdateCarBtn = (gcnew System::Windows::Forms::Button());
			this->CarsDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->brand = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->length = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clearance = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->engine_capacity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->engine_power = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->wheel_diameter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->region = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->color = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AddCarBatton = (gcnew System::Windows::Forms::Button());
			this->PenaltiesTabPage = (gcnew System::Windows::Forms::TabPage());
			this->DeletePenaltyButton = (gcnew System::Windows::Forms::Button());
			this->UpdatePenaltyBatton = (gcnew System::Windows::Forms::Button());
			this->AddPenaltyBatton = (gcnew System::Windows::Forms::Button());
			this->DescriptionControlsPenalties = (gcnew System::Windows::Forms::Label());
			this->PenaltiesDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->PenaltyTypes = (gcnew System::Windows::Forms::TabPage());
			this->PenaltyTypesDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->penaltyTypeId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->penaltyType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->penalty_type_price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->penalty_type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date_p = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->carId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CarTabControl->SuspendLayout();
			this->CarTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CarsDataGridView))->BeginInit();
			this->PenaltiesTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PenaltiesDataGridView))->BeginInit();
			this->PenaltyTypes->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PenaltyTypesDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// CarTabControl
			// 
			this->CarTabControl->Controls->Add(this->CarTabPage);
			this->CarTabControl->Controls->Add(this->PenaltiesTabPage);
			this->CarTabControl->Controls->Add(this->PenaltyTypes);
			this->CarTabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CarTabControl->Location = System::Drawing::Point(0, 0);
			this->CarTabControl->Name = L"CarTabControl";
			this->CarTabControl->SelectedIndex = 0;
			this->CarTabControl->Size = System::Drawing::Size(1278, 685);
			this->CarTabControl->TabIndex = 0;
			// 
			// CarTabPage
			// 
			this->CarTabPage->Controls->Add(this->DescriptionControlsCars);
			this->CarTabPage->Controls->Add(this->DeleteCarBtn);
			this->CarTabPage->Controls->Add(this->UpdateCarBtn);
			this->CarTabPage->Controls->Add(this->CarsDataGridView);
			this->CarTabPage->Controls->Add(this->AddCarBatton);
			this->CarTabPage->Location = System::Drawing::Point(4, 22);
			this->CarTabPage->Name = L"CarTabPage";
			this->CarTabPage->Padding = System::Windows::Forms::Padding(3);
			this->CarTabPage->Size = System::Drawing::Size(1270, 659);
			this->CarTabPage->TabIndex = 0;
			this->CarTabPage->Text = L"Авто";
			this->CarTabPage->UseVisualStyleBackColor = true;
			// 
			// DescriptionControlsCars
			// 
			this->DescriptionControlsCars->AutoSize = true;
			this->DescriptionControlsCars->Location = System::Drawing::Point(523, 11);
			this->DescriptionControlsCars->Name = L"DescriptionControlsCars";
			this->DescriptionControlsCars->Size = System::Drawing::Size(526, 39);
			this->DescriptionControlsCars->TabIndex = 6;
			this->DescriptionControlsCars->Text = resources->GetString(L"DescriptionControlsCars.Text");
			// 
			// DeleteCarBtn
			// 
			this->DeleteCarBtn->Location = System::Drawing::Point(292, 11);
			this->DeleteCarBtn->Name = L"DeleteCarBtn";
			this->DeleteCarBtn->Size = System::Drawing::Size(135, 23);
			this->DeleteCarBtn->TabIndex = 5;
			this->DeleteCarBtn->Text = L"Удалить";
			this->DeleteCarBtn->UseVisualStyleBackColor = true;
			this->DeleteCarBtn->Click += gcnew System::EventHandler(this, &MainForm::DeleteCarBtn_Click);
			// 
			// UpdateCarBtn
			// 
			this->UpdateCarBtn->Location = System::Drawing::Point(151, 11);
			this->UpdateCarBtn->Name = L"UpdateCarBtn";
			this->UpdateCarBtn->Size = System::Drawing::Size(135, 23);
			this->UpdateCarBtn->TabIndex = 4;
			this->UpdateCarBtn->Text = L"Обновить";
			this->UpdateCarBtn->UseVisualStyleBackColor = true;
			this->UpdateCarBtn->Click += gcnew System::EventHandler(this, &MainForm::UpdateCarBtn_Click);
			// 
			// CarsDataGridView
			// 
			this->CarsDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->CarsDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->id,
					this->brand, this->length, this->clearance, this->engine_capacity, this->engine_power, this->wheel_diameter, this->number, this->region,
					this->color
			});
			this->CarsDataGridView->Location = System::Drawing::Point(3, 59);
			this->CarsDataGridView->Name = L"CarsDataGridView";
			this->CarsDataGridView->Size = System::Drawing::Size(1264, 598);
			this->CarsDataGridView->TabIndex = 3;
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			// 
			// brand
			// 
			this->brand->HeaderText = L"Марка";
			this->brand->Name = L"brand";
			// 
			// length
			// 
			this->length->HeaderText = L"Длина (см.)";
			this->length->Name = L"length";
			// 
			// clearance
			// 
			this->clearance->HeaderText = L"Просвет (мм.)";
			this->clearance->Name = L"clearance";
			// 
			// engine_capacity
			// 
			this->engine_capacity->HeaderText = L"Объём (д./л.)";
			this->engine_capacity->Name = L"engine_capacity";
			// 
			// engine_power
			// 
			this->engine_power->HeaderText = L"Мощность (д./лс)";
			this->engine_power->Name = L"engine_power";
			// 
			// wheel_diameter
			// 
			this->wheel_diameter->HeaderText = L"Радиус (к.)";
			this->wheel_diameter->Name = L"wheel_diameter";
			// 
			// number
			// 
			this->number->HeaderText = L"Номер";
			this->number->Name = L"number";
			// 
			// region
			// 
			this->region->HeaderText = L"Регион";
			this->region->Name = L"region";
			// 
			// color
			// 
			this->color->HeaderText = L"Цвет";
			this->color->Name = L"color";
			// 
			// AddCarBatton
			// 
			this->AddCarBatton->Location = System::Drawing::Point(10, 11);
			this->AddCarBatton->Name = L"AddCarBatton";
			this->AddCarBatton->Size = System::Drawing::Size(135, 23);
			this->AddCarBatton->TabIndex = 1;
			this->AddCarBatton->Text = L"Добавить";
			this->AddCarBatton->UseVisualStyleBackColor = true;
			this->AddCarBatton->Click += gcnew System::EventHandler(this, &MainForm::AddCarButton_Click);
			// 
			// PenaltiesTabPage
			// 
			this->PenaltiesTabPage->Controls->Add(this->DeletePenaltyButton);
			this->PenaltiesTabPage->Controls->Add(this->UpdatePenaltyBatton);
			this->PenaltiesTabPage->Controls->Add(this->AddPenaltyBatton);
			this->PenaltiesTabPage->Controls->Add(this->DescriptionControlsPenalties);
			this->PenaltiesTabPage->Controls->Add(this->PenaltiesDataGridView);
			this->PenaltiesTabPage->Location = System::Drawing::Point(4, 22);
			this->PenaltiesTabPage->Name = L"PenaltiesTabPage";
			this->PenaltiesTabPage->Padding = System::Windows::Forms::Padding(3);
			this->PenaltiesTabPage->Size = System::Drawing::Size(1270, 659);
			this->PenaltiesTabPage->TabIndex = 1;
			this->PenaltiesTabPage->Text = L"Штрафы";
			this->PenaltiesTabPage->UseVisualStyleBackColor = true;
			// 
			// DeletePenaltyButton
			// 
			this->DeletePenaltyButton->Location = System::Drawing::Point(290, 18);
			this->DeletePenaltyButton->Name = L"DeletePenaltyButton";
			this->DeletePenaltyButton->Size = System::Drawing::Size(135, 23);
			this->DeletePenaltyButton->TabIndex = 10;
			this->DeletePenaltyButton->Text = L"Удалить";
			this->DeletePenaltyButton->UseVisualStyleBackColor = true;
			this->DeletePenaltyButton->Click += gcnew System::EventHandler(this, &MainForm::DeletePenaltyButton_Click);
			// 
			// UpdatePenaltyBatton
			// 
			this->UpdatePenaltyBatton->Location = System::Drawing::Point(149, 18);
			this->UpdatePenaltyBatton->Name = L"UpdatePenaltyBatton";
			this->UpdatePenaltyBatton->Size = System::Drawing::Size(135, 23);
			this->UpdatePenaltyBatton->TabIndex = 9;
			this->UpdatePenaltyBatton->Text = L"Обновить";
			this->UpdatePenaltyBatton->UseVisualStyleBackColor = true;
			this->UpdatePenaltyBatton->Click += gcnew System::EventHandler(this, &MainForm::UpdatePenaltyBatton_Click);
			// 
			// AddPenaltyBatton
			// 
			this->AddPenaltyBatton->Location = System::Drawing::Point(8, 18);
			this->AddPenaltyBatton->Name = L"AddPenaltyBatton";
			this->AddPenaltyBatton->Size = System::Drawing::Size(135, 23);
			this->AddPenaltyBatton->TabIndex = 8;
			this->AddPenaltyBatton->Text = L"Добавить";
			this->AddPenaltyBatton->UseVisualStyleBackColor = true;
			this->AddPenaltyBatton->Click += gcnew System::EventHandler(this, &MainForm::AddPenaltyBatton_Click);
			// 
			// DescriptionControlsPenalties
			// 
			this->DescriptionControlsPenalties->AutoSize = true;
			this->DescriptionControlsPenalties->Location = System::Drawing::Point(507, 3);
			this->DescriptionControlsPenalties->Name = L"DescriptionControlsPenalties";
			this->DescriptionControlsPenalties->Size = System::Drawing::Size(542, 39);
			this->DescriptionControlsPenalties->TabIndex = 7;
			this->DescriptionControlsPenalties->Text = resources->GetString(L"DescriptionControlsPenalties.Text");
			// 
			// PenaltiesDataGridView
			// 
			this->PenaltiesDataGridView->AllowUserToOrderColumns = true;
			this->PenaltiesDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->PenaltiesDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->penalty_type,
					this->date_p, this->amount, this->carId
			});
			this->PenaltiesDataGridView->Location = System::Drawing::Point(3, 119);
			this->PenaltiesDataGridView->Name = L"PenaltiesDataGridView";
			this->PenaltiesDataGridView->Size = System::Drawing::Size(1046, 537);
			this->PenaltiesDataGridView->TabIndex = 0;
			// 
			// PenaltyTypes
			// 
			this->PenaltyTypes->Controls->Add(this->PenaltyTypesDataGridView);
			this->PenaltyTypes->Location = System::Drawing::Point(4, 22);
			this->PenaltyTypes->Name = L"PenaltyTypes";
			this->PenaltyTypes->Padding = System::Windows::Forms::Padding(3);
			this->PenaltyTypes->Size = System::Drawing::Size(1270, 659);
			this->PenaltyTypes->TabIndex = 2;
			this->PenaltyTypes->Text = L"Виды нарушений";
			this->PenaltyTypes->UseVisualStyleBackColor = true;
			// 
			// PenaltyTypesDataGridView
			// 
			this->PenaltyTypesDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->PenaltyTypesDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->penaltyTypeId,
					this->penaltyType, this->penalty_type_price
			});
			this->PenaltyTypesDataGridView->Location = System::Drawing::Point(3, 80);
			this->PenaltyTypesDataGridView->Name = L"PenaltyTypesDataGridView";
			this->PenaltyTypesDataGridView->Size = System::Drawing::Size(1264, 579);
			this->PenaltyTypesDataGridView->TabIndex = 0;
			// 
			// penaltyTypeId
			// 
			this->penaltyTypeId->HeaderText = L"Id";
			this->penaltyTypeId->Name = L"penaltyTypeId";
			this->penaltyTypeId->ReadOnly = true;
			// 
			// penaltyType
			// 
			this->penaltyType->HeaderText = L"Вид нарушения";
			this->penaltyType->Name = L"penaltyType";
			this->penaltyType->Width = 500;
			// 
			// penalty_type_price
			// 
			this->penalty_type_price->HeaderText = L"Стоимость";
			this->penalty_type_price->Name = L"penalty_type_price";
			// 
			// penalty_type
			// 
			this->penalty_type->HeaderText = L"id штрафа";
			this->penalty_type->Name = L"penalty_type";
			this->penalty_type->ReadOnly = true;
			this->penalty_type->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// date_p
			// 
			dataGridViewCellStyle4->NullValue = nullptr;
			this->date_p->DefaultCellStyle = dataGridViewCellStyle4;
			this->date_p->HeaderText = L"Дата";
			this->date_p->Name = L"date_p";
			this->date_p->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->date_p->Width = 150;
			// 
			// amount
			// 
			this->amount->HeaderText = L"Сумма";
			this->amount->Name = L"amount";
			this->amount->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->amount->Width = 150;
			// 
			// carId
			// 
			this->carId->HeaderText = L"Авто";
			this->carId->Name = L"carId";
			this->carId->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->carId->Width = 150;
			// 
			// MainForm
			// 
			this->ClientSize = System::Drawing::Size(1278, 685);
			this->Controls->Add(this->CarTabControl);
			this->Name = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Loaded);
			this->CarTabControl->ResumeLayout(false);
			this->CarTabPage->ResumeLayout(false);
			this->CarTabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CarsDataGridView))->EndInit();
			this->PenaltiesTabPage->ResumeLayout(false);
			this->PenaltiesTabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PenaltiesDataGridView))->EndInit();
			this->PenaltyTypes->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PenaltyTypesDataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion	

	private: System::Void MainForm_Loaded(System::Object^ sender, System::EventArgs^ e) {

		FillCarListView(CarsDataGridView);
		FillPenaltiesListView(PenaltiesDataGridView);
		FillPenaltyTypesListView(PenaltyTypesDataGridView);
	}
	

#pragma region CRUD авто
	private: System::Void AddCarButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddCarAtDb(CarsDataGridView);		
	}
	private: System::Void UpdateCarBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		UpdateCarAtDb(CarsDataGridView);
	}
	private: System::Void DeleteCarBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		DeleteCarAtDb(CarsDataGridView);
	}
#pragma endregion

#pragma region CRUD Штрафы
	private: System::Void AddPenaltyBatton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddPenaltyAtDb(PenaltiesDataGridView);
	}

	private: System::Void UpdatePenaltyBatton_Click(System::Object^ sender, System::EventArgs^ e) {
		UpdatePenaltyAtDb(PenaltiesDataGridView);
	}

	private: System::Void DeletePenaltyButton_Click(System::Object^ sender, System::EventArgs^ e) {
		DeletePenaltyAtDb(PenaltiesDataGridView);
	}
#pragma endregion

	};
}
