#include <iostream>
#include <cctype>
using namespace std;

int Read_Number()
{
    int Number = 0;
    do
    {
        cout << "Enter The Year : ";
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

bool Leap_Year(int Year)
{
    if (Year % 4 == 0 && Year % 100 != 0)
    {
        return true;
    }
    else if (Year % 100 == 0 && Year % 400 == 0)
    {
        return true;
    }
    return false;
}

void Leap()
{
    char Again = 'Y';
    do
    {
        int Year = Read_Number();
        if (Leap_Year(Year))
        {
            cout << Year << " is a Leap Year";
        }
        else
        {
            cout << Year << "is Not a Leap Year";
        }
        cout << "\nWant to Check another Year? [y/n] ? ";
        cin >> Again;
    } while (toupper(Again) == 'Y');
}

int main()
{
    Leap();
    return 0;
}