#include <iostream>
using namespace std;

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

bool Validate_Date(stDate Date)
{
    if (Date.Day > Days_In_Month(Date.Year, Date.Month) || Date.Day <= 0)
        return false;
    if (Date.Month > 12 || Date.Month <= 0)
        return false;
    return true;
}

stDate Read_Date(stDate &Date)
{
    Date.Day = Read_Day();
    Date.Month = Read_Month();
    Date.Year = Read_Year();
    return Date;
}

int main()
{
    stDate Date = Read_Date(Date);

    if (Validate_Date(Date))
    {
        cout << "\n\nYes, Date is Valid";
    }
    else
    {
        cout << "\n\nNo, Date Not Valid";
    }
    return 0;
}
