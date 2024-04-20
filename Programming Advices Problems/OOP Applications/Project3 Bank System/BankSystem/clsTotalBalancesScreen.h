#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
using namespace std;
class clsTotalBalancesScreen:protected clsScreen
{
private:
    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {

        cout << setw(25) << left << "" << "| " <<setw(15) <<Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
        cout << endl;
    }
public:
    static void ShowTotalBalances()
    {
        vector <clsBankClient> Clients = clsBankClient::GetClientsList();
        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(Clients.size()) + ") client(s)";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;


        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (Clients.size() == 0)
        {
            cout << "\t\t\t\tNo Clients Available In the System!";
        }
        else
        {
            for (clsBankClient& C : Clients)
            {
                _PrintClientRecordBalanceLine(C);
            }
        }
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::Number_To_Text(TotalBalances) << ")";
    }

};

