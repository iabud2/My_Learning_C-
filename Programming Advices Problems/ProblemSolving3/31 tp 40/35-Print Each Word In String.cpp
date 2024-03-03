#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string Read_String()
{
    string message = " ";
    cout << "Enter Your String:\n";
    getline(cin, message);
    return message;
}

/*
-My Solution
void Print_Each_Word(string Words)
{
    bool Check_First_Letter = true;
    for (int i = 0; i < Words.length(); i++)
    {
        cout << Words[i];
        if (Words[i] == ' ')
        {
            cout << endl;
        }
    }
}
*/

void Print_Each_Word2(string ST1)
{
    string delimter = " ";
    short pos = 0;
    string each_Word;
    while ((pos = ST1.find(delimter)) != std::string::npos)
    {
        each_Word = ST1.substr(0, pos);
        if (each_Word != "")
        {
            cout << each_Word << endl;
        }
        ST1.erase(0, pos + delimter.length());
    }
    if (ST1 != "")
    {
        cout << ST1 << endl;
    }
}

int main()
{
    string st1 = Read_String();
    Print_Each_Word2(st1);
    return 0;
}