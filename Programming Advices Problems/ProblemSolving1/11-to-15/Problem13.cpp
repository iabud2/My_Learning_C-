/*
Problem 13:
Write a program to ask the user to enter 3 numbers: 
• A
• B
• C
Then Print Max number.*/

#include <iostream>
using namespace std;

void Read_3_Numbers(int &num1, int &num2, int &num3)
{
    cout << "Enter The First Number :\n";
    cin >> num1;
    cout << "Enter The Second Number :\n";
    cin >> num2;
    cout << "Enter The third Number :\n";
    cin >> num3;
}

int Max_Number(int A, int B, int C)
{
    if (A > B && A > C)
            return A;

    else if (B > A && B > C)
            return B;
    else
            return C;

}

void Print_Maximum_Number(int Max)
{
    cout << "The Maximum Number is :\n" << Max;
}

int main()
{
    int A, B, C;
    Read_3_Numbers(A, B, C);
    Print_Maximum_Number(Max_Number(A, B, C));
    return 0;
}