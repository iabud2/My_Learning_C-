/*
Problem47:
Write a program to read a LoanAmount and Monthly Payment and calculate how many months you need to
settle the loan
*/
#include <iostream>
using namespace std;

float Read_Positive_Number(string message)
{
    float Number;
    cout << message;
    cin >> Number;
    return Number;
}

float calculat_month_needed(float Payment, float Loan)
{
    return (Loan / Payment);
}

void Read_Monthly_Needed(float months)
{
    cout << "You Need " << months << " Months To finish the loann";
}

int main()
{
    Read_Monthly_Needed(calculat_month_needed(Read_Positive_Number("Enter The Mothly Payment:\n"),
                                            Read_Positive_Number("Enter The Loan:\n")));
    return 0;
}

