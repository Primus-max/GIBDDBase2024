#include "MainFormelementConstructor.h"

void FillCarPenaltiesComboBox(DataGridViewComboBoxCell^ comboBoxCell, List<PenaltyType^>^ carPenaltyTypes)
{
    // Очищаем предыдущие элементы комбобокса
    comboBoxCell->Items->Clear();
       
    // Добавляем типы штрафов в комбобокс
    for each (PenaltyType ^ penType in carPenaltyTypes)    
        comboBoxCell->Items->Add(penType->penaltyType);
    
    // Отображаем первый элемент, если он есть
    if (comboBoxCell->Items->Count > 0)
        comboBoxCell->Value = comboBoxCell->Items[0];
}

