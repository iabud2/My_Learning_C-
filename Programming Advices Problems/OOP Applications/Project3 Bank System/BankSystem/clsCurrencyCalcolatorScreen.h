#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputvalidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsCurrencyCalcolatorScreen:protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency, string Title = "CurrencyCard")
	{
        cout << "\n" << Title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";
	}

    static float _ReadAmount()
    {
        float amount;
        cout << "\nEnter amount to exchange :";
        amount = clsInputValidate::ReadFloatNumber();
        return amount;
    }

    static clsCurrency GetCurrency(string message)
    {
        string Code = "";
        cout << message << endl;
        Code = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "Currency Not Found, try another code : ";
            Code = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(Code);
        return Currency;
    }
  
    static void _PrintCalculationResults(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
    {
        _PrintCurrency(CurrencyFrom, "Convert From : ");
        float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
        cout << Amount << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << "USD\n";
        if (CurrencyTo.CurrencyCode() == "USD")
        {
            return;
        }
        cout << "\nConverting From USD to:\n";
        _PrintCurrency(CurrencyTo, "Convert To : ");
        float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
        cout << Amount << CurrencyFrom.CurrencyCode() << " = " <<  AmountInCurrencyTo << CurrencyTo.CurrencyCode();

    }
public:

    static void ShowCurrencyCalculatorScreen()
    {
        char Answer = 'y';
        while (Answer == 'y' || Answer == 'Y')
        {
            system("cls");
            _DrawScreenHeader("\tCalculate Currency Screen");
            clsCurrency CurrencyFrom = GetCurrency("Enter Currency1 Code : ");
            clsCurrency CurrencyTo = GetCurrency("Enter Currency2 Code : ");
            float Amount = _ReadAmount();

            _PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> Answer;

        }
    }

};

