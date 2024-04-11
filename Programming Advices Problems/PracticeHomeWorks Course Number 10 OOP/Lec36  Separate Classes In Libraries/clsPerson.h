#pragma once
#include <iostream>
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

