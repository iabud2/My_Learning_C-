#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
using namespace std;
class clsDeleteUserScreen:protected clsScreen
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

    static string _ReadUsername()
    {

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        return UserName;
    }
public:
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\t  Delete User Screen");
        string Username = _ReadUsername();
        while (!clsUser::IsUserExist(Username))
        {
            cout << "User Not Found.";
            Username = _ReadUsername();
        }
        clsUser User = clsUser::Find(Username);
        _PrintUser(User);

        cout << "Are you sure you want to delete this user ? [y/n] :";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully.\n";
            }
            else
            {
                cout << "\nError, user was not deleted.\n ";
            }
        }
        
    }
};

