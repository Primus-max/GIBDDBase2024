#include "PenaltyTypeRepository.h"

using namespace System;
using namespace System::Collections::Generic;

PenaltyTypeRepository::PenaltyTypeRepository(String^ connStr)
{
    _connectionString = connStr;
}

void PenaltyTypeRepository::Add(PenaltyType^ penaltyType)
{
    // ���������� ����������
}

List<PenaltyType^>^ PenaltyTypeRepository::GetAll()
{
    List<PenaltyType^>^ penaltyTipes = gcnew List<PenaltyType^>();

    return penaltyTipes;
    // ���������� ��������� ���� ���������
}

void PenaltyTypeRepository::Update(PenaltyType^ penaltyType)
{
    // ���������� ����������
}

void PenaltyTypeRepository::Delete(int penaltyTypeId)
{
    // ���������� ��������
}
