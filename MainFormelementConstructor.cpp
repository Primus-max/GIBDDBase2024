#include "MainFormelementConstructor.h"

void FillCarPenaltiesComboBox(DataGridViewComboBoxCell^ comboBoxCell, List<PenaltyType^>^ carPenaltyTypes)
{
    // ������� ���������� �������� ����������
    comboBoxCell->Items->Clear();
       
    // ��������� ���� ������� � ���������
    for each (PenaltyType ^ penType in carPenaltyTypes)    
        comboBoxCell->Items->Add(penType->penaltyType);
    
    // ���������� ������ �������, ���� �� ����
    if (comboBoxCell->Items->Count > 0)
        comboBoxCell->Value = comboBoxCell->Items[0];
}

