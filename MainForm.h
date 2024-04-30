#pragma once
#include "car.h"

using namespace System;

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

	private: TextBox^ textBox1;
	private: Label^ label1;
	private: Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	protected:


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(60, 165);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(147, 84);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(81, 24);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(147, 20);
			this->textBox2->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Марка";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 55);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Номер";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(81, 55);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(147, 20);
			this->textBox3->TabIndex = 4;
			// 
			// MainForm
			// 
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Name = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	

	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		Car car;
		Penalty^ penalty;
		// Присваивание значения полю brand
		car.brand = this->textBox2->Text;
		car.penalties->Add(penalty);
		car.number = this->textBox3->Text;

		// Получение текста из textBox1 и преобразование его в стандартную строку (std::string)
		
		// Копирование значения в переменную car.brand
		//array<wchar_t>^ wideCharArray = this->textBox2->Text->ToCharArray();
		
	}

	};
}
