/*
Problem 48:
Write a program to read a LoanAmount 
and ask you how many months you need to settle the loan, 
then calculate the monthly installment amount
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

float calculat_Payment(float Months, float Loan)
{
    return (Loan / Months);
}

void Read_Payment(float Payment)
{
    cout << "You have to pay " << Payment << "$ per month to complete it in time";
}

int main()
{
    Read_Payment(calculat_Payment(Read_Positive_Number("How many months you need?:\n"),
                                            Read_Positive_Number("Enter The Loan:\n")));
    return 0;
}