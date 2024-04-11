// Properties Set&Get
#include <iostream>
using namespace std;

class Person
{
private:
    string _FirstName;
    string _LastName;

public:
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
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
};

int main()
{
    Person Person1;
    Person1.SetFirstName("Mohammed");
    cout << Person1.GetFirstName() << endl;
    // or
    Person1.FirstName = "Mohammed";
    cout << Person1.FirstName;
    return 0;
}