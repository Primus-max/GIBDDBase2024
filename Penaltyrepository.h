#pragma once
#include "penalty.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class  PenaltyRepository
{
private: String^ _connectionString;

public: PenaltyRepository(String^ connStr);

	  void Add(Penalty^ penalty);
	  List<Penalty^>^ GetAll();
	  Penalty^ GetById(int id);
	  List<Penalty^>^ GetAllForCar(int cardId);
	  double GetAmountPenaltiesByCarId(int cardId);
	  void Update(Penalty^ penalty);
	  bool Delete(int id);
};

