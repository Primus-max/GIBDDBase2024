#pragma once
#include <ctime>
#include "enums.h"
using namespace System;

public ref class Penalty
{
public:
    int id = 0;
    int carId = 0;
    DateTime^ datP;
    double amount = 0.0;    
    //char location[200]{};
    //char additionalInfo[300]{};
    int penaltyType;
    //PenaltyType penaltyType;	
};

