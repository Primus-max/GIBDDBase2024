#include "MainFormelementConstructor.h"

void AddCarPenaltiesColumn(DataGridView^ dataGridView, List<PenaltyType^>^ penaltyTypes)
{
	DataGridViewComboBoxColumn^ comboBox = gcnew DataGridViewComboBoxColumn();

	comboBox->HeaderText = "Штрафы";
	comboBox->Width = 200;

	for each (PenaltyType^ penType in penaltyTypes)	{
		comboBox->Items->Add(penType->penaltyType);
	}
	
	// Отображение первого элемента	
	if (comboBox->Items->Count > 0)	
		comboBox->DefaultCellStyle->NullValue = comboBox->Items[0];
	
	dataGridView->Columns->Add(comboBox);	
}
