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
	  bool Delete(int carId);

	  List<Car^>^ FindByNumber(String^ number);
	  List<Car^>^ FindByColor(String^ color);
	  List<Car^>^ FindByEngineVolume(double volume);
	  List<Car^>^ FindByNumbersPenalties(int quantity);
};

