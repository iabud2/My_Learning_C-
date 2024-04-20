#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen:protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";
    }

    static void _ShowResult(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Not Found.\n";
        }      
    }
public:

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find Currency Screen");
        short Choice = 0;
        cout << "Find By : [1]Code or [2] Country ? ";
        Choice = clsInputValidate::ReadShortNumberBetween(1, 2);
   
        if (Choice == 1)
        {
            string Code;
            cout << "\nPlease Enter Currency Code : ";
            Code = clsInputValidate::ReadString();
            clsCurrency Currency1 = clsCurrency::FindByCode(Code);
            _ShowResult(Currency1);
        }
        else
        {
            string Country;
            cout << "\nPlease Enter Country Name : ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency2 = clsCurrency::FindByCountry(Country);
            _ShowResult(Currency2);
        }
    }
};

