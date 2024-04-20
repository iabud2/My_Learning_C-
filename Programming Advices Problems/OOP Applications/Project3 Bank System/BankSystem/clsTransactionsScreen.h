#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOption {
		eDeposit = 1, eWithDraw = 2,
		eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5, eShowMainMenue = 6
	};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 6]? :";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6 :");
		return choice;
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithDrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::_ShowTransferLogScreen();
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transaction Menue..";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static void _PerformTransactionsMenueOption(enTransactionsMenueOption TM_Option)
	{
		switch (TM_Option)
		{
		case clsTransactionsScreen::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eWithDraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			break;
		}
		case clsTransactionsScreen::eShowMainMenue:
		{
			
		}
		}
	}
public:
	static void ShowTransactionsMenue()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t  Transactions Screen");
		cout << setw(37) << left << "" << "============================================ \n";
		cout << setw(37) << left << "" << "\t\t Transactions Menue\n";
		cout << setw(37) << left << "" << "=========================================== \n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=========================================== \n";
		_PerformTransactionsMenueOption(enTransactionsMenueOption(_ReadTransactionsMenueOption()));
	}
};
