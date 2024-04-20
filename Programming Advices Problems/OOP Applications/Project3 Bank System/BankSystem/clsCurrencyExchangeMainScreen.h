#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalcolatorScreen.h"
using namespace std;

class clsCurrencyExchangeMainScreen:protected clsScreen
{
private:
	enum enCurrencyMenueOptions 
	{
		cListCurrencies = 1 , cFindCurrency = 2, cUpdateRate = 3, cCurrencyCalculater = 4, cMainMenue = 5, 
	};
	
	static short _ReadCurrencyMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 5] ? ";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 5);
		return choice;
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << "\n\nPress any key to go back to Currencies Menue...";
		system("pause>0");
		ShowCurrenciesMenue();
	}
	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalcolatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyMenueOption(enCurrencyMenueOptions Option)
	{
		switch (Option)
		{
		case enCurrencyMenueOptions::cListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyMenueOptions::cFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyMenueOptions::cUpdateRate:
		{
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyMenueOptions::cCurrencyCalculater:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyMenueOptions::cMainMenue:
		{

		}
		}
	}

public:

	static void ShowCurrenciesMenue()
	{
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Main Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyMenueOption(enCurrencyMenueOptions(_ReadCurrencyMenueOption()));
	}
};



