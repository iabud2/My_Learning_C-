#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"

using namespace std;

class clsLoginRegisterScreen:protected clsScreen
{
    static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Username;
        cout << "| " << setw(20) << left << LoginRegisterRecord.password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.permissions;
    }

public:
    static void ShowLoginRegisterScreen()
    {
        system("cls");
        if (!_CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }
        vector <clsUser::stLoginRegisterRecord> vLoginRecords = clsUser::GetLoginRegisterList();
        string title = "\tLogin Register Screen";
        string subtitle = "\t\t(" + to_string(vLoginRecords.size()) + ") Record(s)";
        _DrawScreenHeader(title, subtitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        
        if (vLoginRecords.size() == 0)
        {
            cout << "\t\t\t\tNo Login Records In The System\m";
        }
        else
        {
            for (clsUser::stLoginRegisterRecord& R : vLoginRecords)
            {
                PrintLoginRegisterRecordLine(R);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

