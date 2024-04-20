#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
#include "clsDate.h"
using namespace std;

class clsBankClient : public clsPerson
{
private :

	enum enMode {EmptyMode = 0, UpdateMode = 1, AddNewMode =2};
	
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
    {
		vector <string> vClientDate;
		vClientDate = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vClientDate[0], vClientDate[1], vClientDate[2], vClientDate[3],
			vClientDate[4], vClientDate[5], stof(vClientDate[6]));
    }

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}

	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLineToClientObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}
		return vClients;
	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient C : vClients)
			{
				if (C.MarkForDeleted() == false)
				{
					DataLine = _ConverClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();

		}

	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClients);

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	struct stTransferLogRecord;

	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Separator = "#//#")
	{
		stTransferLogRecord Transfer;
		vector<string> vTransfer;
		vTransfer = clsString::Split(Line, Separator);
		Transfer.Datetime = vTransfer[0];
		Transfer.Username = vTransfer[1];
		Transfer.SourceAccountNumber = vTransfer[2];
		Transfer.DestinationAccountNumber = vTransfer[3];
		Transfer.Amount = stof(vTransfer[4]);
		Transfer.SrcBalanceAfter = stof(vTransfer[5]);
		Transfer.DestBalanceAfter = stof(vTransfer[6]);
		return Transfer;
	}
	
	string _PrepareTransferLogRecord(float t_Amount, clsBankClient DestClient, string Username, string Separator = "#//#")
	{
		string TransferLogLine = "";
		TransferLogLine += clsDate::GetSystemDateTimeString() + Separator;
		TransferLogLine += Username + Separator;
		TransferLogLine += AccountNumber() + Separator;
		TransferLogLine += DestClient.AccountNumber() + Separator;
		TransferLogLine += to_string(t_Amount) + Separator;
		TransferLogLine += to_string(AccountBalance) + Separator;
		TransferLogLine += to_string(DestClient.AccountBalance);
		return TransferLogLine;
	}

	void _RegisterTransferLogRecord(float Amount, clsBankClient DestClient, string Username)
	{
		string DataLine = _PrepareTransferLogRecord(Amount, DestClient, Username);
		fstream TransfersFile;
		TransfersFile.open("TransferLog.txt", ios::out | ios::app);
		if(TransfersFile.is_open())
		{
			TransfersFile << DataLine << endl;
			TransfersFile.close();
		}
	}

public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	struct stTransferLogRecord
	{
		string Datetime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		string Username;
		float Amount;
		float SrcBalanceAfter;
		float DestBalanceAfter;
	};

	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	//Read Only
	string AccountNumber()
	{
		return _AccountNumber;
	}

	bool MarkForDeleted()
	{
		return _MarkForDelete;
	}

	static float GetTotalBalances()
	{
		vector <clsBankClient> vClients = GetClientsList();
		float TotalBalances = 0;
		for (clsBankClient& C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
	}
	//-----------

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	
	_declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	_declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
			
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
				MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}

		_SaveCleintsDataToFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;	
	}

	enum enSaveResults {svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
				break;

			}
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}
		}
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}
	
	//step2 in Project:
	//Transactions Functions:

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
		}
		return true;
	}

	bool Transfer(float Amount, clsBankClient& DestClient, string Username)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestClient.Deposit(Amount);
		_RegisterTransferLogRecord(Amount, DestClient, Username);
		return true;
	}
	static vector <stTransferLogRecord>  GetTransfersLogList()
	{
		vector <stTransferLogRecord> vTransfers;

		fstream TransfersFile;
		TransfersFile.open("TransferLog.txt", ios::in);
		if (TransfersFile.is_open())
		{
			string Line;
			stTransferLogRecord Transfer;
			while (getline(TransfersFile, Line))
			{
				Transfer = _ConvertTransferLogLineToRecord(Line);
				vTransfers.push_back(Transfer);
			}
			TransfersFile.close();
		}
		return vTransfers;
	}
};

