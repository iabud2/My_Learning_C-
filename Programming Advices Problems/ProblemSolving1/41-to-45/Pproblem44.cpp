/*
Problem 44:
Write a program to ask the user to enter: 
• Day
Then print the day as follows: 
• 1 Print Sunday
• 2 Print Monday
• 3 Print Tuesday
• 4 Print Wednesday
• 5 Print Thursday
• 6 Print Friday
• 7 Print Saturday
• Otherwise print “Wrong Day” and ask the use to enter the day again.
*/
#include <iostream>
using namespace std;

enum enDays {
    Sunday = 1,
    Monday = 2,
    Tuesday = 3,
    Wednesday = 4,
    Thursday = 5,
    Friday = 6,
    Saturday = 7
};
int Read_Day_Of_Week(string message)
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
    } while (number <= 1 || number >= 7);
    return number;
}

enDays Day_Of_Week(int num)
{
    return (enDays)num;
}

string Get_Day(enDays Day)
{
    switch (Day)
    {
    case enDays::Saturday:
        return "Saturday";
    case enDays::Sunday:
        return "Sunday";
    case enDays::Monday:
        return "Monday";
    case enDays::Tuesday:
        return "Tuesday";
    case enDays::Wednesday:
        return "Wednesday";
    case enDays::Thursday:
        return "Thursday";
    case enDays::Friday:
        return "Firday";
    default:
        return "Not A day";
    }
}
void Print_Day_Of_Week(string Day)
{
    cout << "Its "<< Day;
}

int main()
{
    Print_Day_Of_Week(Get_Day(Day_Of_Week(Read_Day_Of_Week("Enter The Number Of The day:\n"))));
    return 0;
}