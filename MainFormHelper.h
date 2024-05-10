#pragma once
#include "car.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

void FillCarListView(DataGridView^ dataGridView, List<Car^>^ cars = nullptr);
void FillPenaltiesListView(DataGridView^ dataGridView);
void FillPenaltyTypesListView(DataGridView^ dataGridView);
void FillSearchParameters(ComboBox^ comboBox);