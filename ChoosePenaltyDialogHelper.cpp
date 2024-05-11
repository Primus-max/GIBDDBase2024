#include "ChoosePenaltyDialogHelper.h"
#include "PenaltyTypeRepository.h"
using namespace System;
using namespace System::Collections;

void FillPenaltyTypeListViewAtChooseDialog(DataGridView^ dataGridView)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	PenaltyTypeRepository^ penaltyTypeRepos = gcnew PenaltyTypeRepository(connectionString);
	List<PenaltyType^>^ penaltyTypes = penaltyTypeRepos->GetAll();
	dataGridView->Rows->Clear();

	for each (PenaltyType^ car in penaltyTypes)
	{
		array<Object^>^ rowData = gcnew array<Object^>(4);

		rowData[0] = car->id;
		rowData[1] = car->penaltyType;	

		int rowIndex = dataGridView->Rows->Add(rowData);		
	}
}
