#pragma once
#include <iostream>
#include "clsPerson.h"
using namespace std;
class clsEmployee : public clsPerson
{
private:
    string _Title;
    float _Salary;
    string _Department;
public:
    clsEmployee(int id, string F_Name, string L_Name, string Email, string Phone_Number, string title, float salary, string Department)
        :clsPerson(id, F_Name, L_Name, Email, Phone_Number)
    {
        _Title = title;
        _Salary = salary;
        _Department = Department;
    }
    void set_title(string title)
    {
        _Title = title;
    }

    void SetSalary(float salary)
    {
        _Salary = salary;
    }

    void Set_Department(string Department)
    {
        _Department = Department;
    }

    string Title()
    {
        return _Title;
    }

    float Salary()
    {
        return _Salary;
    }

    string Department()
    {
        return _Department;
    }

    void Print()
    {
        cout << "Info" << endl;
        cout << "--------------------------------------" << endl;
        cout << "ID         : " << ID() << endl;
        cout << "First Name : " << FirstName() << endl;
        cout << "Last Name  : " << LastName() << endl;
        cout << "Email      : " << Email() << endl;
        cout << "Phone      : " << Phone() << endl;
        cout << "Title      : " << _Title << endl;
        cout << "Salary     : " << _Salary << endl;
        cout << "Department : " << _Department << endl;
        cout << "--------------------------------------" << endl;
    }
};

