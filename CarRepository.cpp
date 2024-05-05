#include "CarRepository.h"
#include <exception>
#include <iostream>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::OleDb;
using namespace System::Windows::Forms;

CarRepository::CarRepository(String^ connStr)
{
	_connectionString = connStr;
}

void CarRepository::AddCar(Car^ car)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryInsert = "INSERT INTO [cars] (brand, length, clearance, engine_capacity, engine_power, wheel_diameter, reg_number, region, color) VALUES (@brand, @length, @clearance, @engine_capacity, @engine_power, @wheel_diameter, @reg_number, @region, @color)";
	OleDbCommand^ commandInsert = gcnew OleDbCommand(queryInsert, connection);
		
	commandInsert->Parameters->AddWithValue("@brand", car->brand);
	commandInsert->Parameters->AddWithValue("@length", car->length);
	commandInsert->Parameters->AddWithValue("@clearance", car->clearance);
	commandInsert->Parameters->AddWithValue("@engine_capacity", car->engineCapacity);
	commandInsert->Parameters->AddWithValue("@engine_power", car->enginePower);
	commandInsert->Parameters->AddWithValue("@wheel_diameter", car->wheelDiameter);
	commandInsert->Parameters->AddWithValue("@reg_number", car->number);
	commandInsert->Parameters->AddWithValue("@region", car->region);
	commandInsert->Parameters->AddWithValue("@color", car->color);

	try
	{
		connection->Open();
		commandInsert->ExecuteNonQuery();
	}
	catch (const std::exception& ex) 
	{
		String^ errorMessage = "������ ��� ������ ������ �� ���� ������: " + gcnew String(ex.what());
		MessageBox::Show(errorMessage);
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
			car->engineCapacity = Convert::ToDouble(reader["engine_capacity"]);
			car->enginePower = Convert::ToInt16(reader["engine_power"]);
			car->wheelDiameter = Convert::ToInt16(reader["wheel_diameter"]);
			car->number = reader["reg_number"]->ToString();
			car->region = Convert::ToInt16(reader["region"]);
			car->color = reader["color"]->ToString();

			cars->Add(car);
		}
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "������ ��� ������ ������ �� ���� ������: " + gcnew String(ex->Message);
		MessageBox::Show(errorMessage);
	}

	finally
	{
		connection->Close();
	}

	return cars;
}

void CarRepository::UpdateCar(Car^ car)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryUpdate = "UPDATE [cars] SET brand='"+ car->brand +"', length="+ car->length +", clearance="+ car->clearance +", engine_capacity="+car->engineCapacity+",  engine_power="+ car->enginePower +", wheel_diameter="+ car->wheelDiameter +", number='"+ car->number +"', region="+ car->region +", color='"+ car->color +"'  WHERE id = " + car->id;
	OleDbCommand^ commandUpdate = gcnew OleDbCommand(queryUpdate, connection);

	/*commandUpdate->Parameters->AddWithValue("?", car->brand);
	commandUpdate->Parameters->AddWithValue("?", car->length);
	commandUpdate->Parameters->AddWithValue("?", car->clearance);
	commandUpdate->Parameters->AddWithValue("?", car->engineCapacity);
	commandUpdate->Parameters->AddWithValue("?", car->enginePower);
	commandUpdate->Parameters->AddWithValue("?", car->wheelDiameter);
	commandUpdate->Parameters->AddWithValue("?", car->number);
	commandUpdate->Parameters->AddWithValue("?", car->region);
	commandUpdate->Parameters->AddWithValue("?", car->color);
	commandUpdate->Parameters->AddWithValue("?", car->id);*/

	try
	{
		connection->Open();
		commandUpdate->ExecuteNonQuery();
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "������ ��� ���������� ������ � ����: " + gcnew String(ex->Message);
		MessageBox::Show(errorMessage);
	}
	finally
	{
		connection->Close();
	}

}

void CarRepository::DeleteCar(int carId)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryDelete = "DELETE FROM cars WHERE id=?";
	OleDbCommand^ commandDelete = gcnew OleDbCommand(queryDelete, connection);

	commandDelete->Parameters->AddWithValue("?", carId);

	try
	{
		connection->Open();
		commandDelete->ExecuteNonQuery();
	}
	catch (const std::exception& ex)
	{
		String^ errorMessage = "������ ��� ������ ������ �� ���� ������: " + gcnew String(ex.what());
		MessageBox::Show(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}
