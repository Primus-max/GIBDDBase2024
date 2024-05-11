#include "InfoMessageService.h"
#include "Penaltyrepository.h"
#include <exception>
#include <iostream>

using namespace System;
using namespace System::Globalization;
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
			ErrorMessage("�� ������� �������� ����� � ����");
		else
			SuccessMessage("������ ������� ��������� � ����");

	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "������ ��� ���������� ������ � ���� ������: " + gcnew String(ex->Message);
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
		String^ errorMessage = "������ ��� ��������� ���� ����: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

Penalty^ PenaltyRepository::GetById(int id)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryGet = "SELECT * FROM [penalty] WHERE id = @id";
	OleDbCommand^ commandGet = gcnew OleDbCommand(queryGet, connection);

	Penalty^ penalty = gcnew Penalty(); 

	try
	{
		connection->Open();
		commandGet->Parameters->AddWithValue("@id", id);

		OleDbDataReader^ reader = commandGet->ExecuteReader(); // ��������� ������ � �������� reader

		// ���������, ���� �� ����������
		if (reader->Read())
		{
			// ������� ��������� Penalty � ��������� ��� ������� �� ���������� �������
			penalty = gcnew Penalty();
			penalty->id = id;
			penalty->datP = Convert::ToDateTime(reader["datP"]); // �����������, ��� ��� ��� ������� � �����
			penalty->penaltyType = Convert::ToInt32(reader["penaltyType"]); // �����������, ��� ��� ��� ������� � ����� ������
			penalty->amount = Convert::ToDouble(reader["amount"]); // �����������, ��� ��� ��� ������� � ������
			penalty->carId = Convert::ToInt32(reader["carId"]); // �����������, ��� ��� ��� ������� � ��������������� ����������
		}

		return penalty;
		reader->Close(); // ��������� reader ����� �������������
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "������ ��� ��������� ���������� � ������: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
		return penalty;
	}
	finally
	{
		connection->Close();
	}

	return penalty; // ���������� ������ Penalty
}


List<Penalty^>^ PenaltyRepository::GetAllForCar(int cardId)
{
	List<Penalty^>^ penalties = gcnew List<Penalty^>();

	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryGet = "SELECT * FROM [penalty] WHERE car=@car";
	OleDbCommand^ commandGet = gcnew OleDbCommand(queryGet, connection);

	commandGet->Parameters->AddWithValue("@car", cardId);

	try
	{
		connection->Open();
		OleDbDataReader^ reader = commandGet->ExecuteReader();

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
		String^ errorMessage = "������ ��� ��������� ���� ������� ��� ����: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

double PenaltyRepository::GetAmountPenaltiesByCarId(int cardId)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryGet = "SELECT SUM(amount) AS a FROM [penalty] WHERE car=@car";
	OleDbCommand^ commandGet = gcnew OleDbCommand(queryGet, connection);

	commandGet->Parameters->AddWithValue("@car", cardId);

	try
	{
		connection->Open();
		OleDbDataReader^ reader = commandGet->ExecuteReader();

		double sumPenalties = Convert::ToDouble(reader);
		return sumPenalties;
	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "������ ��� ��������� ���� ������� ��� ����: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
		return -1;
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
			ErrorMessage("�� ������� �������� ����� � ����");
		else
			SuccessMessage("������ ������� ��������� � ����");

	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "������ ��� ���������� ������ � ���� ������: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

bool PenaltyRepository::Delete(int id)
{
	OleDbConnection^ connection = gcnew OleDbConnection(_connectionString);
	String^ queryDelete = "DELETE FROM penalty WHERE id=?";
	OleDbCommand^ commandDelete = gcnew OleDbCommand(queryDelete, connection);

	commandDelete->Parameters->AddWithValue("?", id);

	try
	{
		connection->Open();

		if (commandDelete->ExecuteNonQuery() != 1) {
			ErrorMessage("�� ������� ������� ����� � ����");
			return false;
		}
		else {
			SuccessMessage("������ ������� ������� �� ����");
			return true;
		}


	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "������ ��� �������� ������ �� ���� ������: " + gcnew String(ex->Message);
		ErrorMessage(errorMessage);
		return false;
	}
	finally
	{
		connection->Close();
	}
}
