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

void Convert_To_Upper_Case(string &Words)
{
    bool Check_First_Letter = true;
    for (int i = 0; i < Words.length(); i++)
    {
        if (Words[i] != ' ' && Check_First_Letter == true)
        {
            
            Words[i] =  toupper(Words[i]); 
        }
        Check_First_Letter = (Words[i] == ' ' ? true : false);
    }
}

int main()
{
    string MyString = Read_String();
    cout << "String Before Edit is : \n"<<MyString << endl;
    Convert_To_Upper_Case(MyString);
    cout << "String After Edit is:\n" << MyString << endl;
    return 0;
}