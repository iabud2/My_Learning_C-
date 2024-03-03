#include <iostream>
#include <vector>
using namespace std;

struct stEmployees
{
    string FirstName;
    string SecondName;
    float Salary;
};

void FillVectorEmployees(vector<stEmployees> &Employees)
{
    stEmployees Employee;
    char MoreEmployee = 'Y';
    do
    {
        cout << "Enter First Name : ";
        cin >> Employee.FirstName;
        cout << "Enter Second Name : ";
        cin >> Employee.SecondName;
        cout << "Enter Your Salary : ";
        cin >> Employee.Salary;
        Employees.push_back(Employee);
        cout << "Do You Have More Employees? ";
        cin >> MoreEmployee;
    } while (MoreEmployee == 'Y' || MoreEmployee == 'y');
}

void PrintEmployees(vector<stEmployees> &Employees)
{
    int i = 1;
    for (stEmployees &Employee : Employees)
    {
        cout << "\n------------------------\n";
        cout << "Employee Number [" << i << "]\n"; 
        cout << "First Name :" << Employee.FirstName << endl;
        cout << "Second Name :" << Employee.SecondName << endl;
        cout << "Salary : " << Employee.Salary << endl; 
        i ++;
        cout << "\n------------------------\n";
    }
    cout << "\nyou Have [" << i << "]Employees\n";
}

int main()
{
    vector <stEmployees> Employees;
    FillVectorEmployees(Employees);
    PrintEmployees(Employees);
    return 0;
}