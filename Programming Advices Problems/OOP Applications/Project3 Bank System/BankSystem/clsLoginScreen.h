#pragma once
#include <iostream>
#include <iomanip>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "Global.h"
class clsLoginScreen:protected clsScreen
{
private: 
	static void _ReadUsernamePassword(string &un, string &pw)
	{
		cout << "Enter Username : ";
		cin >> un;
		cout << "Enter Password : ";
		cin >> pw;
	}

	static void _Login()
	{
		short tries = 3;
		bool LoginFailed = false;
		string username, password;
		do
		{
			if (LoginFailed && tries > 0)
			{
				cout << "\nInvalid Username/Password!\n";
				cout << "You Have " << tries << " Tries to login.\n\n";
			}
			if (tries == 0)
			{
				cout << "\nyor are locked after 3 faild trails.\n\n";
				return;
			}

			_ReadUsernamePassword(username, password);
			CurrentUser = clsUser::Find(username, password);
			LoginFailed = CurrentUser.IsEmpty();
			tries--;
		} while (LoginFailed);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		ShowLoginScreen();
	}

public:

	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}
};
