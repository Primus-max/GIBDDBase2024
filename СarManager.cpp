#include "СarManager.h"
#include "CarRepository.h"

using namespace System;
using namespace System::Collections::Generic;

void addCarAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	CarRepository^ carRepos = gcnew CarRepository(connectionString);	

	for each (DataGridViewRow ^ row in dataGrid->Rows) {

		if (!row->Selected) continue;
		if (row->Cells[2] == nullptr) {
			MessageBox::Show("Для добавлении машины в базу данных, необходимо указать марку", "Ошибка");
			return;
		}
			
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
		
		carRepos->Add(car);
	}
}

void updateCarAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	CarRepository^ carRepos = gcnew CarRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {

		if (!row->Selected) continue;
		if (row->Cells[2] == nullptr) {
			MessageBox::Show("Для добавлении машины в базу данных, необходимо указать марку", "Ошибка");
			return;
		}

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
		
		carRepos->Update(car);
	}
}

void deleteCarAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	CarRepository^ carRepos = gcnew CarRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {
		if (!row->Selected) continue;
		carRepos->Delete(Convert::ToInt16(row->Cells[0]->Value));
		dataGrid->Rows->Remove(row);
	}
}
