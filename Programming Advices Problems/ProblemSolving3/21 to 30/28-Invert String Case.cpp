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

char Invert_char(char ch)
{
    return isupper(ch) ? tolower(ch) : toupper(ch);
}

void Invert_String(string &Words)
{
    for(int i =0 ; i < Words.length(); i++)
    {
        Words[i] = Invert_char(Words[i]);
    }
}

int main()
{
    string MyString = Read_String();
    cout << "Your String is :\n";
    cout << MyString << endl;
    cout << "String After edit is:\n";
    Invert_String(MyString);
    cout << MyString << endl;

    return 0;
}