#pragma once
#include <ctime>
#include "enums.h"


public ref class Penalty
{
public:
    int id = 0;
    int carId = 0;
    time_t datP = 0;
    double amount = 0.0;    
    //char location[200]{};
    //char additionalInfo[300]{};
    int penaltyType;
    //PenaltyType penaltyType;	
};

