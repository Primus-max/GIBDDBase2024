#pragma once
#include "car.h"
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
	private: System::Windows::Forms::ListView^ CarsListView;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->PenaltiesTabPage = (gcnew System::Windows::Forms::TabPage());
			this->CarsListView = (gcnew System::Windows::Forms::ListView());
			this->CarTabControl->SuspendLayout();
			this->CarTabPage->SuspendLayout();
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
			this->CarTabControl->Size = System::Drawing::Size(961, 630);
			this->CarTabControl->TabIndex = 0;
			// 
			// CarTabPage
			// 
			this->CarTabPage->Controls->Add(this->CarsListView);
			this->CarTabPage->Controls->Add(this->button1);
			this->CarTabPage->Location = System::Drawing::Point(4, 22);
			this->CarTabPage->Name = L"CarTabPage";
			this->CarTabPage->Padding = System::Windows::Forms::Padding(3);
			this->CarTabPage->Size = System::Drawing::Size(953, 604);
			this->CarTabPage->TabIndex = 0;
			this->CarTabPage->Text = L"Авто";
			this->CarTabPage->UseVisualStyleBackColor = true;
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
			this->PenaltiesTabPage->Size = System::Drawing::Size(953, 604);
			this->PenaltiesTabPage->TabIndex = 1;
			this->PenaltiesTabPage->Text = L"Штрафы";
			this->PenaltiesTabPage->UseVisualStyleBackColor = true;
			// 
			// CarsListView
			// 
			this->CarsListView->HideSelection = false;
			this->CarsListView->Location = System::Drawing::Point(0, 120);
			this->CarsListView->Name = L"CarsListView";
			this->CarsListView->Size = System::Drawing::Size(953, 484);
			this->CarsListView->TabIndex = 2;
			this->CarsListView->UseCompatibleStateImageBehavior = false;
			// 
			// MainForm
			// 
			this->ClientSize = System::Drawing::Size(961, 630);
			this->Controls->Add(this->CarTabControl);
			this->Name = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Loaded);
			this->CarTabControl->ResumeLayout(false);
			this->CarTabPage->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion	

		private: System::Void FillCarListView(ListView^ listView, List<Car^>^ cars)
		{
			listView->Items->Clear(); 
			listView->Columns->Clear(); 

			// Добавляю столбцы с заголовками
			listView->Columns->Add("ID");
			listView->Columns->Add("Brand");
			listView->Columns->Add("Length");
			listView->Columns->Add("Clearance");
			listView->Columns->Add("Engine Capacity");
			listView->Columns->Add("Engine Power");
			listView->Columns->Add("Wheel Diameter");
			listView->Columns->Add("Number");
			listView->Columns->Add("Region");
			listView->Columns->Add("Car Color");

			// Добавляю каждый автомобиль в ListView
			for each (Car ^ car in cars)
			{
				ListViewItem^ item = gcnew ListViewItem(Convert::ToString(car->id));
				item->SubItems->Add(car->brand);
				item->SubItems->Add(Convert::ToString(car->length));
				item->SubItems->Add(Convert::ToString(car->clearance));
				item->SubItems->Add(Convert::ToString(car->engineCapacity));
				item->SubItems->Add(Convert::ToString(car->enginePower));
				item->SubItems->Add(Convert::ToString(car->wheelDiameter));
				item->SubItems->Add(car->number);
				item->SubItems->Add(Convert::ToString(car->region));
				item->SubItems->Add(car->color);
				listView->Items->Add(item);
			}
		}


	private: System::Void MainForm_Loaded(System::Object^ sender, System::EventArgs^ e) {
		
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		try
		{
			dbConnection->Open();

			//// Создаем таблицу
			//String^ createTableQuery = "CREATE TABLE cars (id Number, brand Text)";
			//OleDbCommand^ createTableCommand = gcnew OleDbCommand(createTableQuery, dbConnection);
			//createTableCommand->ExecuteNonQuery();
			//Console::WriteLine("Таблица 'cars' успешно создана.");

			


			String^ queryFrom = "SELECT * FROM penalty";
			OleDbCommand^ dbCommandFrom = gcnew OleDbCommand(queryFrom, dbConnection);
			OleDbDataReader^ reader = dbCommandFrom->ExecuteReader();

			// Чтение данных из результата запроса
			while (reader->Read())
			{
				// Пример чтения данных из колонок (предполагается, что в таблице есть поля "ID", "Make", "Model", "Year")
				//auto id = reader->GetInt32(0); // индексация начинается с 0
				auto id = reader["id"];
				auto make = reader["date_p"];
				Console::WriteLine(id);
				Console::WriteLine(make);
			/*	auto model = reader["brand"];
				int len = reader->GetInt32(2);
				auto lreen = reader->GetString(1);
				int year = reader->GetInt32(3);*/

				
			}

			String^ queryFromew = "SELECT * FROM penalty";
			OleDbCommand^ dbCommandFrossm = gcnew OleDbCommand(queryFromew, dbConnection);
			OleDbDataReader^ readerss = dbCommandFrossm->ExecuteReader();

			// Чтение данных из результата запроса
			while (readerss->Read())
			{
				// Пример чтения данных из колонок (предполагается, что в таблице есть поля "ID", "Make", "Model", "Year")
				//auto id = reader->GetInt32(0); // индексация начинается с 0
				auto asdf = reader->GetValue(0);
				auto mafdsdfke = reader["id"];
				auto moaadel = reader["brand"];
				int ldfden = reader->GetInt32(2);
				auto lrsdfeen = reader->GetString(1);
				int yedsdfar = reader->GetInt32(3);

				
			}
			// Добавляем тестовые данные
			String^ insertQuery = "INSERT INTO cars (brand, length, clearance, engineCapacity, enginePower, wheelDiameter, number, region, color) VALUES "
				"('Toyota', 4500, 200, 2000, 150, 16, 'ABC123', 77, 'Red'), "
				"('BMW', 4800, 190, 2500, 180, 17, 'XYZ789', 78, 'Blue')";
			OleDbCommand^ insertCommand = gcnew OleDbCommand(insertQuery, dbConnection);
			insertCommand->ExecuteNonQuery();
			Console::WriteLine("Тестовые данные успешно добавлены.");
		}
		catch (Exception^ ex)
		{
			Console::WriteLine("Произошла ошибка: " + ex->Message);
		}
		
		
		String^ queryFrom = "SELECT * FROM cars";
		OleDbCommand^ dbCommandFrom = gcnew OleDbCommand(queryFrom, dbConnection);
		OleDbDataReader^ reader = dbCommandFrom->ExecuteReader();

		// Чтение данных из результата запроса
		while (reader->Read())
		{
			// Пример чтения данных из колонок (предполагается, что в таблице есть поля "ID", "Make", "Model", "Year")
			int id = reader->GetInt32(0); // индексация начинается с 0
			String^ make = reader->GetString(1);
			String^ model = reader->GetString(2);
			int year = reader->GetInt32(3);

			// Делайте что-то с прочитанными данными, например, выводите их
			Console::WriteLine("ID: {0}, Make: {1}, Model: {2}, Year: {3}", id, make, model, year);
		}


		List<Car^>^ cars = gcnew List<Car^>();
		for (int i = 1; i <= 3; ++i)
		{
			Car^ car = gcnew Car();
			car->id = i;
			car->brand = "Brand" + i;
			car->number = "Number" + i;
			cars->Add(car);
		}

		
		this->CarsListView->View = View::Details;
		this->CarsListView->FullRowSelect = true;

		// Заполняю ListView данными о автомобилях
		FillCarListView(this->CarsListView, cars);

		Car^ car = gcnew Car();

		car->brand = "Бмв";
		addCarToBase(car);		
	}

	};
}
