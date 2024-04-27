#pragma once


enum PenaltyType
{
    SPEEDING,
    PARKING_VIOLATION,
    RED_LIGHT_INFRACTION,
    DRIVING_UNDER_INFLUENCE, // Вождение в нетрезвом виде
    NO_INSURANCE, // Отсутствие страховки
    ILLEGAL_PARKING, // Нелегальная парковка
    DRIVING_WITH_EXPIRED_LICENSE, // Вождение с истекшими правами
    OVERLOADING, // Перегрузка
    RUNNING_A_STOP_SIGN, // Проезд на красный свет
    DISTRACTED_DRIVING, // Отвлечённое вождение
    USING_MOBILE_PHONE_WHILE_DRIVING, // Разговор по телефону во время вождения
    FAILING_TO_YIELD, // Нарушение правил уступки
    DRIVING_IN_BUS_LANE, // Вождение в полосе для автобусов
    DRIVING_ON_THE_WRONG_SIDE_OF_THE_ROAD, // Движение по встречной полосе    
};

enum EngineType
{
    GASOLINE,
    DIESEL,
    ELECTRIC,
    HYBRID
};

enum TransmissionType
{
    MANUAL,
    AUTOMATIC,
    CVT, // Переменная передача
    SEMI_AUTOMATIC // Полуавтоматическая
};
