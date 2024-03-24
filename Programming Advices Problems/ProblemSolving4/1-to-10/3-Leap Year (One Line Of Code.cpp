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
    //this
    // return((Year % 400 == 0)?true:(Year % 100 == 0)?false:(Year % 4 == 0)?true:false);
    //or this
    return ((Year % 4 == 0 & Year % 100 !=0) || (Year % 400 == 0));
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