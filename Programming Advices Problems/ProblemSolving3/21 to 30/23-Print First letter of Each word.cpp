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

void Convert_To_Upper_Case(string Words)
{
    bool Check_First_Letter = true;
    for (int i = 0; i < Words.length(); i++)
    {
        if (Words[i] != ' ' && Check_First_Letter == true)
        {
            cout << Words[i] << endl;
        }
        Check_First_Letter = (Words[i] == ' ' ? true : false);
    }
}

int main()
{
    Convert_To_Upper_Case(Read_String());
    return 0;
}