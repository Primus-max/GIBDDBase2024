#pragma once
#include "PenaltyType.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

void AddCarPenaltiesColumn(DataGridView^ dataGridView, List<PenaltyType^>^ penaltyTypes);