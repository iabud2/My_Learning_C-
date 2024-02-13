/*
Problem 39:
Write a program to read a TotalBill and CashPaid and calculate the 
remainder to be paid back.
*/
#include <iostream>
using namespace std;
float Read_Number(string message)
{
    float number = 0;
    do
    {
        cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}

float calculate_The_Remainder(float TotalBill, float TotalCashPaid)
{
    return TotalCashPaid - TotalBill;
}

void Print_Result(float remainder)
{
    cout << "The remainder is:\n" << remainder;
}

int main()
{
    Print_Result(calculate_The_Remainder(Read_Number("Enter The Total Bill:\n"), Read_Number("Enter The Total Cash:\n")));
    return 0;
}