#include "InfoMessageService.h"
#include "Penaltyrepository.h"
#include <exception>
#include <iostream>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::OleDb;
using namespace System::Windows::Forms;

PenaltyRepository::PenaltyRepository(String^ connStr)
{
	_connectionString = connStr;
}

void PenaltyRepository::Add(Penalty^ penalty)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryAdd = "INSERT INTO [penalty] (date_p, amount, penalty_type, car) VALUES(@date_p, @amount, @penalty_type, @car)";
	OleDbCommand^ commandAdd = gcnew OleDbCommand(queryAdd, connection);

	commandAdd->Parameters->AddWithValue("@date_p", penalty->datP);
	commandAdd->Parameters->AddWithValue("@amount", penalty->amount);
	commandAdd->Parameters->AddWithValue("@penalty_type", penalty->penaltyType);
	commandAdd->Parameters->AddWithValue("@car", penalty->carId);

	try
	{
		connection->Open();

		if (commandAdd->ExecuteNonQuery() != 1)
			ErrorMessage("Не удалось добавить штраф в базу");
		else
			SuccessMessage("Данные успешно добавлены в базу");

	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при добавлении штрафа в базу данных: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

List<Penalty^>^ PenaltyRepository::GetAll()
{
	List<Penalty^>^ penalties = gcnew List<Penalty^>();

	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryGet = "SELECT * FROM [penalty]";
	OleDbCommand^ commandRead = gcnew OleDbCommand(queryGet, connection);


	try
	{
		connection->Open();
		OleDbDataReader^ reader = commandRead->ExecuteReader();

		while (reader->Read())
		{
			Penalty^ penalty = gcnew Penalty();

			penalty->id = Convert::ToInt32(reader["id"]);
			penalty->datP = Convert::ToDateTime(reader["date_p"]);
			penalty->amount = Convert::ToDouble(reader["amount"]);
			penalty->penaltyType = Convert::ToInt16(reader["penalty_type"]);
			penalty->carId = Convert::ToInt32(reader["car"]);

			penalties->Add(penalty);
		}

		return penalties;
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при добавлении штрафа в базу данных: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

void PenaltyRepository::Update(Penalty^ penalty)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryUpdate = "UPDATE [penalty] SET date_p = @date_p, amount = @amount, penalty_type = @penalty_type, car = @car WHERE id = @id";
	OleDbCommand^ commandUpdate = gcnew OleDbCommand(queryUpdate, connection);

	commandUpdate->Parameters->AddWithValue("@date_p", penalty->datP);
	commandUpdate->Parameters->AddWithValue("@amount", penalty->amount);
	commandUpdate->Parameters->AddWithValue("@penalty_type", penalty->penaltyType);
	commandUpdate->Parameters->AddWithValue("@car", penalty->carId);
	commandUpdate->Parameters->AddWithValue("@id", penalty->id);

	try
	{
		connection->Open();

		if (commandUpdate->ExecuteNonQuery() != 1)
			ErrorMessage("Не удалось обновить штраф в базе");
		else
			SuccessMessage("Данные успешно обновлены в базе");

	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при добавлении штрафа в базу данных: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

void PenaltyRepository::Delete(int id)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryDelete = "DELETE [penalty] WHERE id = @id";
	OleDbCommand^ commandUpdate = gcnew OleDbCommand(queryDelete, connection);

	commandUpdate->Parameters->AddWithValue("@id", id);

	try
	{
		connection->Open();

		if (commandUpdate->ExecuteNonQuery() != 1)
			ErrorMessage("Не удалось удалить штраф в базе");
		else
			SuccessMessage("Данные успешно удалены из базы");

	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при удалении штрафа из базы данных: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}
