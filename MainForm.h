#pragma once
#include "car.h"
#include "CarRepository.h"
#include "penalty.h"
#include "Penaltyrepository.h"
#include "PenaltyType.h"
#include "PenaltyTypeRepository.h"


using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::OleDb;

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





	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penalty_type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ date_p;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ amount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ carId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ reason;
	private: System::Windows::Forms::TabPage^ PenaltyTypes;
	private: System::Windows::Forms::DataGridView^ PenaltyTypesDataGridView;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penaltyTypeId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penaltyType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penalty_type_price;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Button^ DeleteCarBtn;

	private: System::Windows::Forms::Button^ UpdateCarBtn;
	private: System::Windows::Forms::Label^ label1;




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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->CarTabControl = (gcnew System::Windows::Forms::TabControl());
			this->CarTabPage = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->PenaltiesDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->penalty_type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date_p = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->carId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->reason = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PenaltyTypes = (gcnew System::Windows::Forms::TabPage());
			this->PenaltyTypesDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->penaltyTypeId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->penaltyType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->penalty_type_price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
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
			this->CarTabControl->Size = System::Drawing::Size(1060, 685);
			this->CarTabControl->TabIndex = 0;
			// 
			// CarTabPage
			// 
			this->CarTabPage->Controls->Add(this->label1);
			this->CarTabPage->Controls->Add(this->DeleteCarBtn);
			this->CarTabPage->Controls->Add(this->UpdateCarBtn);
			this->CarTabPage->Controls->Add(this->CarsDataGridView);
			this->CarTabPage->Controls->Add(this->AddCarBatton);
			this->CarTabPage->Location = System::Drawing::Point(4, 22);
			this->CarTabPage->Name = L"CarTabPage";
			this->CarTabPage->Padding = System::Windows::Forms::Padding(3);
			this->CarTabPage->Size = System::Drawing::Size(1052, 659);
			this->CarTabPage->TabIndex = 0;
			this->CarTabPage->Text = L"Авто";
			this->CarTabPage->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(520, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(526, 39);
			this->label1->TabIndex = 6;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// DeleteCarBtn
			// 
			this->DeleteCarBtn->Location = System::Drawing::Point(285, 6);
			this->DeleteCarBtn->Name = L"DeleteCarBtn";
			this->DeleteCarBtn->Size = System::Drawing::Size(135, 23);
			this->DeleteCarBtn->TabIndex = 5;
			this->DeleteCarBtn->Text = L"Удалить";
			this->DeleteCarBtn->UseVisualStyleBackColor = true;
			this->DeleteCarBtn->Click += gcnew System::EventHandler(this, &MainForm::DeleteCarBtn_Click);
			// 
			// UpdateCarBtn
			// 
			this->UpdateCarBtn->Location = System::Drawing::Point(144, 6);
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
			this->CarsDataGridView->Location = System::Drawing::Point(3, 48);
			this->CarsDataGridView->Name = L"CarsDataGridView";
			this->CarsDataGridView->Size = System::Drawing::Size(1047, 609);
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
			this->AddCarBatton->Location = System::Drawing::Point(3, 6);
			this->AddCarBatton->Name = L"AddCarBatton";
			this->AddCarBatton->Size = System::Drawing::Size(135, 23);
			this->AddCarBatton->TabIndex = 1;
			this->AddCarBatton->Text = L"Сохранить";
			this->AddCarBatton->UseVisualStyleBackColor = true;
			this->AddCarBatton->Click += gcnew System::EventHandler(this, &MainForm::AddCarButton_Click);
			// 
			// PenaltiesTabPage
			// 
			this->PenaltiesTabPage->Controls->Add(this->button2);
			this->PenaltiesTabPage->Controls->Add(this->PenaltiesDataGridView);
			this->PenaltiesTabPage->Location = System::Drawing::Point(4, 22);
			this->PenaltiesTabPage->Name = L"PenaltiesTabPage";
			this->PenaltiesTabPage->Padding = System::Windows::Forms::Padding(3);
			this->PenaltiesTabPage->Size = System::Drawing::Size(1052, 659);
			this->PenaltiesTabPage->TabIndex = 1;
			this->PenaltiesTabPage->Text = L"Штрафы";
			this->PenaltiesTabPage->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(834, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(212, 97);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Поиск";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// PenaltiesDataGridView
			// 
			this->PenaltiesDataGridView->AllowUserToOrderColumns = true;
			this->PenaltiesDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->PenaltiesDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->penalty_type,
					this->date_p, this->amount, this->carId, this->reason
			});
			this->PenaltiesDataGridView->Dock = System::Windows::Forms::DockStyle::Left;
			this->PenaltiesDataGridView->Location = System::Drawing::Point(3, 3);
			this->PenaltiesDataGridView->Name = L"PenaltiesDataGridView";
			this->PenaltiesDataGridView->Size = System::Drawing::Size(809, 653);
			this->PenaltiesDataGridView->TabIndex = 0;
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
			dataGridViewCellStyle1->NullValue = nullptr;
			this->date_p->DefaultCellStyle = dataGridViewCellStyle1;
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
			// reason
			// 
			this->reason->HeaderText = L"Причина";
			this->reason->Name = L"reason";
			this->reason->Width = 200;
			// 
			// PenaltyTypes
			// 
			this->PenaltyTypes->Controls->Add(this->PenaltyTypesDataGridView);
			this->PenaltyTypes->Location = System::Drawing::Point(4, 22);
			this->PenaltyTypes->Name = L"PenaltyTypes";
			this->PenaltyTypes->Padding = System::Windows::Forms::Padding(3);
			this->PenaltyTypes->Size = System::Drawing::Size(1052, 659);
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
			this->PenaltyTypesDataGridView->Location = System::Drawing::Point(3, 164);
			this->PenaltyTypesDataGridView->Name = L"PenaltyTypesDataGridView";
			this->PenaltyTypesDataGridView->Size = System::Drawing::Size(1049, 495);
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
			// toolTip1
			// 
			this->toolTip1->ToolTipTitle = L"ЛОРДЛОРДЛОРДЛОР";
			// 
			// MainForm
			// 
			this->ClientSize = System::Drawing::Size(1060, 685);
			this->Controls->Add(this->CarTabControl);
			this->Name = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Loaded);
			this->CarTabControl->ResumeLayout(false);
			this->CarTabPage->ResumeLayout(false);
			this->CarTabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CarsDataGridView))->EndInit();
			this->PenaltiesTabPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PenaltiesDataGridView))->EndInit();
			this->PenaltyTypes->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PenaltyTypesDataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion	

	private: System::Void FillCarListView(DataGridView^ dataGridView, List<Car^>^ cars)
	{
		dataGridView->Rows->Clear();

		for each (Car ^ car in cars)
		{
			array<Object^>^ rowData = gcnew array<Object^>(10);

			rowData[0] = car->id;
			rowData[1] = car->brand;
			rowData[2] = car->length;
			rowData[3] = car->clearance;
			rowData[4] = car->engineCapacity;
			rowData[5] = car->enginePower;
			rowData[6] = car->wheelDiameter;
			rowData[7] = car->reg_number;
			rowData[8] = car->region;
			rowData[9] = car->color;

			dataGridView->Rows->Add(rowData);
		}
	}
	private: System::Void FillPenaltiesListView(DataGridView^ dataGridView, List<Penalty^>^ penalties) {
		dataGridView->Rows->Clear();

		for each (Penalty ^ penalty in penalties)
		{
			array<Object^>^ rowData = gcnew array<Object^>(4);
			rowData[0] = penalty->penaltyType;
			rowData[1] = penalty->datP;
			rowData[2] = penalty->amount;
			rowData[3] = penalty->carId;

			dataGridView->Rows->Add(rowData);
		}
	}
	private: System::Void FillPenaltyTypesListView(DataGridView^ dataGridView, List<PenaltyType^>^ penaltyTypes) {
		dataGridView->Rows->Clear();

		for each (PenaltyType ^ penaltyType in penaltyTypes)
		{
			array<Object^>^ rowData = gcnew array<Object^>(3);
			rowData[0] = penaltyType->id;
			rowData[1] = penaltyType->penaltyType;
			rowData[2] = penaltyType->price;		

			dataGridView->Rows->Add(rowData);
		}
	}
	private: System::Void MainForm_Loaded(System::Object^ sender, System::EventArgs^ e) {

		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
		CarRepository^ carRepos = gcnew CarRepository(connectionString);
		List<Car^>^ cars = carRepos->GetAll();
		FillCarListView(CarsDataGridView, cars);

		PenaltyRepository^ penaltyRepos = gcnew PenaltyRepository(connectionString);
		List<Penalty^>^ penalties = penaltyRepos->GetAll();
		FillPenaltiesListView(PenaltiesDataGridView, penalties);

		PenaltyTypeRepository^ penaltyTypeRepos = gcnew PenaltyTypeRepository(connectionString);
		List<PenaltyType^>^ penaltyTypes = penaltyTypeRepos->GetAll();
		FillPenaltyTypesListView(PenaltyTypesDataGridView, penaltyTypes);

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
		PenaltyRepository^ penaltyRepos = gcnew PenaltyRepository(connectionString);

		List<Penalty^>^ penalties = penaltyRepos->GetAll();
		FillPenaltiesListView(PenaltiesDataGridView, penalties);

	}
	private: System::Void AddCarButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
		CarRepository^ carRepos = gcnew CarRepository(connectionString);

		List<Car^>^ cars = gcnew List<Car^>();

		for each (DataGridViewRow ^ row in CarsDataGridView->Rows) {

			if (!row->Selected) continue;

			Car^ car = gcnew Car();
			car->id = Convert::ToInt16(row->Cells[0]->Value);
			car->brand = row->Cells[1]->Value->ToString();
			car->length = Convert::ToInt16(row->Cells[2]->Value);
			car->clearance = Convert::ToInt16(row->Cells[3]->Value);
			car->engineCapacity = Convert::ToDouble(row->Cells[4]->Value);
			car->enginePower = Convert::ToInt16(row->Cells[5]->Value);
			car->wheelDiameter = Convert::ToInt16(row->Cells[6]->Value);
			car->reg_number = row->Cells[7]->Value->ToString();
			car->region = Convert::ToInt16(row->Cells[8]->Value);
			car->color = row->Cells[9]->Value->ToString();

			cars->Add(car);
			carRepos->Update(car);
		}
	}

private: System::Void UpdateCarBtn_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void DeleteCarBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	CarRepository^ carRepos = gcnew CarRepository(connectionString);	

	for each (DataGridViewRow ^ row in CarsDataGridView->Rows) {
		if (!row->Selected) continue;	
		carRepos->Delete(Convert::ToInt16(row->Cells[0]->Value));		
		CarsDataGridView->Rows->Remove(row);
	}
}

};
}
