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

bool is_Date1_Before_Date2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false) : false);
}

bool is_Date1_Equals_to_Date2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? true : (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false) : false);
}
bool is_Date1_After_Date2(stDate Date1, stDate Date2)
{
    return (!is_Date1_Before_Date2(Date1, Date2) && !is_Date1_Equals_to_Date2(Date1, Date2));
}

enDateStatus Return_Date_Status(stDate Date1, stDate Date2)
{
    if (is_Date1_Before_Date2(Date1, Date2))
    {
        return enDateStatus(-1);
    }
    else if (is_Date1_Equals_to_Date2(Date1, Date2))
    {
        return enDateStatus(0);
    }
    else
    {
        return enDateStatus(1);
    }
}

void Print_Date_Status(stDate Date1, stDate Date2)
{
    switch (Return_Date_Status(Date1, Date2))
    {
    case enDateStatus::After:
        cout << "\nCompare Result = " << enDateStatus::After;
        break;
    case enDateStatus::Equals:
        cout << "\nCompare Retult = " << enDateStatus::Equals;
        break;
    case enDateStatus::Before:
        cout << "\nCompare Result = " << enDateStatus::Before;
    };
}
int main()
{
    stDate Date1;
    stDate Date2;
    cout << "Date Number one: \n";
    Read_Date(Date1);
    cout << "\nDate Number Two: \n";
    Read_Date(Date2);
    Print_Date_Status(Date1, Date2);
    return 0;
}