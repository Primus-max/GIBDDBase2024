#include "data.h"
#include <fstream>
#include <filesystem>

using namespace System;
using namespace System::Collections::Generic;
namespace fs = std::filesystem;

const char* pathToCars = "data/cars.xlsx";

List<Car^>^ getAllCars()
{
   // ifstream input(pathToCars);

 
  //  if(!input.is_open())
        //MessageBox(NULL, L"Unable to open file!", L"Error", MB_OK | MB_ICONERROR);

    List<Car^>^ cars = nullptr;
    //while (!input.eof()){
    //    Car^ newCar = nullptr;

    //   // input.getline(, );

    //    cars->Add(newCar);
    //}

    
    return cars;
    // TODO: вставьте здесь оператор return
}

void addCarToBase(Car^ car){
    
    //ofstream output(pathToCars, ios::app);
    ////MessageBox::Show("Произошла ошибка: файл не найден!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    ///*if (!output.is_open())
    //    cout << "Yt";*/
    ////if (!fs::exists(pathToCars))
    //char buff[100]{};
    //for (size_t i = 0; i < car->brand->Length; i++) {
    //    buff[i] = static_cast<char>(car->brand[i]);
    //}
    //buff[car->brand->Length] = '\0';

}
