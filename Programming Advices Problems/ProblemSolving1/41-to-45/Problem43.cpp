/*
Problem:
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
#include <cmath>
using namespace std;
int Read_Number_Of_Seconds(string message)
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}

struct stTaskDuration{
    int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

stTaskDuration Seconds_To_Task_Duration(int Total_Seconds)
{
    const int Seconds_Per_day = 24 * 60 * 60;
    const int Seconds_Per_Hour = 60 * 60;
    const int Seconds_Per_Minute = 60;
    int remainder = 0;
    stTaskDuration Duration;
    Duration.NumberOfDays = floor(Total_Seconds / Seconds_Per_day);
    remainder = Total_Seconds % Seconds_Per_day;
    Duration.NumberOfHours = floor(remainder / Seconds_Per_Hour);
    remainder = remainder % Seconds_Per_Hour;
    Duration.NumberOfMinutes = floor(remainder / Seconds_Per_Minute);
    remainder = remainder % Seconds_Per_Minute;
    Duration.NumberOfSeconds = remainder;

    return Duration; 
}

void Read_Task_Duration(stTaskDuration Duration)
{
    cout << Duration.NumberOfDays <<':'<< Duration.NumberOfHours <<':'<< Duration.NumberOfMinutes
    <<':'<<Duration.NumberOfSeconds;
}

int main()
{
    Read_Task_Duration(Seconds_To_Task_Duration(Read_Number_Of_Seconds("Please Enter Task Duration In Seconds:\n")));
    return 0;
}