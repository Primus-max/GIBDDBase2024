#pragma once
#include "PenaltyType.h";

using namespace System::Collections::Generic;

public ref class PenaltyTypeRepository
{
private: String^ _connectionString;
public:	PenaltyTypeRepository(String^ connStr);

	  void Add(PenaltyType^ penaltyType);
	  List<PenaltyType^>^ GetAll();
	  void Update(PenaltyType^ penaltyType);
	  void Delete(int penaltyTypeId);
};
