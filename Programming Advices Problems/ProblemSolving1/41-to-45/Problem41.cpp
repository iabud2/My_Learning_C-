/*
Problem 41:
Write a program to read a NumberOfHours and calculates the number of weeks,
and days included in that number
*/
#include <iostream>
using namespace std;

float Read_Number_Of_Hours(string message)
{
    float number = 0;
    do
    {
        cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}

float Number_Of_weeks(float hours)
{
    return (hours / 24 / 7);
}

float Number_Of_Days(float hours)
{
    return (hours / 24);
}

void Print_result(float hours)
{
    cout << "Number Of Days Is : " << Number_Of_Days(hours)<< " Days" << endl;
    cout << "Number Of Weeks Is :" << Number_Of_weeks(hours) << " Weeksa"<<endl;
}

int main()
{
    Print_result(Read_Number_Of_Hours("Enter The Number Of Hours:\n"));
    return 0;
}