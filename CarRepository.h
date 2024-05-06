#pragma once 
#include "car.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class CarRepository
{
private: String^ _connectionString;

public: CarRepository(String^ connStr);

	  void Add(Car^ car);
	  List<Car^>^ GetAll();
	  void Update(Car^ car);
	  void Delete(int carId);
};

