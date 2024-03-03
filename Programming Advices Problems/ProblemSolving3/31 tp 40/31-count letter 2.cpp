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

char Read_char()
{
    char ch;
    cout << "Enter Your Char: \n";
    cin >> ch;
    return ch;
}


char InvertLetterCase(char char1)
{ 
    return (isupper(char1) ? tolower(char1) : toupper(char1)); 
}

short CountLetter(string S1, char Letter, bool MatchCase = true)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == Letter)
                Counter++;
        }
        else
        {
            if (tolower(S1[i]) == tolower(Letter))
                Counter++;
        }
    }
    return Counter;
}


int main()
{
    string st1 = Read_String();
    char ch1 = Read_char();
    short Same_Case = CountLetter(st1, ch1, 1);
    short Any_Case = CountLetter(st1, ch1, 0);
    cout << "Your Character \"" << st1 << "\"count is : " << Same_Case << endl;
    cout << "Your Character \"" << InvertLetterCase(ch1) << "\" or \"" 
    << ch1  << "\" count is : " << Any_Case << endl;
    return 0;
}