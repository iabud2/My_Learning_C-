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

short Count_Vowel(string S1)
{
    short counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (Is_Vowel(S1[i]))
            counter++;
    }
    return counter;
}

int main()
{
    string st1 = Read_String();
    cout << "Number of Vowel Characters in stirng is : " << Count_Vowel(st1);

    return 0;
}