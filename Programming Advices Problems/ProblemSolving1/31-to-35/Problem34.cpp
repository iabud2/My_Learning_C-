/*
Problem 34:
Write a program to ask the user to enter: 
• TotalSales

The commission is calculated as one percentage * the total sales amount,
all you need is to decide which percentage to use of the following: 

• > 1000,000  Percentage is 1%
• > 500K to 1M  Percentage is 2%
• > 100K – 500K  Percentage is 3%
• > 50K to 100K  Percentage is 5%
• Otherwise  Percentage is 0%
*/
#include <iostream>
using namespace std;

int Read_Sales_Amount()
{
    int Sales;
    cout << "Ener the Total Sales Amount:\n";  
    cin >> Sales;
    return Sales;
}

float commission(int Sales)
{
    if (Sales >= (1000000))
        return Sales * 0.01;
    else if (Sales >= 500000)
        return Sales * 0.02;
    else if (Sales >= 100000)
        return Sales * 0.03;
    else if(Sales >= 50000)
        return Sales * 0.05;
    else 
        return 0;
}

void Print_Commission(float commission)
{
    cout << "Your commission is : "<< commission;
}

int main()
{
    Print_Commission(commission(Read_Sales_Amount()));
    return 0;
}