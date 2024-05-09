#include "CarRepository.h"
#include "InfoMessageService.h"
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

void CarRepository::Add(Car^ car)
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
	commandInsert->Parameters->AddWithValue("@reg_number", car->reg_number);
	commandInsert->Parameters->AddWithValue("@region", car->region);
	commandInsert->Parameters->AddWithValue("@color", car->color);

	try
	{
		connection->Open();

		if (commandInsert->ExecuteNonQuery() != 1)
			ErrorMessage("Не удалось добавить авто в базу");
		else
			SuccessMessage("Данные успешно добавлены в базу");
	}
	catch (const std::exception& ex) 
	{
		String^ errorMessage = "Ошибка при добавлении авто в базу данных: " + gcnew String(ex.what());
		ErrorMessage(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

List<Car^>^ CarRepository::GetAll()
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
			car->reg_number = reader["reg_number"]->ToString();
			car->region = Convert::ToInt16(reader["region"]);
			car->color = reader["color"]->ToString();

			cars->Add(car);
		}

		return cars;
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при чтении данных из базы данных: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}

	finally
	{
		connection->Close();
	}	
}

void CarRepository::Update(Car^ car)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryUpdate = "UPDATE [cars] SET brand = @brand, length = @length, clearance = @clearance, engine_capacity = @engine_capacity, engine_power = @engine_power, wheel_diameter = @wheel_diameter, reg_number = @reg_number, region = @region, color = @color WHERE id = @id";	
	OleDbCommand^ commandUpdate = gcnew OleDbCommand(queryUpdate, connection);

	commandUpdate->Parameters->AddWithValue("@brand", car->brand);
	commandUpdate->Parameters->AddWithValue("@length", car->length);
	commandUpdate->Parameters->AddWithValue("@clearance", car->clearance);
	commandUpdate->Parameters->AddWithValue("@engine_capacity", car->engineCapacity);
	commandUpdate->Parameters->AddWithValue("@engine_power", car->enginePower);
	commandUpdate->Parameters->AddWithValue("@wheel_diameter", car->wheelDiameter);
	commandUpdate->Parameters->AddWithValue("@reg_number", car->reg_number);
	commandUpdate->Parameters->AddWithValue("@region", car->region);
	commandUpdate->Parameters->AddWithValue("@color", car->color);
	commandUpdate->Parameters->AddWithValue("@id", car->id);

	try
	{
		connection->Open();
		if (commandUpdate->ExecuteNonQuery() != 1)
			ErrorMessage("Не удалось обновить авто в базе");
		else
			SuccessMessage("Данные успешно обновлены в базе");
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при обновлении данных в базе: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

bool CarRepository::Delete(int carId)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryDelete = "DELETE FROM cars WHERE id=?";
	OleDbCommand^ commandDelete = gcnew OleDbCommand(queryDelete, connection);

	commandDelete->Parameters->AddWithValue("?", carId);

	try
	{
		connection->Open();
		if (commandDelete->ExecuteNonQuery() != 1) {
			ErrorMessage("Не удалось удалить авто из базы");
			return false;
		}			
		else {
			SuccessMessage("Данные успешно удалены из базы");
			return true;
		}
		
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при удалении данных из базы: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
		return false;
	}
	finally
	{
		connection->Close();
	}
}

List<Car^>^ CarRepository::FindByNumber(String^ number)
{
	List<Car^>^ cars = gcnew List<Car^>();
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryGet = "SELECT * FROM cars WHERE cars.reg_number = @number";
	OleDbCommand^ commandGet = gcnew OleDbCommand(queryGet, connection);

	commandGet->Parameters->AddWithValue("@number", number);

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
			car->reg_number = reader["reg_number"]->ToString();
			car->region = Convert::ToInt16(reader["region"]);
			car->color = reader["color"]->ToString();

			cars->Add(car);
		}

		return cars;
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при чтении данных из базы данных: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}

	finally
	{
		connection->Close();
	}
}

List<Car^>^ CarRepository::FindByColor(String^ color)
{
	List<Car^>^ cars = gcnew List<Car^>();
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryGet = "SELECT * FROM cars WHERE cars.color = @color";
	OleDbCommand^ commandGet = gcnew OleDbCommand(queryGet, connection);

	commandGet->Parameters->AddWithValue("@number", color);

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
			car->reg_number = reader["reg_number"]->ToString();
			car->region = Convert::ToInt16(reader["region"]);
			car->color = reader["color"]->ToString();

			cars->Add(car);
		}

		return cars;
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при чтении данных из базы данных: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}

	finally
	{
		connection->Close();
	}
}

List<Car^>^ CarRepository::FindByEngineVolume(String^ volume)
{
	List<Car^>^ cars = gcnew List<Car^>();
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryGet = "SELECT * FROM cars WHERE cars.volume = @volume";
	OleDbCommand^ commandGet = gcnew OleDbCommand(queryGet, connection);

	commandGet->Parameters->AddWithValue("@volume", volume);

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
			car->reg_number = reader["reg_number"]->ToString();
			car->region = Convert::ToInt16(reader["region"]);
			car->color = reader["color"]->ToString();

			cars->Add(car);
		}

		return cars;
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при чтении данных из базы данных: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}

	finally
	{
		connection->Close();
	}
}
