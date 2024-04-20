#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputvalidate.h"
using namespace std;

class clsDepositScreen:protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

public :
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber));
        {
            cout << "Client with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        char Answer = 'n';
        cout << "\nPlease Enter Deposit Amount : ";
        Amount = clsInputValidate::ReadDblNumber();

        while (Amount < 0)
        {
            cout << "\nPlease Enter Valid Deposit Amount : ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        
        cout << "\nAre you sure you want to perform this transaction?[y/n] : ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\bNew Balance: " << Client.AccountBalance;
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }
};

