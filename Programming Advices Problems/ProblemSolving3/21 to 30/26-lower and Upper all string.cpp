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

void Upper_String(string &Words)
{
    for (int i = 0; i < Words.length(); i++)
    {
        Words[i] = toupper(Words[i]);
    }
}

void Lower_String(string &Words)
{
    for (int i = 0; i < Words.length(); i++)
    {
        Words[i] = tolower(Words[i]);
    }
}

int main()
{
    string MyString = Read_String();
    cout << "Upper String :\n";
    Upper_String(MyString);
    cout << MyString << endl;
    cout << "Lower String :" << endl;
    Lower_String(MyString);
    cout << MyString << endl;
    return 0;
}