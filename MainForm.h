#pragma once
#include "car.h"
#include "ChooseCarDialog.h"
#include "MainFormHelper.h"
#include "PenaltyManager.h"
#include "PenaltyTypeManager.h"
#include "СarManager.h"

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
		}

	public: property int SelectedRowIndex;

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
	private: System::Windows::Forms::DataGridView^ PenaltiesDataGridView;
	private: System::Windows::Forms::TabPage^ PenaltyTypes;
	private: System::Windows::Forms::DataGridView^ PenaltyTypesDataGridView;



	private: System::Windows::Forms::Button^ DeleteCarBtn;
	private: System::Windows::Forms::Button^ UpdateCarBtn;
	private: System::Windows::Forms::Label^ DescriptionControlsCars;
	private: System::Windows::Forms::Label^ DescriptionControlsPenalties;
	private: System::Windows::Forms::Button^ DeletePenaltyButton;
	private: System::Windows::Forms::Button^ UpdatePenaltyBatton;
	private: System::Windows::Forms::Button^ AddPenaltyBatton;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ SearchInput;
	private: System::Windows::Forms::ComboBox^ SearchParametersComboBox;
	private: System::Windows::Forms::Button^ SearchButton;












	private: System::Windows::Forms::Button^ ResetSearchButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ brand;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ length;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clearance;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ engineCapacity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ enginePower;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ wheelDiameter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ region;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ color;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ PenaltiesCombobox;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SumPenaltiesColumn;




	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penaltyTypeId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penaltyType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penalty_type_price;
	private: System::Windows::Forms::Button^ PenaltyTypeDeleteButton;
	private: System::Windows::Forms::Button^ PenaltyTypeUpdateButton;
	private: System::Windows::Forms::Button^ PenaltyTypeAddButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ penalty_type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ date_p;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ amount;
	private: System::Windows::Forms::DataGridViewButtonColumn^ carId;






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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->CarTabControl = (gcnew System::Windows::Forms::TabControl());
			this->CarTabPage = (gcnew System::Windows::Forms::TabPage());
			this->ResetSearchButton = (gcnew System::Windows::Forms::Button());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->SearchParametersComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SearchInput = (gcnew System::Windows::Forms::TextBox());
			this->DescriptionControlsCars = (gcnew System::Windows::Forms::Label());
			this->DeleteCarBtn = (gcnew System::Windows::Forms::Button());
			this->UpdateCarBtn = (gcnew System::Windows::Forms::Button());
			this->CarsDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->brand = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->length = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clearance = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->engineCapacity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->enginePower = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->wheelDiameter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->region = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->color = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PenaltiesCombobox = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->SumPenaltiesColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AddCarBatton = (gcnew System::Windows::Forms::Button());
			this->PenaltiesTabPage = (gcnew System::Windows::Forms::TabPage());
			this->DeletePenaltyButton = (gcnew System::Windows::Forms::Button());
			this->UpdatePenaltyBatton = (gcnew System::Windows::Forms::Button());
			this->AddPenaltyBatton = (gcnew System::Windows::Forms::Button());
			this->DescriptionControlsPenalties = (gcnew System::Windows::Forms::Label());
			this->PenaltiesDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->PenaltyTypes = (gcnew System::Windows::Forms::TabPage());
			this->PenaltyTypeDeleteButton = (gcnew System::Windows::Forms::Button());
			this->PenaltyTypeUpdateButton = (gcnew System::Windows::Forms::Button());
			this->PenaltyTypeAddButton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->PenaltyTypesDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->penaltyTypeId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->penaltyType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->penalty_type_price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->penalty_type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date_p = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->carId = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->PenaltiesDataGridView->CellContentClick += gcnew DataGridViewCellEventHandler(this, &MainForm::OpenDialogChooseCar_Click);
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
			this->CarTabControl->Size = System::Drawing::Size(1299, 698);
			this->CarTabControl->TabIndex = 0;
			// 
			// CarTabPage
			// 
			this->CarTabPage->Controls->Add(this->ResetSearchButton);
			this->CarTabPage->Controls->Add(this->SearchButton);
			this->CarTabPage->Controls->Add(this->SearchParametersComboBox);
			this->CarTabPage->Controls->Add(this->label2);
			this->CarTabPage->Controls->Add(this->label1);
			this->CarTabPage->Controls->Add(this->SearchInput);
			this->CarTabPage->Controls->Add(this->DescriptionControlsCars);
			this->CarTabPage->Controls->Add(this->DeleteCarBtn);
			this->CarTabPage->Controls->Add(this->UpdateCarBtn);
			this->CarTabPage->Controls->Add(this->CarsDataGridView);
			this->CarTabPage->Controls->Add(this->AddCarBatton);
			this->CarTabPage->Location = System::Drawing::Point(4, 22);
			this->CarTabPage->Name = L"CarTabPage";
			this->CarTabPage->Padding = System::Windows::Forms::Padding(3);
			this->CarTabPage->Size = System::Drawing::Size(1291, 672);
			this->CarTabPage->TabIndex = 0;
			this->CarTabPage->Text = L"Авто";
			this->CarTabPage->UseVisualStyleBackColor = true;
			// 
			// ResetSearchButton
			// 
			this->ResetSearchButton->Location = System::Drawing::Point(554, 42);
			this->ResetSearchButton->Name = L"ResetSearchButton";
			this->ResetSearchButton->Size = System::Drawing::Size(136, 22);
			this->ResetSearchButton->TabIndex = 12;
			this->ResetSearchButton->Text = L"Сбросить";
			this->ResetSearchButton->UseVisualStyleBackColor = true;
			this->ResetSearchButton->Click += gcnew System::EventHandler(this, &MainForm::ResetSearchButton_Click);
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(412, 43);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(136, 21);
			this->SearchButton->TabIndex = 11;
			this->SearchButton->Text = L"Искать";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MainForm::SearchButton_Click);
			// 
			// SearchParametersComboBox
			// 
			this->SearchParametersComboBox->FormattingEnabled = true;
			this->SearchParametersComboBox->Location = System::Drawing::Point(264, 42);
			this->SearchParametersComboBox->Name = L"SearchParametersComboBox";
			this->SearchParametersComboBox->Size = System::Drawing::Size(121, 21);
			this->SearchParametersComboBox->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(235, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 16);
			this->label2->TabIndex = 9;
			this->label2->Text = L"по";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(24, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 16);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Поиск";
			// 
			// SearchInput
			// 
			this->SearchInput->Location = System::Drawing::Point(77, 41);
			this->SearchInput->Name = L"SearchInput";
			this->SearchInput->Size = System::Drawing::Size(152, 20);
			this->SearchInput->TabIndex = 7;
			// 
			// DescriptionControlsCars
			// 
			this->DescriptionControlsCars->AutoSize = true;
			this->DescriptionControlsCars->Location = System::Drawing::Point(744, 16);
			this->DescriptionControlsCars->Name = L"DescriptionControlsCars";
			this->DescriptionControlsCars->Size = System::Drawing::Size(526, 39);
			this->DescriptionControlsCars->TabIndex = 6;
			this->DescriptionControlsCars->Text = resources->GetString(L"DescriptionControlsCars.Text");
			// 
			// DeleteCarBtn
			// 
			this->DeleteCarBtn->Location = System::Drawing::Point(1129, 79);
			this->DeleteCarBtn->Name = L"DeleteCarBtn";
			this->DeleteCarBtn->Size = System::Drawing::Size(135, 23);
			this->DeleteCarBtn->TabIndex = 5;
			this->DeleteCarBtn->Text = L"Удалить";
			this->DeleteCarBtn->UseVisualStyleBackColor = true;
			this->DeleteCarBtn->Click += gcnew System::EventHandler(this, &MainForm::DeleteCarBtn_Click);
			// 
			// UpdateCarBtn
			// 
			this->UpdateCarBtn->Location = System::Drawing::Point(942, 79);
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
			this->CarsDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(12) {
				this->id,
					this->brand, this->length, this->clearance, this->engineCapacity, this->enginePower, this->wheelDiameter, this->number, this->region,
					this->color, this->PenaltiesCombobox, this->SumPenaltiesColumn
			});
			this->CarsDataGridView->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->CarsDataGridView->Location = System::Drawing::Point(3, 140);
			this->CarsDataGridView->Name = L"CarsDataGridView";
			this->CarsDataGridView->Size = System::Drawing::Size(1285, 529);
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
			// engineCapacity
			// 
			this->engineCapacity->HeaderText = L"Объём (д./л.)";
			this->engineCapacity->Name = L"engineCapacity";
			// 
			// enginePower
			// 
			this->enginePower->HeaderText = L"Мощность (д./лс)";
			this->enginePower->Name = L"enginePower";
			this->enginePower->Width = 101;
			// 
			// wheelDiameter
			// 
			this->wheelDiameter->HeaderText = L"Радиус (к/мм)";
			this->wheelDiameter->Name = L"wheelDiameter";
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
			// PenaltiesCombobox
			// 
			this->PenaltiesCombobox->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->PenaltiesCombobox->HeaderText = L"Штрафы";
			this->PenaltiesCombobox->Name = L"PenaltiesCombobox";
			// 
			// SumPenaltiesColumn
			// 
			this->SumPenaltiesColumn->HeaderText = L"Сумма";
			this->SumPenaltiesColumn->Name = L"SumPenaltiesColumn";
			// 
			// AddCarBatton
			// 
			this->AddCarBatton->Location = System::Drawing::Point(747, 79);
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
			this->PenaltiesTabPage->Size = System::Drawing::Size(1291, 672);
			this->PenaltiesTabPage->TabIndex = 1;
			this->PenaltiesTabPage->Text = L"Штрафы";
			this->PenaltiesTabPage->UseVisualStyleBackColor = true;
			// 
			// DeletePenaltyButton
			// 
			this->DeletePenaltyButton->Location = System::Drawing::Point(399, 34);
			this->DeletePenaltyButton->Name = L"DeletePenaltyButton";
			this->DeletePenaltyButton->Size = System::Drawing::Size(135, 23);
			this->DeletePenaltyButton->TabIndex = 10;
			this->DeletePenaltyButton->Text = L"Удалить";
			this->DeletePenaltyButton->UseVisualStyleBackColor = true;
			this->DeletePenaltyButton->Click += gcnew System::EventHandler(this, &MainForm::DeletePenaltyButton_Click);
			// 
			// UpdatePenaltyBatton
			// 
			this->UpdatePenaltyBatton->Location = System::Drawing::Point(240, 34);
			this->UpdatePenaltyBatton->Name = L"UpdatePenaltyBatton";
			this->UpdatePenaltyBatton->Size = System::Drawing::Size(135, 23);
			this->UpdatePenaltyBatton->TabIndex = 9;
			this->UpdatePenaltyBatton->Text = L"Обновить";
			this->UpdatePenaltyBatton->UseVisualStyleBackColor = true;
			this->UpdatePenaltyBatton->Click += gcnew System::EventHandler(this, &MainForm::UpdatePenaltyBatton_Click);
			// 
			// AddPenaltyBatton
			// 
			this->AddPenaltyBatton->Location = System::Drawing::Point(79, 34);
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
			this->DescriptionControlsPenalties->Location = System::Drawing::Point(683, 18);
			this->DescriptionControlsPenalties->Name = L"DescriptionControlsPenalties";
			this->DescriptionControlsPenalties->Size = System::Drawing::Size(542, 39);
			this->DescriptionControlsPenalties->TabIndex = 7;
			this->DescriptionControlsPenalties->Text = resources->GetString(L"DescriptionControlsPenalties.Text");
			// 
			// PenaltiesDataGridView
			// 
			this->PenaltiesDataGridView->AllowUserToOrderColumns = true;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->PenaltiesDataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->PenaltiesDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->PenaltiesDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->penalty_type,
					this->date_p, this->amount, this->carId
			});
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->PenaltiesDataGridView->DefaultCellStyle = dataGridViewCellStyle3;
			this->PenaltiesDataGridView->Location = System::Drawing::Point(3, 78);
			this->PenaltiesDataGridView->Name = L"PenaltiesDataGridView";
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->PenaltiesDataGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->PenaltiesDataGridView->Size = System::Drawing::Size(1285, 591);
			this->PenaltiesDataGridView->TabIndex = 0;
			// 
			// PenaltyTypes
			// 
			this->PenaltyTypes->Controls->Add(this->PenaltyTypeDeleteButton);
			this->PenaltyTypes->Controls->Add(this->PenaltyTypeUpdateButton);
			this->PenaltyTypes->Controls->Add(this->PenaltyTypeAddButton);
			this->PenaltyTypes->Controls->Add(this->label3);
			this->PenaltyTypes->Controls->Add(this->PenaltyTypesDataGridView);
			this->PenaltyTypes->Location = System::Drawing::Point(4, 22);
			this->PenaltyTypes->Name = L"PenaltyTypes";
			this->PenaltyTypes->Padding = System::Windows::Forms::Padding(3);
			this->PenaltyTypes->Size = System::Drawing::Size(1291, 672);
			this->PenaltyTypes->TabIndex = 2;
			this->PenaltyTypes->Text = L"Виды нарушений";
			this->PenaltyTypes->UseVisualStyleBackColor = true;
			// 
			// PenaltyTypeDeleteButton
			// 
			this->PenaltyTypeDeleteButton->Location = System::Drawing::Point(421, 39);
			this->PenaltyTypeDeleteButton->Name = L"PenaltyTypeDeleteButton";
			this->PenaltyTypeDeleteButton->Size = System::Drawing::Size(135, 23);
			this->PenaltyTypeDeleteButton->TabIndex = 13;
			this->PenaltyTypeDeleteButton->Text = L"Удалить";
			this->PenaltyTypeDeleteButton->UseVisualStyleBackColor = true;
			this->PenaltyTypeDeleteButton->Click += gcnew System::EventHandler(this, &MainForm::PenaltyTypeDeleteButton_Click);
			// 
			// PenaltyTypeUpdateButton
			// 
			this->PenaltyTypeUpdateButton->Location = System::Drawing::Point(262, 39);
			this->PenaltyTypeUpdateButton->Name = L"PenaltyTypeUpdateButton";
			this->PenaltyTypeUpdateButton->Size = System::Drawing::Size(135, 23);
			this->PenaltyTypeUpdateButton->TabIndex = 12;
			this->PenaltyTypeUpdateButton->Text = L"Обновить";
			this->PenaltyTypeUpdateButton->UseVisualStyleBackColor = true;
			this->PenaltyTypeUpdateButton->Click += gcnew System::EventHandler(this, &MainForm::PenaltyTypeUpdateButton_Click);
			// 
			// PenaltyTypeAddButton
			// 
			this->PenaltyTypeAddButton->Location = System::Drawing::Point(101, 39);
			this->PenaltyTypeAddButton->Name = L"PenaltyTypeAddButton";
			this->PenaltyTypeAddButton->Size = System::Drawing::Size(135, 23);
			this->PenaltyTypeAddButton->TabIndex = 11;
			this->PenaltyTypeAddButton->Text = L"Добавить";
			this->PenaltyTypeAddButton->UseVisualStyleBackColor = true;
			this->PenaltyTypeAddButton->Click += gcnew System::EventHandler(this, &MainForm::PenaltyTypeAddButton_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(720, 23);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(542, 39);
			this->label3->TabIndex = 8;
			this->label3->Text = resources->GetString(L"label3.Text");
			// 
			// PenaltyTypesDataGridView
			// 
			this->PenaltyTypesDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->PenaltyTypesDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->penaltyTypeId,
					this->penaltyType, this->penalty_type_price
			});
			this->PenaltyTypesDataGridView->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->PenaltyTypesDataGridView->Location = System::Drawing::Point(3, 85);
			this->PenaltyTypesDataGridView->Name = L"PenaltyTypesDataGridView";
			this->PenaltyTypesDataGridView->Size = System::Drawing::Size(1285, 584);
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
			this->penaltyType->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->penaltyType->HeaderText = L"Вид нарушения";
			this->penaltyType->Name = L"penaltyType";
			// 
			// penalty_type_price
			// 
			this->penalty_type_price->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
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
			this->date_p->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle2->NullValue = nullptr;
			this->date_p->DefaultCellStyle = dataGridViewCellStyle2;
			this->date_p->HeaderText = L"Дата";
			this->date_p->Name = L"date_p";
			this->date_p->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// amount
			// 
			this->amount->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->amount->HeaderText = L"Сумма";
			this->amount->Name = L"amount";
			this->amount->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// carId
			// 
			this->carId->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->carId->HeaderText = L"Авто";
			this->carId->Name = L"carId";
			this->carId->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->carId->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// MainForm
			// 
			this->ClientSize = System::Drawing::Size(1299, 698);
			this->Controls->Add(this->CarTabControl);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1315, 744);
			this->Name = L"MainForm";
			this->Text = L"Программа для работы с базой ГИБДД";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Loaded);
			this->CarTabControl->ResumeLayout(false);
			this->CarTabPage->ResumeLayout(false);
			this->CarTabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CarsDataGridView))->EndInit();
			this->PenaltiesTabPage->ResumeLayout(false);
			this->PenaltiesTabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PenaltiesDataGridView))->EndInit();
			this->PenaltyTypes->ResumeLayout(false);
			this->PenaltyTypes->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PenaltyTypesDataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion	

	private: System::Void MainForm_Loaded(System::Object^ sender, System::EventArgs^ e) {

		FillCarListView(CarsDataGridView);
		FillPenaltiesListView(PenaltiesDataGridView);
		FillPenaltyTypesListView(PenaltyTypesDataGridView);
		FillSearchParameters(SearchParametersComboBox);
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

#pragma region CRUD Типы штрафов
	private: System::Void PenaltyTypeDeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		DeletePenaltyTypeAtDb(PenaltyTypesDataGridView);
	}
	private: System::Void PenaltyTypeUpdateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		UpdatePenaltyTypeAtDb(PenaltyTypesDataGridView);
	}
	private: System::Void PenaltyTypeAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddPenaltyTypeAtDb(PenaltyTypesDataGridView);
	}
#pragma endregion

#pragma region Поиск
	private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int selectedIndex = SearchParametersComboBox->SelectedIndex;
		List<Car^>^ searchedCars = Find(SearchInput->Text, selectedIndex);
		//CarsDataGridView->DataSource = 
		FillCarListView(CarsDataGridView, searchedCars);
	}
	private: System::Void ResetSearchButton_Click(System::Object^ sender, System::EventArgs^ e) {
		FillCarListView(CarsDataGridView);
	}
#pragma endregion


	private: Void OpenDialogChooseCar_Click(Object^ sender, DataGridViewCellEventArgs^ e) {
		ChooseCarDialog^ dialog = gcnew ChooseCarDialog();
		dialog->Show();
		dialog->CarSelected += gcnew ChooseCarDialog::CarSelectedEventHandler(this, &MainForm::OnCarSelected);
		SelectedRowIndex = e->RowIndex;
	}

	private: Void OnCarSelected(int carId) {
		if (SelectedRowIndex == -1) return;

		DataGridViewRow^ selectedRow = PenaltiesDataGridView->Rows[SelectedRowIndex];
		selectedRow->Cells[4]->Value = carId;
		selectedRow->Selected = true;
		UpdatePenaltyAtDb(PenaltiesDataGridView);
	}

	};
}
