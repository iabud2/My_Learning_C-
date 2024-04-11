#include <iostream>
#include <iomanip>
using namespace std;

class clsPerson
{
private:
    int _ID;
    string _FirstName;
    string _Lastname;
    string _Email;
    string _PhoneNumber;

public:
    clsPerson(int id, string F_Name, string L_Name, string Email, string Phone_Number)
    {
        _ID = id;
        _FirstName = F_Name;
        _Lastname = L_Name;
        _Email = Email;
        _PhoneNumber = Phone_Number;
    }

    void Set_FirsName(string F_Name)
    {
        _FirstName = F_Name;
    }
    void Set_LastName(string L_Name)
    {
        _Lastname = L_Name;
    }
    void Set_Email(string Email)
    {
        _Email = Email;
    }
    void Set_PhoneNumber(string PhoneNumber)
    {
        _PhoneNumber = PhoneNumber;
    }

    int ID()
    {
        return _ID;
    }
    string FirstName()
    {
        return _FirstName;
    }
    string LastName()
    {
        return _Lastname;
    }
    string Email()
    {
        return _Email;
    }
    string Phone()
    {
        return _PhoneNumber;
    }

    void Print()
    {
        cout << "Info" << endl;
        cout << "--------------------------------------" << endl;
        cout << "ID         : " << _ID << endl;
        cout << "First Name : " << _FirstName << endl;
        cout << "Last Name  : " << _Lastname << endl;
        cout << "Email      : " << _Email << endl;
        cout << "Phone      : " << _PhoneNumber << endl;
        cout << "--------------------------------------" << endl;
    }
    void SendEmail(string subject, string message)
    {
        cout << "The Following Message Sent Successfully to Email :" << _Email << endl;
        cout << "Subject : " << subject << endl;
        cout << "Body : " << message << "\n\n";
    }
    void SendSMS(string message)
    {
        cout << "The Following Message Sent Successfully to Phone Number : " << _PhoneNumber << endl;
        cout << message << endl;
    }
};

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

int main()
{
    clsDeveloper Person1(10, "Ahmed", "Mohammed", "me@gmail.com", "09864321", "Boss", 5550, "Stc", "C++");

    Person1.Print();
    Person1.SendEmail("Hi", "How Are You");
    Person1.SendSMS("How Are You");
    system("pause>0");
    return 0;
}