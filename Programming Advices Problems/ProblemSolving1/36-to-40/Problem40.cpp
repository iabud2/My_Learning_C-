/*
Problem 40:
A restaurant charges 10% services fee and 16% sales tax.
Write a program to read a BillValue and add service fee and sales tax to it,
and print the TotalBill on thescreen.
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

float Service_Tax(float Bill)
{
    return Bill + Bill * 1.1;
}

float Sales_Tax(float Bill)
{
    return Bill * 1.16;
}

void Bill(float Bill)
{
    cout << "Total Bill : " << Bill << endl;
    cout << "Total Bill With Services Tax : "<< Service_Tax(Bill) << endl;
    cout << "Total Bill with Sales Tax :" << Sales_Tax(Service_Tax(Bill)); 
}

int main()
{
    Bill(Read_Number("Enter The Bill :\n"));
    return 0;
}