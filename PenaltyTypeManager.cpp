#include "PenaltyTypeManager.h"
#include "PenaltyTypeRepository.h"

using namespace System;
using namespace System::Collections::Generic;

void AddPenaltyTypeAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	PenaltyTypeRepository^ penaltyTypeRepos = gcnew PenaltyTypeRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {

		if (!row->Selected) continue;
		if (row->Cells[1] == nullptr) {
			MessageBox::Show("Для добавления типа штрафа в базу данных, необходимо указать его тип", "Ошибка");
			return;
		}

		PenaltyType^ penaltyType = gcnew PenaltyType();
		penaltyType->id = Convert::ToInt16(row->Cells[0]->Value);
		penaltyType->penaltyType = row->Cells[1]->Value->ToString();
		penaltyType->price = Convert::ToDouble(row->Cells[2]->Value);
		
		penaltyTypeRepos->Add(penaltyType);
	}
}

void UpdatePenaltyTypeAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	PenaltyTypeRepository^ penaltyTypeRepos = gcnew PenaltyTypeRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {

		if (!row->Selected) continue;
		if (row->Cells[1] == nullptr) {
			MessageBox::Show("Для добавления типа штрафа в базу данных, необходимо указать его тип", "Ошибка");
			return;
		}

		PenaltyType^ penaltyType = gcnew PenaltyType();
		penaltyType->id = Convert::ToInt16(row->Cells[0]->Value);
		penaltyType->penaltyType = row->Cells[1]->Value->ToString();
		penaltyType->price = Convert::ToDouble(row->Cells[2]->Value);

		penaltyTypeRepos->Update(penaltyType);
	}
}

void DeletePenaltyTypeAtDb(DataGridView^ dataGrid)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	PenaltyTypeRepository^ penaltyTypeRepos = gcnew PenaltyTypeRepository(connectionString);

	for each (DataGridViewRow ^ row in dataGrid->Rows) {
		if (!row->Selected) continue;
		bool isSuccess = penaltyTypeRepos->Delete(Convert::ToInt16(row->Cells[0]->Value));

		if (isSuccess)
			dataGrid->Rows->Remove(row);
	}
}
