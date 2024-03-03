#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

string Read_String()
{
    string message = " ";
    cout << "Enter Your String:\n";
    getline(cin, message);
    return message;
}

int Count_Capital_Letters(string MyString)
{
    short Counter = 0;
    for(int i = 0; i < MyString.length(); i++)
    {
        if (isupper(MyString[i]))
        {
            Counter++;
        }
    }
    return Counter;
}

int Count_Small_Letters(string MyString)
{
    short Counter = 0;
    for (int i = 0; i < MyString.length(); i++)
    {
        if (islower(MyString[i]))
        {
            Counter++;
        }
    }
    return Counter;
}

int main()
{
    string MyString = Read_String();
    cout << "Stirng Length is : " << MyString.length() << endl;
    cout << "Number Of Capital Letters : " << Count_Capital_Letters(MyString)<< endl;
    cout << "Number Of Small Letters : "<< Count_Small_Letters(MyString) << endl;
    return 0;
}