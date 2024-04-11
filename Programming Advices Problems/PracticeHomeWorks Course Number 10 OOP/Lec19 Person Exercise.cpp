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
    string _message;

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
    string Get_FirstName()
    {
        return _FirstName;
    }
    string Get_LastName()
    {
        return _Lastname;
    }
    string Get_Email()
    {
        return _Email;
    }
    string Get_PhoneNumber()
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
        _message = message;
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
    clsPerson Person1(10, "Ahmed", "Mohammed", "me@gmail.com", "09864321");
    Person1.Print();

    Person1.SendEmail("Hi", "How Are You");
    Person1.SendSMS("How Are You");
    system("pause>0");
    return 0;
}