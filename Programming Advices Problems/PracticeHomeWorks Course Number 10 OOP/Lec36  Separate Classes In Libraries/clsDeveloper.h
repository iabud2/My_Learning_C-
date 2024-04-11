#pragma once
#include <iostream>
#include "clsEmployee.h"

using namespace std;
class clsDeveloper : public clsEmployee
{
private:
    string _MainProgrammingLanguage;

public:
    clsDeveloper(int id, string F_Name, string L_Name, string Email, string Phone_Number, string title, float salary, string Department, string MainProgLang)
        : clsEmployee(id, F_Name, L_Name, Email, Phone_Number, title, salary, Department)
    {
        _MainProgrammingLanguage = MainProgLang;
    }

    void SetMainProgrammingLanguage(string MainProgLang)
    {
        _MainProgrammingLanguage = MainProgLang;
    }

    string MainProgrammingLanguage()
    {
        return _MainProgrammingLanguage;
    }

    void Print()
    {
        cout << "Info" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "ID         : " << ID() << endl;
        cout << "First Name : " << FirstName() << endl;
        cout << "Last Name  : " << LastName() << endl;
        cout << "Email      : " << Email() << endl;
        cout << "Phone      : " << Phone() << endl;
        cout << "Title      : " << Title() << endl;
        cout << "Salary     : " << Salary() << endl;
        cout << "Department : " << Department() << endl;
        cout << "Main Programming Language : " << _MainProgrammingLanguage << endl;
        cout << "--------------------------------------------" << endl;
    }
};


