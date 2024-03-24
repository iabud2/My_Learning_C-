#pragma warning(disable : 4996);
#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>
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

bool is_First_Day(stDate Date)
{
    return (Date.Day == 1) ? true : false;
}

bool is_First_Month(stDate Date)
{
    return (Date.Month == 1) ? true : false;
}

stDate Increase_Date_By_One_day(stDate &Date)
{
    if (is_First_Day(Date))
    {
        if (is_First_Month(Date))
        {
            Date.Year--;
            Date.Month = 12;
            Date.Day = Days_In_Month(Date.Year, Date.Month);
        }
        else
        {
            Date.Month--;
            Date.Day = Days_In_Month(Date.Year, Date.Month);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}

stDate Decrease_Date_By_X_Day(stDate &Date, int X_Days)
{
    for (int i = 1; i <= X_Days; i++)
    {
        Date = Increase_Date_By_One_day(Date);
    }

    return Date;
}

stDate Decrease_Date_By_One_Weak(stDate &Date)
{
    Date = Decrease_Date_By_X_Day(Date, 7);
    return Date;
}

stDate Deacrease_Date_By_X_Weaks(stDate &Date, int X_Weaks)
{
    for (int i = 1; i <= X_Weaks; i++)
    {
        Date = Decrease_Date_By_One_Weak(Date);
    }
    return Date;
}

stDate Decrease_Date_By_One_Month(stDate &Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }
    short Number_of_Days_in_Month = Days_In_Month(Date.Year, Date.Month);
    if (Date.Day > Number_of_Days_in_Month)
    {
        Date.Day = Number_of_Days_in_Month;
    }
    return Date;
}

stDate Decrease_Date_By_X_Month(stDate &Date, int X_Months)
{
    for (int i = 1; i <= X_Months; i++)
    {
        Date = Decrease_Date_By_One_Month(Date);
    }
    return Date;
}

stDate Decrease_Date_By_One_Year(stDate &Date)
{
    Date.Year--;
    return Date;
}

stDate Deacrease_Date_By_X_Years(stDate &Date, int X_Years)
{
    for (int i = 1; i <= X_Years; i++)
    {
        Date = Decrease_Date_By_One_Year(Date);
    }
    return Date;
}

stDate Fast_Deacrese_Date_By_X_Years(stDate &Date, int X_Years)
{
    Date.Year -= X_Years;
    return Date;
}

stDate Decreace_Date_By_One_Decade(stDate &Date)
{
    Date.Year -= 10;
    return Date;
}

stDate Deacrese_Date_By_X_Decades(stDate &Date, int X_Decades)
{
    for (int i = 1; i <= X_Decades; i++)
    {
        Date = Decreace_Date_By_One_Decade(Date);
    }
    return Date;
}

stDate Fast_Decrease_Date_By_X_Decades(stDate &Date, int X_Decades)
{

    Date.Year -= X_Decades * 10;
    return Date;
}

stDate Decrease_Date_By_One_Century(stDate &Date)
{
    Date.Year -= 100;
    return Date;
}

stDate Decrease_Date_By_One_Millennium(stDate &Date)
{
    Date.Year -= 1000;
    return Date;
}

stDate Read_Date(stDate &Date)
{
    Date.Day = Read_Day();
    Date.Month = Read_Month();
    Date.Year = Read_Year();
    return Date;
}

void Date_After(stDate Date)
{
    cout << "\n\nDate Before : \n\n";
    short x_Days = 10;
    Date = Increase_Date_By_One_day(Date);
    printf("\n01-Before One day is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);
    Date = Decrease_Date_By_X_Day(Date, x_Days);
    printf("\n02-Before %d day(s) is : %d/%d/%d\n", x_Days, Date.Day, Date.Month, Date.Year);

    short x_Weaks = 10;
    Date = Decrease_Date_By_One_Weak(Date);
    printf("\n03-Before One Weak is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);
    Date = Deacrease_Date_By_X_Weaks(Date, x_Weaks);
    printf("\n04-Before %d Weak(s) is : %d/%d/%d\n", x_Weaks, Date.Day, Date.Month, Date.Year);

    short x_Months = 5;
    Date = Decrease_Date_By_One_Month(Date);
    printf("\n05-Before One Month is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);
    Date = Decrease_Date_By_X_Month(Date, x_Months);
    printf("\n06-Before %d Month(s) is : %d/%d/%d\n", x_Months, Date.Day, Date.Month, Date.Year);

    short x_Years = 10;
    Date = Decrease_Date_By_One_Year(Date);
    printf("\n07-Before One Year is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);
    Date = Deacrease_Date_By_X_Years(Date, x_Years);
    printf("\n08-Before %d Year(s) is : %d/%d/%d\n", x_Years, Date.Day, Date.Month, Date.Year);
    Date = Fast_Deacrese_Date_By_X_Years(Date, x_Years);
    printf("\n09-Before %d Year(s) is (Faster Method) : %d/%d/%d\n", x_Years, Date.Day, Date.Month, Date.Year);

    short x_Decades = 10;
    Date = Decreace_Date_By_One_Decade(Date);
    printf("\n010-Before One Decade is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);
    Date = Deacrese_Date_By_X_Decades(Date, x_Decades);
    printf("\n011-Before %d Decade(s) is : %d/%d/%d\n", x_Decades, Date.Day, Date.Month, Date.Year);
    Date = Fast_Decrease_Date_By_X_Decades(Date, x_Decades);
    printf("\n012-Before %d Decade(s) is (Fast Method) : %d/%d/%d\n", x_Decades, Date.Day, Date.Month, Date.Year);

    Date = Decrease_Date_By_One_Century(Date);
    printf("\n013-Before One Century is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = Decrease_Date_By_One_Millennium(Date);
    printf("\n014-Before One Millennium is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);
}

int main()
{
    stDate Date = Read_Date(Date);
    Date_After(Date);
    return 0;
}