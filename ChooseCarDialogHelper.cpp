#include "ChooseCarDialogHelper.h"
#include "CarRepository.h"

void FillCarListViewAtChooseDialog(DataGridView^ dataGridView)
{

	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";	
	CarRepository^ carRepos = gcnew CarRepository(connectionString);
	List<Car^>^ cars = carRepos->GetAll();
	dataGridView->Rows->Clear();

	for each (Car ^ car in cars)
	{		
		array<Object^>^ rowData = gcnew array<Object^>(4);	

		rowData[0] = car->id;
		rowData[1] = car->brand;
		rowData[2] = car->reg_number;
		rowData[3] = car->color;	

		int rowIndex = dataGridView->Rows->Add(rowData);
		//DataGridViewComboBoxCell^ comboBoxCell = dynamic_cast<DataGridViewComboBoxCell^>(dataGridView->Rows[rowIndex]->Cells["PenaltiesCombobox"]);		
	}
}
