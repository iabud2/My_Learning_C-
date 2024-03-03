#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

char Read_char()
{
    char ch;
    cout << "Enter Your String:\n";
    cin >> ch;
    return ch;
}

void Invert_char(char &ch)
{
    tolower(ch);
}

int main()
{
    char Mychar = Read_char();
    cout << "Your character is :\n";
    cout << Mychar << endl;
    cout << "Char After edit is:\n";
    Invert_char(Mychar);
    cout << Mychar << endl;

    return 0;
}