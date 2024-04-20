#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "Global.h"
using namespace std;

class clsTransferScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
	}

    static string ReadAccountNumber(string Message)
    {
        string AccountNumber;
        cout << Message;
        AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }

    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount : ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount : ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t  Transfer Screen");
        string username = CurrentUser.UserName;
        string message1 = "\nEnter Account Number you Want To transfer from :";
        clsBankClient SourceClient = clsBankClient::Find(ReadAccountNumber(message1));
        _PrintClient(SourceClient);
        string message2 = "\nEnter Account Number you Want To transfer to :";
        clsBankClient DestinationClient = clsBankClient::Find(ReadAccountNumber(message2));
        _PrintClient(DestinationClient);

        float Amount = _ReadAmount(SourceClient);
        char Answer = 'n';
        cout << "Are you sure you want to perform this operation ? [y/n] : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, username))
            {
                cout << "Transfer Done Successfully.\n";
            }
            else
            {
                cout << "Transfer Faild, Try Again later. \n";
            }
        }
        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
    }
};

