// Properties Set&Get
#include <iostream>
using namespace std;

class Person
{
private:
    string _FirstName;
    string _LastName;
    int _ID = 25;
public:
    // Get ID (Read Only Property bcs No Set Property for ID)
    int ID()
    {
        return _ID;
    }
    //  Property Set
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    // Property Get
    string GetFirstName()
    {
        return _FirstName;
    }
    // Property Set
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }
    // Property Get
    string GetLastName()
    {
        return _LastName;
    }
    // Property Get
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }
};

int main()
{
    Person Person1;
    Person1.SetFirstName("Mohammed");
    Person1.SetLastName("Abdullah");
    cout << "ID : " << Person1.ID() << endl;
    cout << "Full Name :" << Person1.FullName();
    return 0;
}