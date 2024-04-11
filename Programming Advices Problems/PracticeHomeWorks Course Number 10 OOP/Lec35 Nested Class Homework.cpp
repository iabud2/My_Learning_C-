#include <iostream>
using namespace std;

class clsPerson
{
    private:
        string _FullName;
        string _Address;
    class clsAddress
    {

    private:
        string _AddressLine1;
        string _AddressLine2;
        string _City;
        string _Country;

    public:
        // Set Properties:
        clsAddress(string AddressLine1, string AddressLine2, string City, string Country)
        {
            _AddressLine1 = AddressLine1;
            _AddressLine2 = AddressLine2;
            _City = City;
            _Country = Country;
        }

        void Set_AddressLine1(string AddressLine1)
        {
            _AddressLine1 = AddressLine1;
        }

        void Set_AddressLine2(string AddressLine2)
        {
            _AddressLine2 = AddressLine2;
        }

        void Set_City(string City)
        {
            _City = City;
        }

        void Set_Country(string Country)
        {
            _Country = Country;
        }
        // Get Properties:
        string AddressLine1()
        {
            return _AddressLine1;
        }

        string AddressLine2()
        {
            return _AddressLine2;
        }

        string City()
        {
            return _City;
        }

        string Country()
        {
            return _Country;
        }

        void Print()
        {
            cout << "\nAddress:\n";
            cout << _AddressLine1 << endl;
            cout << _AddressLine2 << endl;
            cout << _City << endl;
            cout << _Country << endl;
        }
    };

public:
    void SetFullName(string FullName)
    {
        _FullName = FullName;
    }

    string FullName()
    {
        return _FullName;
    }

    clsAddress Address = clsAddress("", "", "", "");
    clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country)
    {
        _FullName = FullName;
        Address = clsAddress(AddressLine1, AddressLine2, City, Country);
    }
    void Print()
    {
        cout << "Full Name : " << _FullName << endl;
        cout << "Address:\n";
        cout << Address.AddressLine1() << endl;
        cout << Address.AddressLine2() << endl;
        cout << Address.City() << endl;
        cout << Address.Country() << endl;
    }
};

int main()

{
    clsPerson Person("Mohammed Ahmed", "Buildng 10", "Queen Rania Street", "Amman", "Jordan");
    Person.Print();
    return 0;
}