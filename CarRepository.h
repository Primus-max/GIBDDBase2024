#pragma once 
#include "car.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::OleDb;

public ref class CarRepository
{
private: String^ _connectionString;

public: CarRepository(String^ connStr);

	  void AddCar(Car^ car);
	  List<Car^>^ GetAllCars();
	  void UpdateCar(Car^ car);
	  void DeleteCar(int carId);
};

