#include "CarRepository.h"
#include "СarManager.h"

using namespace System;
using namespace System::Collections::Generic;

void AddCarAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	CarRepository^ carRepos = gcnew CarRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {

		if (!row->Selected) continue;
		if (row->Cells[2] == nullptr) {
			MessageBox::Show("Для добавления машины в базу данных, необходимо указать марку", "Ошибка");
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

void UpdateCarAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	CarRepository^ carRepos = gcnew CarRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {

		if (!row->Selected) continue;
		if (row->Cells[2] == nullptr) {
			MessageBox::Show("Для добавления машины в базу данных, необходимо указать марку", "Ошибка");
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

void DeleteCarAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	CarRepository^ carRepos = gcnew CarRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {
		if (!row->Selected) continue;
		bool isSuccess = carRepos->Delete(Convert::ToInt16(row->Cells[0]->Value));

		if (isSuccess)
			dataGrid->Rows->Remove(row);
	}
}

List<Car^>^ Find(String^ searchValue, int searchType)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	CarRepository^ carRepos = gcnew CarRepository(connectionString);

	switch (searchType)
	{
	case 0:
		return carRepos->FindByNumber(searchValue);
	case 1:
		return carRepos->FindByColor(searchValue);
	case 2:
		return carRepos->FindByEngineVolume(Convert::ToDouble( searchValue));
	case 3:
		return carRepos->FindByNumbersPenalties(Convert::ToInt16(searchValue));		
	default:
		// Если тип поиска не определен, возвращаем пустой список
		return gcnew List<Car^>();
	}
}

//
//List<Car^>^ FindByNumber(DataGridView^ dataGrid, String^ number)
//{
//	List<Car^>^ foundCars = gcnew List<Car^>();
//	for each (DataGridViewRow ^ row in dataGrid->Rows)
//	{
//		if (row->Cells["number"]->Value != nullptr && row->Cells["number"]->Value->ToString() == number)
//		{
//			Car^ car = gcnew Car();
//			car->id = Convert::ToInt32( row->Cells["id"]);
//			car->reg_number = number;			
//			car->color = row->Cells["color"]->Value->ToString();
//			car->engineVolume = Convert::ToInt32(row->Cells["EngineVolume"]->Value);
//
//
//			foundCars->Add(car);
//		}
//	}
//	return foundCars;
//}
//
//List<Car^>^ FindByColor(DataGridView^ dataGrid, String^ color)
//{
//	List<Car^>^ foundCars = gcnew List<Car^>();
//	for each (DataGridViewRow ^ row in dataGrid->Rows)
//	{
//		if (row->Cells["Color"]->Value != nullptr && row->Cells["Color"]->Value->ToString() == color)
//		{
//			Car^ car = gcnew Car();
//			car->Color = color;
//			// Заполните остальные поля машины на основе данных из DataGridView
//			// Например:
//			car->Number = row->Cells["Number"]->Value->ToString();
//			car->EngineVolume = Convert::ToInt32(row->Cells["EngineVolume"]->Value);
//			// Добавляем найденную машину в список
//			foundCars->Add(car);
//		}
//	}
//	return foundCars;
//}
//
//List<Car^>^ FindByEngineVolume(DataGridView^ dataGrid, int volume)
//{
//	List<Car^>^ foundCars = gcnew List<Car^>();
//	for each (DataGridViewRow ^ row in dataGrid->Rows)
//	{
//		if (row->Cells["EngineVolume"]->Value != nullptr && Convert::ToInt32(row->Cells["EngineVolume"]->Value) == volume)
//		{
//			Car^ car = gcnew Car();
//			car->EngineVolume = volume;
//			// Заполните остальные поля машины на основе данных из DataGridView
//			// Например:
//			car->Number = row->Cells["Number"]->Value->ToString();
//			car->Color = row->Cells["Color"]->Value->ToString();
//			// Добавляем найденную машину в список
//			foundCars->Add(car);
//		}
//	}
//	return foundCars;
//}
