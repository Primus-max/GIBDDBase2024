#pragma once
#include <ctime>
#include <string>
#include "enums.h"
using namespace std;


struct Penalty
{
    int id = 0;
    int carId = 0;
    time_t datTime = 0;
    double penaltyAmount = 0.0;
    string location = "";
    string additionalInfo = "";

    PenaltyType penaltyType;	
};

