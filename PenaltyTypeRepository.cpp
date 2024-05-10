#include "PenaltyTypeRepository.h"
#include "InfoMessageService.h"

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
			ErrorMessage("Не удалось добавить тип штрафа в базу");
		else
			SuccessMessage("Данные успешно добавлены в базу");

	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при добавлении описания штрафа в базу данных: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
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
		ErrorMessage(errorMessage);
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
	String^ queryGet = "SELECT pt.* FROM penalty_types AS pt INNER JOIN penalty AS p ON pt.id = p.penalty_type  WHERE p.car = @carId";
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
		ErrorMessage(errorMessage);
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
			ErrorMessage("Не удалось обновить тип штрафа в базе");
		else
			SuccessMessage("Данные успешно обновлены в базе");

	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при добавлении описания штрафа в базу данных: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

bool PenaltyTypeRepository::Delete(int penaltyTypeId)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryDelete = "DELETE FROM [penalty_types] WHERE id = @id";
	OleDbCommand^ commandDelete = gcnew OleDbCommand(queryDelete, connection);

	commandDelete->Parameters->AddWithValue("@id", penaltyTypeId);

	try
	{
		connection->Open();

		if (commandDelete->ExecuteNonQuery() != 1) {
			ErrorMessage("Не удалось удалить тип штрафа в базе");
			return false;
		}
		else {
			SuccessMessage("Данные успешно удалены из базы");
			return true;
		}
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при удалении описания штрафа из базы данных: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
		return false;
	}
	finally
	{
		connection->Close();
	}
}
