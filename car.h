#pragma once
#include <ctime>
#include "penalty.h"
#include <vector>

struct Car
{
    int id = 0;

    // Характеристики автомобиля
    short length = 0;
    short clearance = 0;
    short engineCapacity = 0;
    short enginePower = 0;
    short wheelDiameter = 0;

    // Регистрационные данные
    char number[7] = {};
    short region = 0;

    // Цвет автомобиля
    char carColor[10] = {};

    // Список штрафов
    vector<Penalty> penalties;
};

