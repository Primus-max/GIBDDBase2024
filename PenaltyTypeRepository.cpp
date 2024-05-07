#include "PenaltyTypeRepository.h"

PenaltyTypeRepository::PenaltyTypeRepository(String^ connStr)
{
	_connectionString = connStr;
}

void PenaltyTypeRepository::Add(PenaltyType^ penaltyType)
{
	throw gcnew System::NotImplementedException();
}

List<PenaltyType^>^ PenaltyTypeRepository::GetAll()
{
	throw gcnew System::NotImplementedException();
	// TODO: вставьте здесь оператор return
}

void PenaltyTypeRepository::Update(PenaltyType^ penaltyType)
{
	throw gcnew System::NotImplementedException();
}

void PenaltyTypeRepository::Delete(int penaltyTypeId)
{
	throw gcnew System::NotImplementedException();
}
