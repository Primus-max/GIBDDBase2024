#include "MainFormHelper.h"
#include "CarRepository.h"
#include "Penaltyrepository.h"
#include "PenaltyType.h"
#include "PenaltyTypeRepository.h"
#include "MainFormelementConstructor.h"

void FillCarListView(DataGridView^ dataGridView)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";

	PenaltyTypeRepository^ penaltyTypesRepos = gcnew PenaltyTypeRepository(connectionString);

	CarRepository^ carRepos = gcnew CarRepository(connectionString);
	List<Car^>^ cars = carRepos->GetAll();

	dataGridView->Rows->Clear();

	for each (Car ^ car in cars)
	{
		array<Object^>^ rowData = gcnew array<Object^>(10);

		rowData[0] = car->id;
		rowData[1] = car->brand;
		rowData[2] = car->length;
		rowData[3] = car->clearance;
		rowData[4] = car->engineCapacity;
		rowData[5] = car->enginePower;
		rowData[6] = car->wheelDiameter;
		rowData[7] = car->reg_number;
		rowData[8] = car->region;
		rowData[9] = car->color;

		int rowIndex = dataGridView->Rows->Add(rowData); 
		DataGridViewComboBoxCell^ comboBoxCell = dynamic_cast<DataGridViewComboBoxCell^>(dataGridView->Rows[rowIndex]->Cells["PenaltiesCombobox"]);

		List<PenaltyType^>^ carPenaltyTypes = penaltyTypesRepos->GetAllTypesByCarId(car->id);
		FillCarPenaltiesComboBox(comboBoxCell, carPenaltyTypes);
	}
}

void FillPenaltiesListView(DataGridView^ PenaltiesDataGridView)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	// ������� ������������ ������ � DataGridView
	PenaltiesDataGridView->Rows->Clear();

	PenaltyRepository^ penaltyRepos = gcnew PenaltyRepository(connectionString);
	List<Penalty^>^ penalties = penaltyRepos->GetAll();	
	// ��������� ��������� �������
	for each (Penalty ^ penalty in penalties)
	{
		array<Object^>^ rowData = gcnew array<Object^>(5); // ��������� ����� �������
		rowData[0] = penalty->penaltyType;
		rowData[1] = penalty->datP;
		rowData[2] = penalty->amount;
		rowData[3] = penalty->carId;		

		PenaltiesDataGridView->Rows->Add(rowData);
	}
}

void FillPenaltyTypesListView(DataGridView^ dataGridView)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	PenaltyTypeRepository^ penaltyTypeRepos = gcnew PenaltyTypeRepository(connectionString);
	List<PenaltyType^>^ penaltyTypes = penaltyTypeRepos->GetAll();
	List<PenaltyType^>^ asdf = penaltyTypeRepos->GetAllTypesByCarId(3);
	dataGridView->Rows->Clear();

	for each (PenaltyType ^ penaltyType in penaltyTypes)
	{
		array<Object^>^ rowData = gcnew array<Object^>(3);
		rowData[0] = penaltyType->id;
		rowData[1] = penaltyType->penaltyType;
		rowData[2] = penaltyType->price;

		dataGridView->Rows->Add(rowData);
	}
}


