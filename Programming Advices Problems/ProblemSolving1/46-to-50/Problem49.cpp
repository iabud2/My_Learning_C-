/*
Problem 49:
Write a program to read the ATM PIN code from the user,
then check if PIN Code = 1234, then show the balance to user,
otherwise print “Wong PIN” and ask the user to enter the PIN again.
*/

#include <iostream>
using namespace std;

string Read_Positive_Number()
{
    string Number;
    cout << "Enter The Pin Code :\n";
    cin >> Number;
    return Number;
}

bool check_Pin()
{
    string Password = "1234";
    string PinCode;
    do
    {
        PinCode = Read_Positive_Number();
        if (PinCode == Password)
        {
            return true;
        }
        else
        {
            cout << "\nWrong Password\n";
            system("color 4F");
        }
    } while (PinCode != "1234");
}

void Read_Result()
{
    if (check_Pin())
    {
        system("color 2F");
        cout << "Balance is 5000";
    }
}

int main()
{
    Read_Result();
    return 0;
}

