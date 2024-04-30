#pragma once
#include "car.h"
#include <SQLiteCpp/SQLiteCpp.h>

using namespace System;
using namespace System::Collections::Generic;


void addCar(Car car);
void deleteCar(int carId);
Car findCarByNumber(String^ number);
void findCarByColor(String^ color);
void sortCarsByEngineCapacity(List<Car^>^& cars);
void sortCarsByEnginePower(List<Car^>^& cars);
void sortCarsByNumber(List<Car^>^& cars);