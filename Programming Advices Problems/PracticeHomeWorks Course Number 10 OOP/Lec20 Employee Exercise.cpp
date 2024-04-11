#include <iostream>
#include <iomanip>
using namespace std;

class clsEmployee
{
private:
    int _ID;
    string _FirstName;
    string _Lastname;
    string _Title;
    string _Email;
    string _PhoneNumber;
    float _Salary;
    string _Department;

public:
    clsEmployee(int id, string F_Name, string L_Name, string title, string Email, string Phone_Number, float salay, string Department)
    {
        _ID = id;
        _FirstName = F_Name;
        _Lastname = L_Name;
        _Title = title;
        _Email = Email;
        _PhoneNumber = Phone_Number;
        _Salary = salay;
        _Department = Department;
    }

    void Set_FirsName(string F_Name)
    {
        _FirstName = F_Name;
    }
    
    void Set_LastName(string L_Name)
    {
        _Lastname = L_Name;
    }

    void set_title(string title)
    {
        _Title = title;
    }

    void Set_Email(string Email)
    {
        _Email = Email;
    }
    
    void Set_PhoneNumber(string PhoneNumber)
    {
        _PhoneNumber = PhoneNumber;
    }

    void SetSalary(float salary)
    {
        _Salary = salary;
    }

    void Set_Department(string Department)
    {
        _Department = Department;
    }

    //Get Methods:
    int ID()
    {
        return _ID;
    }
    
    string Get_FirstName()
    {
        return _FirstName;
    }
    
    string Get_LastName()
    {
        return _Lastname;
    }
    
    string Full_Name()
    {
        return _FirstName + " " + _Lastname;
    }

    string Title()
    {
        return _Title;
    }

    string Get_Email()
    {
        return _Email;
    }

    string Get_PhoneNumber()
    {
        return _PhoneNumber;
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
        cout << "ID         : " << _ID << endl;
        cout << "First Name : " << _FirstName << endl;
        cout << "Last Name  : " << _Lastname << endl;
        cout << "Email      : " << _Email << endl;
        cout << "Phone      : " << _PhoneNumber << endl;
        cout << "Title      : " << _Title << endl;
        cout << "Salary     : " << _Salary << endl;
        cout << "Department : " << _Department << endl;
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

int main()
{
    clsEmployee Employee1(10, "Ahmed", "Mohammed", "Boss", "me@gmail.com", "09864321", 5900, "STC");
    Employee1.Print();

    Employee1.SendEmail("Hi", "How Are You");
    Employee1.SendSMS("How Are You");
    system("pause>0");
    return 0;
}