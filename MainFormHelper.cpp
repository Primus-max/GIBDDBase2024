#include "CarRepository.h"
#include "MainFormelementConstructor.h"
#include "MainFormHelper.h"
#include "Penaltyrepository.h"
#include "PenaltyType.h"
#include "PenaltyTypeRepository.h"


void FillCarListView(DataGridView^ dataGridView, List<Car^>^ cars)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";

	PenaltyTypeRepository^ penaltyTypesRepos = gcnew PenaltyTypeRepository(connectionString);

	if (cars == nullptr)
	{
		CarRepository^ carRepos = gcnew CarRepository(connectionString);
		cars = carRepos->GetAll();
	}

	dataGridView->Rows->Clear();

	for each (Car ^ car in cars)
	{
		List<PenaltyType^>^ carPenaltyTypes = penaltyTypesRepos->GetAllTypesByCarId(car->id);
		array<Object^>^ rowData = gcnew array<Object^>(12);

		double sumPenalties = 0.0;

		for each (PenaltyType ^ penaltyType in carPenaltyTypes)
			sumPenalties += penaltyType->price;

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
		rowData[rowData->Length - 1] = sumPenalties;

		int rowIndex = dataGridView->Rows->Add(rowData);
		DataGridViewComboBoxCell^ comboBoxCell = dynamic_cast<DataGridViewComboBoxCell^>(dataGridView->Rows[rowIndex]->Cells["PenaltiesCombobox"]);
		FillCarPenaltiesComboBox(comboBoxCell, carPenaltyTypes);
	}
}

void FillPenaltiesListView(DataGridView^ PenaltiesDataGridView)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=gibdd_base.accdb";

	PenaltiesDataGridView->Rows->Clear();

	PenaltyRepository^ penaltyRepos = gcnew PenaltyRepository(connectionString);
	PenaltyTypeRepository^ penaltyTypesRepository = gcnew PenaltyTypeRepository(connectionString);
	CarRepository^ carRepos = gcnew CarRepository(connectionString);
	List<PenaltyType^>^ penaltyTypes = penaltyTypesRepository->GetAll();
	List<Penalty^>^ penalties = penaltyRepos->GetAll();
	Car^ car = gcnew Car();
	for each (Penalty ^ penalty in penalties)
	{
		car = carRepos->GetById(penalty->carId);
		String^ carBuilder = "�����: " + car->brand + " " + "�����: " + car ->reg_number;
		String^ formattedAmount = String::Format("{0:0.000}", penalty->amount);
		
		
			
		array<Object^>^ rowData = gcnew array<Object^>(5);

		rowData[0] = penalty->penaltyType;
		rowData[1] = penalty->datP;
		rowData[2] = formattedAmount;
		for each (PenaltyType ^ type in penaltyTypes) {
			if (penalty->penaltyType == type->id)
				rowData[3] = type->penaltyType;
			break;
		}		
		rowData[4] = carBuilder;
		//rowData[5] = car->id;

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
		String^ formattedAmount = String::Format("{0:0.000}", penaltyType->price);

		array<Object^>^ rowData = gcnew array<Object^>(3);
		rowData[0] = penaltyType->id;
		rowData[1] = penaltyType->penaltyType;
		rowData[2] = formattedAmount;

		dataGridView->Rows->Add(rowData);
	}
}

void FillSearchParameters(ComboBox^ comboBox)
{
	array<String^>^ searchParameters = gcnew array<String^> {
		"����� ������",
		"���� ������",
		"����� ���������",
		"� ���-��� ������� X"
	};

	comboBox->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBox->Items->Clear();
	comboBox->Items->AddRange(searchParameters);
	comboBox->SelectedIndex = 0;
}


