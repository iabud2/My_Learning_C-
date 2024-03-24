#include <iostream>
using namespace std;

enum enDateStatus
{
    Before = -1,
    Equals = 0,
    After = 1
};

struct stDate
{
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

struct Periods
{
    stDate Start_Date;
    stDate End_Date;
};

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

stDate Read_Date(stDate &Date)
{
    Date.Day = Read_Day();
    Date.Month = Read_Month();
    Date.Year = Read_Year();
    return Date;
}

Periods Read_Periods(Periods &Period)
{
    cout << "Enter Start Date:\n";
    Period.Start_Date = Read_Date(Period.Start_Date);
    cout << "\nEnter End Date:\n";
    Period.End_Date = Read_Date(Period.End_Date);
    return Period;
}

bool is_Date1_Before_Date2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false) : false);
}

bool is_Date1_Equals_to_Date2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool is_Date1_After_Date2(stDate Date1, stDate Date2)
{
    return (!is_Date1_Before_Date2(Date1, Date2) && !is_Date1_Equals_to_Date2(Date1, Date2));
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

enDateStatus Return_Date_Status(stDate Date1, stDate Date2)
{
    if (is_Date1_Before_Date2(Date1, Date2))
    {
        return enDateStatus(-1);
    }
    if (is_Date1_Equals_to_Date2(Date1, Date2))
    {
        return enDateStatus(0);
    }
    return enDateStatus(1);
}

int Diff_In_Days(stDate Date1, stDate Date2, bool includ_Current_Day = false)
{
    int Days = 0;
    while (is_Date1_Before_Date2(Date1, Date2))
    {
        Days++;
        Date1 = Increase_Date_By_One_day(Date1);
    }
    return (includ_Current_Day) ? ++Days : Days;
}

int Period_Length_In_Days(Periods Period, bool IncludeEndDate = false)
{
    return (Diff_In_Days(Period.Start_Date, Period.End_Date, IncludeEndDate));
}


int main()
{
    Periods Period1;
    cout << "Enter Period 1:\n";
    Period1 = Read_Periods(Period1);
    printf("Period Length is : %d\n", Period_Length_In_Days(Period1)) ;
    printf("Period Length (Including End Date) is : %d\n", Period_Length_In_Days(Period1, true)) ;
    return 0;
}
