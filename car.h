#pragma once

#include "penalty.h"

using namespace System;
using namespace System::Collections::Generic;


public ref class Car
{
public:

	int id;
	String^ brand;

	short length = 0;
	short clearance = 0;
	double engineCapacity = 0;
	short enginePower = 0;
	short wheelDiameter = 0;

	String^ number;
	short region = 0;

	String^ color;

	List<Penalty^>^ penalties;
};


