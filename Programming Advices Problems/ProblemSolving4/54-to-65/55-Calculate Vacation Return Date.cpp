#include <iostream>
#include <iomanip>
#include <cctype>
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

bool Is_Weekend(stDate Date)
{
    return (Find_Day_Order_In_Week(Date) == 5) ? true : (Find_Day_Order_In_Week(Date) == 6) ? true
                                                                                            : false;
}

bool Is_Business_Day(stDate Date)
{
    return (Is_Weekend(Date)) ? false : true;
}

stDate Read_Date(stDate &Date)
{
    Date.Day = Read_Day();
    Date.Month = Read_Month();
    Date.Year = Read_Year();
    return Date;
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

short Vacation_Days(stDate from, stDate to)
{
    short Days = 0;
    while (is_Date1_Before_Date2(from, to))
    {
        if (Is_Business_Day(from))
            Days++;
        from = Increase_Date_By_One_day(from);
    }
    return Days;
}

stDate Days_to_vacation(stDate from, int Vacation_Days)
{
    for (int i = 1; i <= Vacation_Days; i++)
    {
        if (Is_Business_Day(from))
            from = Increase_Date_By_One_day(from);
    }
    return from;
}

int Read_Vacation_Days()
{
    int Number = 0;
    do
    {
        cout << "\nEnter Vacation Days : ";
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
int main()
{
    cout << "\nVacation Starts: ";
    stDate from = Read_Date(from);
    int Vacation_Days = Read_Vacation_Days();
    from = Days_to_vacation(from, Vacation_Days);
    printf("\nReturned Date is : %d/%d/%d", from.Day, from.Month, from.Year);
    return 0;
}