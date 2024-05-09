#pragma once
#include "ICarSearchable.h"
#include "CarRepository.h"
#include "car.h"

using namespace System;
using namespace System::Windows::Forms;

void AddCarAtDb(DataGridView^ dataGrid);
void UpdateCarAtDb(DataGridView^ dataGrid);
void DeleteCarAtDb(DataGridView^ dataGrid);
List<Car^>^ Find(String^ searchValue, int searchType);

//List<Car^>^ FindByNumber(DataGridView^ dataGrid, String^ number);
//List<Car^>^ FindByColor(DataGridView^ dataGrid, String^ color);
//List<Car^>^ FindByEngineVolume(DataGridView^ dataGrid, double volume);