#pragma once

#include "penalty.h"

using namespace System;
using namespace System::Collections::Generic;


public ref class Car
{
public:

    int id;
    String^ brand;
    // Характеристики автомобиля
    short length = 0;
    short clearance = 0;
    short engineCapacity = 0;
    short enginePower = 0;
    short wheelDiameter = 0;

    // Регистрационные данные
    String^ number;
    short region = 0;

    // Цвет автомобиля
    String^ color;

    // Список штрафов
   List<Penalty^>^ penalties;
};


