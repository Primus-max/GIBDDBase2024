#include "PenaltyTypeRepository.h"

using namespace System;
using namespace System::Collections::Generic;

PenaltyTypeRepository::PenaltyTypeRepository(String^ connStr)
{
    _connectionString = connStr;
}

void PenaltyTypeRepository::Add(PenaltyType^ penaltyType)
{
    // Реализация добавления
}

List<PenaltyType^>^ PenaltyTypeRepository::GetAll()
{
    List<PenaltyType^>^ penaltyTipes = gcnew List<PenaltyType^>();

    return penaltyTipes;
    // Реализация получения всех элементов
}

void PenaltyTypeRepository::Update(PenaltyType^ penaltyType)
{
    // Реализация обновления
}

void PenaltyTypeRepository::Delete(int penaltyTypeId)
{
    // Реализация удаления
}
