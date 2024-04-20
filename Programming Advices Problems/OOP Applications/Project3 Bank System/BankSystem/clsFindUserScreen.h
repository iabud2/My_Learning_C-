#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindUserScreen:clsScreen
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
        cout << "\nUserName    : " << User.UserName;
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
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");
        string username = _ReadUsername();
        while (!clsUser::IsUserExist(username))
        {
            cout << "\nUser Not Found.\n";
            username = _ReadUsername();
        }
        clsUser User = clsUser::Find(username);
        if (!User.IsEmpty())
        {
            cout << "User Found :\n";
        }
        else
        {
            cout << "User not found.\n";
        }
        _PrintUser(User);
    }
};

