#pragma once
#include "PenaltyType.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

void FillCarPenaltiesComboBox(DataGridViewComboBoxCell^ comboBoxCell, List<PenaltyType^>^ carPenaltyTypes);