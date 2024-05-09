// ICarSearchable.h

#pragma once
#include "Car.h"

public enum class SearchType
{
    ByNumber,
    ByColor,
    ByEngineVolume,
    // Добавь другие типы поиска по необходимости
};

public interface class ICarSearchable
{
public:
    List<Car^>^ Find(String^ searchValue, SearchType searchType);
};