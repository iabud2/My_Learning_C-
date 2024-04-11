// Properties Set&Get
#include <iostream>
using namespace std;

class Person
{
private:
    string _FirstName;
    string _LastName;

public:
    // Property Set
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    // Property Set
    void SetLastName(string LastName)
    {
        _LastName = LastName;
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
    cout << Person1.FullName();
    return 0;
}