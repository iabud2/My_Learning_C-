#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;

class clsUser :public clsPerson
{
private:

	enum enMode {EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;
	string _Username;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;
	
	string _PrepareLoginRecord(string Separator = "#//#")
	{
		clsDate Date;
		string RecordLine;
		RecordLine += Date.GetSystemDateTimeString() + Separator;
		RecordLine += UserName + Separator;
		RecordLine += clsUtil::EncryptText(Password) +Separator;
		RecordLine += to_string(Permissions);
		return RecordLine;
	}

	static clsUser _ConvertLinetoUserObject(string Line, string Separator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Separator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));
	}

	static string _ConverUserObjectToLine(clsUser User, string Separator = "#//#")
	{
		string UserRecord = "";
		UserRecord += User.FirstName + Separator;
		UserRecord += User.LastName + Separator;
		UserRecord += User.Email + Separator;
		UserRecord += User.Phone + Separator;
		UserRecord += User.UserName + Separator;
		UserRecord += clsUtil::EncryptText(User.Password) + Separator;
		UserRecord += to_string(User.Permissions);

		return UserRecord;
	}

	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsUser User = _ConvertLinetoUserObject(Line);

				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;
	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsUser U : vUsers)
			{
				if (U.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverUserObjectToLine(U);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}
	}

	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);
	}

	void _AddDataLineToFile(string  DataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << DataLine << endl;

			MyFile.close();
		}

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConverUserObjectToLine(*this));
	}
	
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	struct stLoginRegisterRecord;

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Separator = "#//#")
	{
		stLoginRegisterRecord Record;
		vector<string> vRecords;
		vRecords = clsString::Split(Line, Separator);
		Record.DateTime = vRecords[0];
		Record.Username = vRecords[1];
		Record.password = vRecords[2];
		Record.permissions = stoi(vRecords[3]);
		return Record;
	}


public:

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string UserName, string PassWord, int Permissions)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_Username = UserName;
		_Password = PassWord;
		_Permissions = Permissions;
	}

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2,
		pDeleteClient = 4, pUpdateClient = 8,
		pFindClient = 16, pTransactions = 32,
		pManageUsers = 64, pLoginRegister = 128,
	};

	struct stLoginRegisterRecord
	{
		string DateTime;
		string Username;
		string password;
		int permissions;
	};

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted()
	{
		return(_MarkedForDelete);
	}

	string GetUsername()
	{
		return _Username;
	}

	void SetUserName(string Un)
	{
		_Username = Un;
	}

	_declspec(property(get = GetUsername, put = SetUserName)) string UserName;

	string GetPassword()
	{
		return _Password;
	}

	void SetPassword(string password)
	{
		_Password = password;
	}

	_declspec(property(get = GetPassword, put = SetPassword))string Password;

	int GetPermissions()
	{
		return _Permissions;
	}

	void SetPermissions(int permissions)
	{
		_Permissions = permissions;
	}

	_declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}
		return _GetEmptyUserObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
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
			//This will add new record to file or database
			if (clsUser::IsUserExist(_Username))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNew();
				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}

	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	bool Delete()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == _Username)
			{
				U._MarkedForDelete = true;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);

		*this = _GetEmptyUserObject();

		return true;

	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermissions(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
		{
			return true;
		}
		if ((Permission & this->Permissions) == Permission)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void RegisterLogin()
	{
		string login_time = _PrepareLoginRecord();
		fstream LoginFile;
		LoginFile.open("LoginRegister.txt", ios::out | ios::app);
		if (LoginFile.is_open())
		{
			LoginFile << login_time << endl;
			LoginFile.close();
		}
	}

	static vector <stLoginRegisterRecord>  GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vRecords;
		
		fstream LoginRegisterFile;
		LoginRegisterFile.open("LoginRegister.txt", ios::in);
		if (LoginRegisterFile.is_open())
		{
			string Line;
			stLoginRegisterRecord Record;
			while (getline(LoginRegisterFile, Line))
			{
				Record = _ConvertLoginRegisterLineToRecord(Line);
				vRecords.push_back(Record);
			}
			LoginRegisterFile.close();
		}

		return vRecords;
	}
};