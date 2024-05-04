#include "CarRepository.h"
#include <exception>
#include <iostream>
using namespace System::Data::OleDb;
using namespace System::Windows::Forms;

CarRepository::CarRepository(String^ connStr)
{
    _connectionString = connStr;
}

void CarRepository::AddCar(Car^ car)
{
    OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
    String^ queryInsert = "INSERT INTO cars(brand, length, clearance, engine_capacity, engine_power, wheel_diameter, number, region, color) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
    OleDbCommand^ commandInsert = gcnew OleDbCommand(queryInsert, connection);

    commandInsert->Parameters->AddWithValue("?", car->brand);
    commandInsert->Parameters->AddWithValue("?", car->length);
    commandInsert->Parameters->AddWithValue("?", car->clearance);
    commandInsert->Parameters->AddWithValue("?", car->engineCapacity);
    commandInsert->Parameters->AddWithValue("?", car->enginePower);
    commandInsert->Parameters->AddWithValue("?", car->wheelDiameter);
    commandInsert->Parameters->AddWithValue("?", car->number);
    commandInsert->Parameters->AddWithValue("?", car->region);
    commandInsert->Parameters->AddWithValue("?", car->color);

    try
    {
        connection->Open();
        commandInsert->ExecuteNonQuery();
    }
    finally
    {
        connection->Close();
    }
}

List<Car^>^ CarRepository::GetAllCars()
{
    List<Car^>^ cars = gcnew List<Car^>();
    OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
    String^ queryGet = "SELECT * FROM cars";
    OleDbCommand^ commandGet = gcnew OleDbCommand(queryGet, connection);

    try
    {
        connection->Open();
        OleDbDataReader^ reader = commandGet->ExecuteReader();

        while (reader->Read())
        {
            Car^ car = gcnew Car();
            car->id = Convert::ToInt32(reader["id"]);
            car->brand = reader["brand"]->ToString();
            car->length = Convert::ToInt16(reader["length"]);
            car->clearance = Convert::ToInt16(reader["clearance"]);
            car->engineCapacity = Convert::ToInt16(reader["engine_capacity"]);
            car->enginePower = Convert::ToInt16(reader["engine_power"]);
            car->wheelDiameter = Convert::ToInt16(reader["wheel_diameter"]);
            car->number = reader["number"]->ToString();
            car->region = Convert::ToInt16(reader["region"]);
            car->color = reader["color"]->ToString();

            cars->Add(car);
        }
    }
    catch (const std::exception&)
    {
        MessageBox::Show("Ошибка при чтении данных из базы данных");
    }

    return cars;
}

void CarRepository::UpdateCar(Car^ car)
{
    // Реализация метода UpdateCar
}

void CarRepository::DeleteCar(int carId)
{
    // Реализация метода DeleteCar
}
