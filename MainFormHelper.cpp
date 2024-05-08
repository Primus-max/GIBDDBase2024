#include "MainFormHelper.h"
#include "CarRepository.h"
#include "Penaltyrepository.h"
#include "PenaltyType.h"
#include "PenaltyTypeRepository.h"

void FillCarListView(DataGridView^ dataGridView)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
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

		dataGridView->Rows->Add(rowData);
	}
}

void FillPenaltiesListView(DataGridView^ PenaltiesDataGridView)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";
	PenaltyRepository^ penaltyRepos = gcnew PenaltyRepository(connectionString);
	List<Penalty^>^ penalties = penaltyRepos->GetAll();

	PenaltiesDataGridView->Rows->Clear();

	for each (Penalty ^ penalty in penalties)
	{
		array<Object^>^ rowData = gcnew array<Object^>(4);
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
