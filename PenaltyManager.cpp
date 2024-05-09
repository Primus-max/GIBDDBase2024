#include "PenaltyManager.h"
#include "Penaltyrepository.h"
#include "penalty.h"

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
		penalty->datP = Convert::ToDateTime( row->Cells[1]->Value);
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

	for each (DataGridViewRow ^ row in dataGrid->Rows) {

		if (!row->Selected) continue;
		if (row->Cells[2] == nullptr) {
			MessageBox::Show("Для добавлении машины в базу данных, необходимо указать марку", "Ошибка");
			return;
		}

		Penalty^ penalty = gcnew Penalty();
		penalty->id = Convert::ToInt16(row->Cells[0]->Value);
		penalty->datP = Convert::ToDateTime(row->Cells[1]->Value);
		penalty->amount = Convert::ToDouble(row->Cells[2]->Value);
		penalty->penaltyType = Convert::ToInt16(row->Cells[3]->Value);
		penalty->carId = Convert::ToInt16(row->Cells[4]->Value);

		penaltyRepos->Update(penalty);
	}
}

void DeletePenaltyAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	PenaltyRepository^ penaltyRepos = gcnew PenaltyRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {
		if (!row->Selected) continue;
		penaltyRepos->Delete(Convert::ToInt16(row->Cells[0]->Value));
		dataGrid->Rows->Remove(row);
	}
}
