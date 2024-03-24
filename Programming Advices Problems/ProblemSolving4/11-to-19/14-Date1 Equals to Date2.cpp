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

stDate Read_Date(stDate &Date)
{
    Date.Day = Read_Number("Enter The Day : ");
    Date.Month = Read_Number("Enter The Month : ");
    Date.Year = Read_Number("Enter The Year : ");
    return Date;
}

bool is_equal(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
}

int main()
{
    stDate Date1;
    stDate Date2;
    cout << "Date Number one: \n";
    Read_Date(Date1);
    cout << "\nDate Number Two: \n";
    Read_Date(Date2);
    if (is_equal(Date1, Date2))
        cout << "\nYes, Date1 is Equal to Date2.";
    else
        cout << "\nNo, Date1 is NOT Equal to Date2.";
    return 0;
}