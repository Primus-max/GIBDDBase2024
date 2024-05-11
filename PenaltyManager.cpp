#include "penalty.h"
#include "PenaltyManager.h"
#include "Penaltyrepository.h"
#include "PenaltyTypeRepository.h"
#include "CarRepository.h"

using namespace System;
using namespace System::Collections::Generic;

void AddPenaltyAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	PenaltyRepository^ penaltyRepos = gcnew PenaltyRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {

		if (!row->Selected) continue;
		if (row->Cells[2] == nullptr) {
			MessageBox::Show("Для добавления штрафа в базу данных, необходимо указать марку", "Ошибка");
			return;
		}

		Penalty^ penalty = gcnew Penalty();
		penalty->id = Convert::ToInt16(row->Cells[0]->Value);
		penalty->datP = Convert::ToDateTime(row->Cells[1]->Value);
		penalty->amount = Convert::ToDouble(row->Cells[2]->Value);
		penalty->penaltyType = Convert::ToInt16(row->Cells[3]->Value);
		penalty->carId = Convert::ToInt16(row->Cells[4]->Value);

		penaltyRepos->Add(penalty);
	}
}

void UpdatePenaltyAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	PenaltyRepository^ penaltyRepos = gcnew PenaltyRepository(connectionString);
	PenaltyTypeRepository^ penaltyTypeRepos = gcnew PenaltyTypeRepository(connectionString);
	CarRepository^ carRepos = gcnew CarRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {

		if (!row->Selected) continue;
		if (row->Cells[2] == nullptr) {
			MessageBox::Show("Для добавления машины в базу данных, необходимо указать марку", "Ошибка");
			return;
		}
		int penaltyTypeId = Convert::ToInt16(row->Cells[1]->Value);

		PenaltyType^ penaltyType = penaltyTypeRepos->GetById(penaltyTypeId);
		Penalty^ penalty = gcnew Penalty();
		
		penalty->id = Convert::ToInt16(row->Cells[0]->Value);
		penalty->datP = Convert::ToDateTime(row->Cells[2]->Value);
		penalty->penaltyType = penaltyType->id;
		penalty->amount = penaltyType->price;
		penalty->carId = Convert::ToInt16(row->Cells[5]->Value);

		// Обновляем данные в базе данных
		penaltyRepos->Update(penalty);

		Car^ car = carRepos->GetById(penalty->carId);
		String^ carBuilder = "Марка: " + car->brand + " " + "номер: " + car->reg_number;
		String^ formattedAmount = String::Format("{0:0.000}", penaltyType->price);

		row->Cells[0]->Value = penalty->id;
		row->Cells[1]->Value = penalty->penaltyType;
		row->Cells[2]->Value = penalty->datP;		
		row->Cells[3]->Value = penaltyType->penaltyType;
		row->Cells[4]->Value = formattedAmount;
		row->Cells[5]->Value = penalty->carId;
		row->Cells[6]->Value = carBuilder;
	}
}


void DeletePenaltyAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	PenaltyRepository^ penaltyRepos = gcnew PenaltyRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {
		if (!row->Selected) continue;
		bool isSuccess = penaltyRepos->Delete(Convert::ToInt16(row->Cells[0]->Value));

		if (isSuccess)
			dataGrid->Rows->Remove(row);
	}
}
