#pragma once
#include <ctime>
#include <string>
using namespace std;


struct Penalty
{
    int id = 0;
    int carId = 0;
    time_t datTime = 0;
    double penaltyAmount = 0.0;
    string location = "";
    string additionalInfo = "";

    //PenaltyType penaltyType;	
};


enum PenaltyType
{
    SPEEDING,
    PARKING_VIOLATION,
    RED_LIGHT_INFRACTION,
    DRIVING_UNDER_INFLUENCE, // �������� � ��������� ����
    NO_INSURANCE, // ���������� ���������
    ILLEGAL_PARKING, // ����������� ��������
    DRIVING_WITH_EXPIRED_LICENSE, // �������� � ��������� �������
    OVERLOADING, // ����������
    RUNNING_A_STOP_SIGN, // ������ �� ������� ����
    DISTRACTED_DRIVING, // ����������� ��������
    USING_MOBILE_PHONE_WHILE_DRIVING, // �������� �� �������� �� ����� ��������
    FAILING_TO_YIELD, // ��������� ������ �������
    DRIVING_IN_BUS_LANE, // �������� � ������ ��� ���������
    DRIVING_ON_THE_WRONG_SIDE_OF_THE_ROAD, // �������� �� ��������� ������    
};

const string penaltyTypeStrings[] = {
    "���������� ��������",
    "��������� ������ ��������",
    "������ �� ������� ����",
    "�������� � ��������� ����",
    "���������� ���������",
    "����������� ��������",
    "�������� � ��������� �������",
    "����������",
    "������ �� ������� ����",
    "����������� ��������",
    "�������� �� �������� �� ����� ��������",
    "��������� ������ �������",
    "�������� � ������ ��� ���������",
    "�������� �� ��������� ������"
};