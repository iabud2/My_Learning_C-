/*
Problem:
Write a program to calculate the task duration in seconds and print it on screen
=> Given the time duration of a task in the number of days, hours, minutes, and seconds,.
*/
#include <iostream>
#include <cmath>
using namespace std;
struct stTime
{
    int Days, Hours, Minutes, Seconds;
};

stTime Read_Time()
{
    stTime Time;
    cout << "Enter The Number Of Days:\n";
    cin >> Time.Days;
    cout << "Enter The Number Of Hours:\n";
    cin >> Time.Hours;
    cout << "Enter The Number Of Minutes:\n";
    cin >> Time.Minutes;
    cout << "Enter The Number Of Seconds:\n";
    cin >> Time.Seconds;
    return Time;
}

int Task_Seconds(stTime Time)
{
    int Task_Days = Time.Days * 24 * 60 * 60;
    int Task_hours = Time.Hours * 60 * 60;
    int Task_Mins = Time.Minutes * 60;
    int Task_Seconds = Time.Seconds;

    int Total_Task_Duration = Task_Days + Task_hours + Task_Mins + Task_Seconds;
    return Total_Task_Duration;
}

void Read_Task_Duration(int Duration)
{

    cout << "Your Task Duration in Seconds = " << Duration << " Seconds";
}

int main()
{
    Read_Task_Duration(Task_Seconds(Read_Time()));
    return 0;
}
