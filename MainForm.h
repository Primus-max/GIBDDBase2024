#pragma once
#include "car.h"
#include "CarRepository.h"
#include "data.h"


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

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ brand;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ length;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clearance;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ engine_capacity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ engine_power;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ wheel_deameter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ region;
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
			this->CarTabControl = (gcnew System::Windows::Forms::TabControl());
			this->CarTabPage = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->brand = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->length = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clearance = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->engine_capacity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->engine_power = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->wheel_deameter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->region = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->color = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->PenaltiesTabPage = (gcnew System::Windows::Forms::TabPage());
			this->CarTabControl->SuspendLayout();
			this->CarTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// CarTabControl
			// 
			this->CarTabControl->Controls->Add(this->CarTabPage);
			this->CarTabControl->Controls->Add(this->PenaltiesTabPage);
			this->CarTabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CarTabControl->Location = System::Drawing::Point(0, 0);
			this->CarTabControl->Name = L"CarTabControl";
			this->CarTabControl->SelectedIndex = 0;
			this->CarTabControl->Size = System::Drawing::Size(1060, 685);
			this->CarTabControl->TabIndex = 0;
			// 
			// CarTabPage
			// 
			this->CarTabPage->Controls->Add(this->dataGridView1);
			this->CarTabPage->Controls->Add(this->button1);
			this->CarTabPage->Location = System::Drawing::Point(4, 22);
			this->CarTabPage->Name = L"CarTabPage";
			this->CarTabPage->Padding = System::Windows::Forms::Padding(3);
			this->CarTabPage->Size = System::Drawing::Size(1052, 659);
			this->CarTabPage->TabIndex = 0;
			this->CarTabPage->Text = L"Авто";
			this->CarTabPage->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->id, this->brand,
					this->length, this->clearance, this->engine_capacity, this->engine_power, this->wheel_deameter, this->number, this->region, this->color
			});
			this->dataGridView1->Location = System::Drawing::Point(3, 85);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1047, 572);
			this->dataGridView1->TabIndex = 3;
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
			this->length->HeaderText = L"Длина";
			this->length->Name = L"length";
			// 
			// clearance
			// 
			this->clearance->HeaderText = L"Просвет";
			this->clearance->Name = L"clearance";
			// 
			// engine_capacity
			// 
			this->engine_capacity->HeaderText = L"Объём (д.)";
			this->engine_capacity->Name = L"engine_capacity";
			// 
			// engine_power
			// 
			this->engine_power->HeaderText = L"Мощность (д./лс)";
			this->engine_power->Name = L"engine_power";
			// 
			// wheel_deameter
			// 
			this->wheel_deameter->HeaderText = L"Радиус (к.)";
			this->wheel_deameter->Name = L"wheel_diameter";
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(213, 56);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// PenaltiesTabPage
			// 
			this->PenaltiesTabPage->Location = System::Drawing::Point(4, 22);
			this->PenaltiesTabPage->Name = L"PenaltiesTabPage";
			this->PenaltiesTabPage->Padding = System::Windows::Forms::Padding(3);
			this->PenaltiesTabPage->Size = System::Drawing::Size(1056, 659);
			this->PenaltiesTabPage->TabIndex = 1;
			this->PenaltiesTabPage->Text = L"Штрафы";
			this->PenaltiesTabPage->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->ClientSize = System::Drawing::Size(1060, 685);
			this->Controls->Add(this->CarTabControl);
			this->Name = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Loaded);
			this->CarTabControl->ResumeLayout(false);
			this->CarTabPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
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
			rowData[7] = car->number;
			rowData[8] = car->region;
			rowData[9] = car->color;

			dataGridView->Rows->Add(rowData);
		}
	}



	private: System::Void MainForm_Loaded(System::Object^ sender, System::EventArgs^ e) {

		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";

		CarRepository^ carRepos = gcnew CarRepository(connectionString);
		List<Car^>^ cars = carRepos->GetAllCars();
		FillCarListView(dataGridView1, cars);

	}
	};
}
