#pragma warning(disable : 4996);
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

struct stDate
{
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

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

bool is_Last_Day(stDate Date)
{
    return (Date.Day == Days_In_Month(Date.Year, Date.Month));
}

bool is_Last_Month(stDate Date)
{
    return (Date.Month == 12);
}

stDate Increase_Date_By_One_day(stDate &Date)
{
    if (is_Last_Day(Date))
    {
        if (is_Last_Month(Date))
        {
            Date.Year++;
            Date.Day = 1;
            Date.Month = 1;
        }
        else
        {
            Date.Month++;
            Date.Day = 1;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

bool is_Date1_Before_Date2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false) : false);
}

stDate Read_Date(stDate &Date)
{
    Date.Day = Read_Number("Enter The Day : ");
    Date.Month = Read_Number("Enter The Month : ");
    Date.Year = Read_Number("Enter The Year : ");
    return Date;
}

void Swap_Dates(stDate &Date1, stDate &Date2)
{
    stDate TempDate;
    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;
    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;
    Date2.Year = TempDate.Year;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;
}
int Diff_In_Days(stDate Date1, stDate Date2, bool includ_Current_Day = false)
{
    int Days = 0;
    short Swap_Flag = 1;
    if (!is_Date1_Before_Date2(Date1, Date2))
    {
        Swap_Dates(Date1, Date2);
        Swap_Flag = -1;
    }
    while (is_Date1_Before_Date2(Date1, Date2))
    {
        Days++;
        Date1 = Increase_Date_By_One_day(Date1);
    }
    return (includ_Current_Day) ? ++Days * Swap_Flag : Days * Swap_Flag;
}

int main()
{
    stDate Date1, Date2;
    cout << "\nDate1 : \n";
    Read_Date(Date1);
    cout << "\nDate2 : \n";
    Read_Date(Date2);
    printf("Diffrent in days is :  [%d] Day(s) ", Diff_In_Days(Date1, Date2));
    return 0;
}