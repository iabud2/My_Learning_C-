#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateUserScreen:protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
    }

    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access? [y/n] : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }
        cout << "\nDo you want to give access to : \n";
        cout << "\nShow Clients List ? [y/n] : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }
        cout << "\nAdd New Client ? [y/n] : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }
        cout << "\nDelete Client ? [y/n] : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }
        cout << "\nUpdate Client? [y/n] : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
        }
        cout << "\nFind Client? [y/n] : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }
        cout << "\nTransactions [y/n] : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }
        cout << "\nManage Users [y/n] : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }
        cout << "\nLogin Registers [y/n] : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLoginRegister;
        }
        return Permissions;
    }

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static string _ReadUsername()
    {

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        return UserName;
    }

public:
    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\t  Update User Screen");
        string username = _ReadUsername();
        while (!clsUser::IsUserExist(username))
        {
            cout << "\nAccount Not Found";
            username = _ReadUsername();
        }

        clsUser User = clsUser::Find(username);
        _PrintUser(User);
        cout << "\bAre you sure you want to update this user ?[y/n] :";
        char answer = 'n';
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            cout << "Update user Info :\n";
            cout << "-------------------\n";
            _ReadUserInfo(User);
            clsUser::enSaveResults SaveResult;
            SaveResult = User.Save();

            switch (SaveResult)
            {
            case clsUser::svFaildEmptyObject:
            {
                cout << "\nError, User Was Not Updated Because it's Empty";
                break;
            }
            case clsUser::svSucceeded:
            {
                cout << "\nUser Updated Successfully.\n";
                break;
            }
            }
        }
    }
};

