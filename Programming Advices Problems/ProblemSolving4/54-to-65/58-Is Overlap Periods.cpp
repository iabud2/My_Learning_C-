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

Periods Read_Periods(Periods &Period)
{
    cout << "Enter Start Date:\n";
    Period.Start_Date = Read_Date(Period.Start_Date);
    cout << "Enter End Date:\n";
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
    if (is_Date1_After_Date2(Date1, Date2))
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
        break;
    };
}

bool is_Over_Lap_Periods(Periods Period1, Periods Period2)
{
    if (Return_Date_Status(Period2.End_Date, Period1.Start_Date) == enDateStatus::Before || Return_Date_Status(Period2.Start_Date, Period1.End_Date) == enDateStatus::After)
        return false;
    else
        return true;
}

int main()
{
    Periods Period1, Period2;
    cout << "Enter Period 1:\n";
    Period1 = Read_Periods(Period1);
    cout << "\n\nEnter Period 2:\n";
    Period2 = Read_Periods(Period2);

    if (is_Over_Lap_Periods(Period1, Period2))
        cout << "\nYes, Periods Overlap";
    else
        cout << "\nNo, Periods Not Overlap";
    return 0;
}
