#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsers.h"
#include "clsLoginScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
using namespace std;

class clsMainScreen: protected clsScreen
{
private:
	enum enMainMenueOptions{eListClients =1, eAddNewClient =2, eDeleteClient = 3,
	eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6
	,eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 10] ? ";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 10);
		return choice;
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientsListScreen::ShowClientsScreen();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewCientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientSceen();
	}

	static void _ShowTransactionsMenue()
	{
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersMenue()
	{
		clsManageUsers::ShowManageUsersMenu();
	}

	static void _ShowRegisterLoginSreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeMenue()
	{
		clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerformMainMenueOption(enMainMenueOptions mmOption)
	{
		switch (mmOption)
		{
		case enMainMenueOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eShowTransactionsMenu:
		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;;
		}
		case clsMainScreen::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eLoginRegister:
		{
			system("cls");
			_ShowRegisterLoginSreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eExit:
		{
			system("cls");
			_Logout();			
			break;
		}
		}
	}

public:
	
	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMainScreen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformMainMenueOption(enMainMenueOptions(_ReadMainMenueOption()));
	}

};

