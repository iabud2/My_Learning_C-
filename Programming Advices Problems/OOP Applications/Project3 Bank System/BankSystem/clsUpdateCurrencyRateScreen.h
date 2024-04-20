#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputvalidate.h"
#include "clsCurrency.h"

class clsUpdateCurrencyRateScreen:protected clsScreen
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

    static float _ReadNewRate()
    {
        cout << "\nõEnter New Rate : ";
        float NewRate = clsInputValidate::ReadDblNumber();
        return NewRate;
    }

public:
    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("\t  Update Currency Screen");
        string Code;
        cout << "Please Enter Currency Code : ";
        Code = clsInputValidate::ReadString();
      
        
        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "\nCurrency Not Found, Choose Another One : \n";
            Code = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(Code);
        _PrintCurrency(Currency);
        cout << "Are you sure you want to update this currency rate? [y/n] : ";
        
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";
            Currency.UpdateRate(_ReadNewRate());
            cout << "\nCurrency After Update :\n";
            _PrintCurrency(Currency);
        }
    }
};

