#pragma warning(disable : 4996)
#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>
using namespace std;

short Read_Year()
{
    int Year = 0;
    do
    {
        cout << "Please Enter a Year : ";
        cin >> Year;
    } while (Year <= 0);
    return Year;
}

short Read_Month()
{
    int Month = 0;
    do
    {
        cout << "Please Enter a Month : ";
        cin >> Month;
    } while (Month <= 0);
    return Month;
}

short Read_Day()
{
    int Day = 0;
    do
    {
        cout << "Please Enter a Day : ";
        cin >> Day;
    } while (Day <= 0);
    return Day;
}

struct stDate
{
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

bool is_Leap(int Year)
{
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

short Days_In_Year(int Year)
{
    return (is_Leap(Year)) ? 366 : 365;
}

short Days_From_Beginning(stDate Date)
{
    short sum = 0;
    for (int i = 1; i < Date.Month; i++)
    {
        sum += Days_In_Month(Date.Year, i);
    }
    sum += Date.Day;
    return sum;
}

string Day_Name(short Day)
{
    string Days_Array[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return Days_Array[Day];
}

short Find_Day_Order_In_Week(short Year, short Month, short Day)
{
    short A = (14 - Month) / 12;
    short Y = Year - A;
    short M = Month - (12 * A) - 2;
    short d = ((Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12))) % 7;
    return d;
}

short Find_Day_Order_In_Week(stDate Date)
{
    return Find_Day_Order_In_Week(Date.Year, Date.Month, Date.Day);
}

bool Is_End_Of_Week(stDate Date)
{
    return (Find_Day_Order_In_Week(Date) == 6) ? true : false;
}

bool Is_Weekend(stDate Date)
{
    return (Find_Day_Order_In_Week(Date) == 5) ? true : (Find_Day_Order_In_Week(Date) == 6) ? true
                                                                                            : false;
}

bool Is_Business_Day(stDate Date)
{
    return (Is_Weekend(Date)) ? false : true;
}

short Days_Until_The_End_Of_Week(stDate Date)
{
    return (6 - Find_Day_Order_In_Week(Date));
}

short Days_Until_The_End_Of_Month(stDate Date)
{
    return (Days_In_Month(Date.Year, Date.Month) - Date.Day);
}

short Days_Until_The_End_Of_Year(stDate Date)
{
    return (Days_In_Year(Date.Year) - Days_From_Beginning(Date));
}

stDate Read_Date(stDate &Date)
{
    Date.Day = Read_Day();
    Date.Month = Read_Month();
    Date.Year = Read_Year();
    return Date;
}

stDate Get_System_Date(stDate &Date)
{
    time_t Time = time(0);
    tm *Now = localtime(&Time);
    Date.Year = Now->tm_year + 1900;
    Date.Month = Now->tm_mon + 1;
    Date.Day = Now->tm_mday;
    return Date;
}

void Date_Functions(stDate Date)
{
    cout << "\nIs it End of Week?\n";
    if (Is_End_Of_Week(Date))
        cout << "Yes it is Saturday, it's of Week.";
    else
        cout << "No it's Not end of week.";

    cout << "\n\nIs it Weekend?\n";
    if (Is_Weekend(Date))
        cout << "Yes it is a week end.";
    else
        cout << "No today is " << Day_Name(Find_Day_Order_In_Week(Date)) << ", Not a weekend.";

    cout << "\n\nIs it Business Day?\n";
    if (Is_Business_Day(Date))
        cout << "Yes it is a business day.";
    else
        cout << "No it is NOT a business day.";

    cout << "\n\nDays until end of week : " << Days_Until_The_End_Of_Week(Date) << " Day(s).";

    cout << "\nDays until end of month : " << Days_Until_The_End_Of_Month(Date) << " Day(s).";

    cout << "\nDays until end of year : " << Days_Until_The_End_Of_Year(Date) << " Day(s).";
}

int main()
{
    stDate Date = Get_System_Date(Date);
    cout << "Today is " << Day_Name(Find_Day_Order_In_Week(Date));
    printf(" , %d/%d/%d\n\n", Date.Day, Date.Month, Date.Year);
    Date_Functions(Date);
    return 0;
}
