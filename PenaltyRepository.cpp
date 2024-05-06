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
			MessageBox::Show("Не удалось добавить штраф в базу", "Ошибка!");

	}
	catch (OleDbException^ ex)
	{
		String^ errorMessage = "Ошибка при добавлении авто в базу данных: " + gcnew String(ex->Message);
		MessageBox::Show(errorMessage);
	}
	finally
	{
		connection->Close();
	}
}

List<Penalty^>^ PenaltyRepository::GetAll()
{
	throw gcnew System::NotImplementedException();
	// TODO: вставьте здесь оператор return
}

void PenaltyRepository::Update(Penalty^ penalty)
{
	throw gcnew System::NotImplementedException();
}

void PenaltyRepository::Delete(int id)
{
	throw gcnew System::NotImplementedException();
}
