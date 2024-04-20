#pragma once
#include <iostream>
#include "Global.h"
#include "clsUser.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{

private :

protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		clsDate Date;
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t  " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n";
		cout << "\n\t\t\t\t\tUser :" << CurrentUser.UserName << endl;
		cout << "\n\t\t\t\t\tDate :" << clsDate::DateToString(Date) << "\n\n";
	}

	static bool _CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermissions(Permission))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}
	}
};

