#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
string Trim_Left(string MyString)
{
    for (int i = 0; i < MyString.length(); i++)
    {
        if (MyString[i] != ' ')
        {
            return (MyString.substr(i, MyString.length() - i));
        }
    }

    return "";
}

string Trim_Right(string MyString)
{
    for (short i = MyString.length() - 1; i >= 0; i--)
    {
        if (MyString[i] != ' ')
        {
            return MyString.substr(0, i + 1);
        }
    }

    return "";
}

string Trim(string MyString)
{
    Trim_Left(MyString);
    Trim_Right(MyString);
    return MyString;
}

int main()
{
    string st1 = "mohamed abu-hadhoud mohammed";
    cout << " Trim Left = " << Trim_Left(st1) << endl;
    cout << " Trim Right = " << Trim_Right(st1) << endl;
    cout << " Trim = " << Trim(st1) << endl;

    return 0;
}