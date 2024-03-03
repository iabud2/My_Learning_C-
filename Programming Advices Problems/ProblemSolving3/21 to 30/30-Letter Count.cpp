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

int count_Letter(string message, char ch1)
{
    short counter = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == ch1)
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    cout << "Enter Your String : ";
    string st1 = Read_String();
    cout << "Enter Character You need to count";
    char ch1 = Read_char();
    cout << "Your Character count is : ";
    count_Letter(st1, ch1);
    return 0;

}