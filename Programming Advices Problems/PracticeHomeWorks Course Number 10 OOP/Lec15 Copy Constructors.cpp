#include <iostream>
using namespace std;

class clsAddress
{

private:
    string _Address_Street1;
    string _Address_Street2;
    string _PO_Box;
    string _Zip_Code;

public:
    clsAddress(string Address_Street1, string Address_Street2, string POBox, string ZipCode)
    {
        _Address_Street1 = Address_Street1;
        _Address_Street2 = Address_Street2;
        _PO_Box = POBox;
        _Zip_Code = ZipCode;
    }

    // copy Constructor
    clsAddress(clsAddress &old_Adderess)
    {
        _Address_Street1 = old_Adderess.AddressLine1();
        _Address_Street2 = old_Adderess.AddressLine2();
        _PO_Box = old_Adderess.POBox();
        _Zip_Code = old_Adderess.ZipCode();
    }

    void SetAddressLine1(string AddressLine1)
    {
        _Address_Street1 = AddressLine1;
    }
    string AddressLine1()
    {
        return _Address_Street1;
    }
    void SetAddressLine2(string AddressLine2)
    {
        _Address_Street2 = AddressLine2;
    }
    string AddressLine2()
    {
        return _Address_Street2;
    }
    void SetPOBox(string POBox)
    {
        _PO_Box = POBox;
    }
    string POBox()
    {
        return _PO_Box;
    }
    void SetZipCode(string ZipCode)
    {
        _Zip_Code = ZipCode;
    }
    string ZipCode()
    {
        return _Zip_Code;
    }
    void Print()
    {
        cout << "\nAddress Details:\n";
        cout << "------------------------";
        cout << "\nAddressLine1: " << _Address_Street1 << endl;
        cout << "AddressLine2: " << _Address_Street2 << endl;
        cout << "POBox       : " << _PO_Box << endl;
        cout << "ZipCode     : " << _Zip_Code << endl;
    }
};

int main()
{
    clsAddress Address1("Stree1", "Street2", "20020", "1211");
    Address1.Print();
    // copy Address
    clsAddress Address2 = Address1;
    Address2.Print();
    // or
    clsAddress Address3(Address2);
    Address3.Print();
    system("pause>0");
    return 0;
}