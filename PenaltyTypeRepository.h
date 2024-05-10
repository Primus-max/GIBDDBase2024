#pragma once
#include "PenaltyType.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class PenaltyTypeRepository
{
private: String^ _connectionString;
public:	PenaltyTypeRepository(String^ connStr);

	  void Add(PenaltyType^ penaltyType);
	  List<PenaltyType^>^ GetAll();
	  List<PenaltyType^>^ GetAllTypesByCarId(int carId);
	  void Update(PenaltyType^ penaltyType);
	  bool Delete(int penaltyTypeId);
};
