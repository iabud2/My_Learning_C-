#include <iostream>
#include <iomanip>
using namespace std;

short Read_Number(string message)
{
    short Number = 0;
    do
    {
        cout << message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

short Calculate_Year(short month, short year)
{
    short A = (14 - month) / 12;
    short y = year - A;
    return y;
}

short Calculate_month(short month)
{
    short A = (14 - month) / 12;
    short m = month - (12 * A) - 2;
    return m;
}


short Find_day_Order(short M, short Y, short Day)
{
    short d = ((Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12))) % 7;
    return d;
}

string Day_Name(short Day)
{
    string Days_Array[] = {"Sun",
                           "Mon",
                           "Tue",
                           "Wed",
                           "Thu",
                           "Fri",
                           "Sat"};
    return Days_Array[Day];
}

void Print_Day_Name()
{
    short Year = Read_Number("Please Enter Year : ");
    short Month = Read_Number("Please Enter Month : ");
    short Day = Read_Number("Please Enter Day : ");
    short Y = Calculate_Year(Month, Year);
    short M = Calculate_month(Month);
    short D = Find_day_Order(M, Y, Day);
    cout << "\nDate : " << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order : " << D << endl;
    cout << "Day Name : " << Day_Name(D);
}

int main()
{
    Print_Day_Name();
    return 0;
}