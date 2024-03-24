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
    // this
    //  return((Year % 400 == 0)?true:(Year % 100 == 0)?false:(Year % 4 == 0)?true:false);
    // or this
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short Days_In_Month(int Year, int Month)
{

    int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // Months of 31 Days (1, 3 , 5, 7, 8, 10, 12)
    if (Month > 12 || Month <= 0)
    {
        return 0;
    }
    return ((Month == 2) ? (is_Leap(Year) ? 29 : 28) : arr[Month - 1]);
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short sum = 0;
    for (int i = 1; i < Month; i++)
    {
        sum += Days_In_Month(Year, i);
    }
    sum += Day;
    return sum;
}

stDate Read_Date(stDate &Date)
{
    Date.Day = Read_Number("Enter The Day : ");
    Date.Month = Read_Number("Enter The Month : ");
    Date.Year = Read_Number("Enter The Year : ");
    return Date;
}

stDate Date_After_Number_of_Days(stDate &Date, int Days)
{
    int Remaining_Days = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
    Date.Month = 1;
    short Month_Days = 0;
    while (true)
    {
        Month_Days = Days_In_Month(Date.Year, Date.Month);
        if (Remaining_Days > Month_Days)
        {
            Remaining_Days -= Month_Days;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = Remaining_Days;
            break;
        }
    }
    return Date;
}

int main()
{
    stDate Date;
    Read_Date(Date);
    int NumberOfDays = Read_Number("How Many Days You Want To add : ");
    Date_After_Number_of_Days(Date, NumberOfDays);
    printf("\nDate After Adding [%d] Days is : %d/%d/%d", NumberOfDays, Date.Day, Date.Month, Date.Year);
    
    return 0;
}