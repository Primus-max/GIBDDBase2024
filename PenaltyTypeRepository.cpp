#include "PenaltyTypeRepository.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::OleDb;
using namespace System::Windows::Forms;

PenaltyTypeRepository::PenaltyTypeRepository(String^ connStr)
{
    _connectionString = connStr;
}

void PenaltyTypeRepository::Add(PenaltyType^ penaltyType)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryAdd = "INSERT INTO [penalty_types] (penalty_type, price) VALUES(@penalty_type, @price)";
	OleDbCommand^ commandAdd = gcnew OleDbCommand(queryAdd, connection);

	commandAdd->Parameters->AddWithValue("@penalty_type", penaltyType->penaltyType);
	commandAdd->Parameters->AddWithValue("@price", penaltyType->price);	

	try
	{
		connection->Open();

		if (commandAdd->ExecuteNonQuery() != 1)
			MessageBox::Show("Не удалось добавить описание штрафа в базу", "Ошибка!");

	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при добавлении описания штрафа в базу данных: " + gcnew String(ex->Message);
		MessageBox::Show(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

List<PenaltyType^>^ PenaltyTypeRepository::GetAll()
{
	List<PenaltyType^>^ penaltiesTypes = gcnew List<PenaltyType^>();

	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryGet = "SELECT * FROM [penalty_types]";
	OleDbCommand^ commandRead = gcnew OleDbCommand(queryGet, connection);


	try
	{
		connection->Open();
		OleDbDataReader^ reader = commandRead->ExecuteReader();

		while (reader->Read())
		{
			PenaltyType^ penaltyType = gcnew PenaltyType();

			penaltyType->id = Convert::ToInt32(reader["id"]);
			penaltyType->penaltyType = reader["penalty_type"]->ToString();
			penaltyType->price = Convert::ToDouble(reader["price"]);
			
			penaltiesTypes->Add(penaltyType);
		}

		return penaltiesTypes;
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при добавлении описания штрафа в базу данных: " + gcnew String(ex->Message);
		MessageBox::Show(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

List<PenaltyType^>^ PenaltyTypeRepository::GetAllTypesByCarId(int carId)
{
	List<PenaltyType^>^ penaltiesTypes = gcnew List<PenaltyType^>();

	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryGet = "SELECT pt.id, pt.penalty_type, pt.price FROM penalty AS p INNER JOIN penalty_types AS pt ON p.penalty_type = pt.id WHERE p.car = @carId";
	OleDbCommand^ commandRead = gcnew OleDbCommand(queryGet, connection);

	commandRead->Parameters->AddWithValue("@carId", carId);
	try
	{
		connection->Open();
		OleDbDataReader^ reader = commandRead->ExecuteReader();

		while (reader->Read())
		{
			PenaltyType^ penaltyType = gcnew PenaltyType();

			penaltyType->id = Convert::ToInt32(reader["id"]);
			penaltyType->penaltyType = reader["penalty_type"]->ToString();
			penaltyType->price = Convert::ToDouble(reader["price"]);

			penaltiesTypes->Add(penaltyType);
		}

		return penaltiesTypes;
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при получении данных: " + gcnew String(ex->Message);
		MessageBox::Show(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}



void PenaltyTypeRepository::Update(PenaltyType^ penaltyType)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);	
	String^ queryUpdate = "UPDATE [penalty_types] SET penalty_type = @penalty_type, price = @price WHERE id = @id";
	OleDbCommand^ commandUpdate = gcnew OleDbCommand(queryUpdate, connection);

	commandUpdate->Parameters->AddWithValue("@penalty_type", penaltyType->penaltyType);
	commandUpdate->Parameters->AddWithValue("@price", penaltyType->price);
	commandUpdate->Parameters->AddWithValue("@id", penaltyType->id);

	try
	{
		connection->Open();

		if (commandUpdate->ExecuteNonQuery() != 1)
			MessageBox::Show("Не удалось обновить описание штрафа в базе", "Ошибка!");

	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при добавлении описания штрафа в базу данных: " + gcnew String(ex->Message);
		MessageBox::Show(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

void PenaltyTypeRepository::Delete(int penaltyTypeId)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryDelete = "DELETE [penalty] WHERE id = @id";
	OleDbCommand^ commandUpdate = gcnew OleDbCommand(queryDelete, connection);

	commandUpdate->Parameters->AddWithValue("@id", penaltyTypeId);

	try
	{
		connection->Open();

		if (commandUpdate->ExecuteNonQuery() != 1)
			MessageBox::Show("Не удалось удалить описание штрафа в базе", "Ошибка!");

	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при удалении описания штрафа из базы данных: " + gcnew String(ex->Message);
		MessageBox::Show(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}
