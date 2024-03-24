#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

int Read_Number(string message)
{
    int Number = 0;
    do
    {
        cout << message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

bool is_Leap(int Year)
{
    // this
    //  return((Year % 400 == 0)?true:(Year % 100 == 0)?false:(Year % 4 == 0)?true:false);
    // or this
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short Days_In_Month(int Year, int Month)
{

    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Months of 31 Days (1, 3 , 5, 7, 8, 10, 12)
    if (Month > 12 || Month <= 0)
    {
        return 0;
    }
    return ((Month == 2) ? (is_Leap(Year) ? 29 : 28) : arr[Month - 1]);
}

short Find_day(short Day, short month, short year)
{
    short A = (14 - month) / 12;
    short y = year - A;
    short m = month - (12 * A) - 2;
    short d = ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))) % 7;
    return d;
}

string MonthsName(short Month)
{
    string Days_Array[] = {"Jun", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return Days_Array[Month - 1];
}

string Day_Name(short Day)
{
    string Days_Array[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return Days_Array[Day];
}

void Print_Calender(short Month, short Year)
{
    short Day = Find_day(1, Month, Year);
    short Number_Of_days = Days_In_Month(Year, Month);
    // calender Head
    cout << "\n  _______________" << MonthsName(Month) << "_______________\n\n";
    for (int D = 0; D < 7; D++)
    {
        cout << setw(5) << left << Day_Name(D);
    }
    cout << endl;
    // calender Body
    int i;
    for (i = 0; i < Day; i++)
    {
        cout << "     ";
    }
    for (int j = 1; j <= Number_Of_days; j++)
    {
        cout << setw(5) << left << j;
        if (++i == 7)
        {
            i = 0;
            cout << endl;
        }
    }
    cout << "\n_________________________________\n";
}

int main()
{
    Print_Calender(2, 2000);
    return 0;
}