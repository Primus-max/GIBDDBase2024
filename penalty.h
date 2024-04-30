#pragma once
#include <ctime>
#include "enums.h"
using namespace std;

public ref class Penalty
{
public:
    int id = 0;
    int carId = 0;
    time_t datTime = 0;
    double penaltyAmount = 0.0;    
    //char location[200]{};
    //char additionalInfo[300]{};

    PenaltyType penaltyType;	
};

