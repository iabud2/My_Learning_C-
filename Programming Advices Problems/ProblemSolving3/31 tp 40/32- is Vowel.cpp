#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

char Read_char()
{
    char ch;
    cout << "Enter Your Char: \n";
    cin >> ch;
    return ch;
}

bool Is_Vowel(char Mychar)
{
    Mychar = tolower(Mychar);
    return ((Mychar == 'a' || Mychar == 'u' || Mychar == 'o' || Mychar == 'e' || Mychar == 'i'));
}

int main()
{
    char ch1 = Read_char();
    if (Is_Vowel(ch1))
        cout << "Yes, Your character '" << ch1 << "' is Vowel Character.";
    else
        cout << "No, Your Chracter '" << ch1 << "' Not a Vowel Character.";
    return 0;
}