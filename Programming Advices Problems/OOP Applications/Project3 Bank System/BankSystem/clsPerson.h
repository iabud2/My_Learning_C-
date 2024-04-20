#pragma once
#include <iostream>
#include "InterfaceCommunication.h"
using namespace std;

class clsPerson : public InterfaceCommunication
{
private:
    string _FirstName;
    string _Last_Name;
    string _Email;
    string _Phone;

public:
    clsPerson(string F_Name, string L_Name, string Email, string Phone_Number)
    {
        _FirstName = F_Name;
        _Last_Name = L_Name;
        _Email = Email;
        _Phone = Phone_Number;
    }

    void Set_FirsName(string F_Name)
    {
        _FirstName = F_Name;
    }

    string Get_FirstName()
    {
        return _FirstName;
    }

    _declspec(property(get = Get_FirstName, put = Set_FirsName)) string FirstName;

    void Set_LastName(string L_Name)
    {
        _Last_Name = L_Name;
    }
    
    string Get_LastName()
    {
        return _Last_Name;
    }

    _declspec(property(get = Get_LastName, put = Set_LastName)) string LastName;
    
    void Set_Email(string Email)
    {
        _Email = Email;
    }

    string Get_Email()
    {
        return _Email;
    }

    _declspec(property(get = Get_Email, put = Set_Email)) string Email;
   
    void Set_Phone(string PhoneNumber)
    {
        _Phone = PhoneNumber;
    }

    string Get_Phone()
    {
        return _Phone;
    }

    _declspec(property(get = Get_Phone, put = Set_Phone)) string Phone;

    string FullName()
    {
        return _FirstName + " " + _Last_Name;
    }

    /*
    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _Last_Name;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";

    }
    */

    void SendEmail(string Title, string Body)
    {

    }

    void SendFax(string Title, string Body)
    {

    }

    void SendSMS(string Title, string Body)
    {

    }
};

