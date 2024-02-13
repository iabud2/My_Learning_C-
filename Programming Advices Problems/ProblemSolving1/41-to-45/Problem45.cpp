/*
Problem 45:
Write a program to ask the user to enter: 
• Month
Then print the Month as follows: 
• 1 Print January
• 2 Print February
• 3 Print March
• 4 Print April 
• 5 Print May
• 6 Print June
• 7 Print July
• 8 Print August
• 9 Print September
• 10 Print October
• 11 Print November
• 12 Print December
• Otherwise print “Wrong Month” and ask the use to enter the Month again.
*/

#include <iostream>
using namespace std;

enum enMonth
{
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12,
};
int Read_Month(string message)
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
    } while (number <= 1 || number >= 12);
    return number;
}

enMonth Month(int num)
{
    return (enMonth)num;
}

string Get_Month(enMonth Month)
{
    switch (Month)
    {
    case enMonth::January:
        return "January";
    case enMonth::February:
        return "February";
    case enMonth::March:
        return "March";
    case enMonth::April:
        return "April";
    case enMonth::May:
        return "May";
    case enMonth::June:
        return "June";
    case enMonth::July:
        return "July";
    case enMonth::August:
        return "August";
    case enMonth::September:
        return "September";
    case enMonth::October:
        return "October";
    case enMonth::November:
        return "November";
    case enMonth::December:
        return "December";
    default:
        return "Not A Month";
    }
}
void Print_Month_Of_Week(string Month)
{
    cout << "Its " << Month;
}

int main()
{
    Print_Month_Of_Week(Get_Month(Month(Read_Month("Enter The Number Of The Month:\n"))));
    return 0;
}