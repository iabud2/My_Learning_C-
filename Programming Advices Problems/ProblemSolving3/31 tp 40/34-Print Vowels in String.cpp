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

char InvertLetterCase(char char1)
{
    return (isupper(char1) ? tolower(char1) : toupper(char1));
}

bool Is_Vowel(char Mychar)
{
    Mychar = tolower(Mychar);
    return ((Mychar == 'a' || Mychar == 'u' || Mychar == 'o' || Mychar == 'e' || Mychar == 'i'));
}

void Print_Vowel_Characters(string S1)
{
    cout << "Vowel Character in String is :\n";
    for (int i = 0; i < S1.length(); i++)
    {
        if (Is_Vowel(S1[i]))
        {
            cout << setw(3) << S1[i] << "  ";
        }
    }
}

int main()
{
    string st1 = Read_String();
    Print_Vowel_Characters(st1);

    return 0;
}