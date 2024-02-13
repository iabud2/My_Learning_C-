/*
Problem 12.

Write a program to ask the user to enter:
• Number1 , Number2

Then Print the Max Number
*/


#include <iostream>
using namespace std;

void Read_Numbers(int &num1, int &num2)
{
    cout << "Enter The First Number:\n";
    cin >> num1;
    cout << "Enter The Second Number:\n";
    cin >> num2;
}

int Max_Number(int num1, int num2)
{
    if (num1 > num2)
    return num1;
    else
        return num2;
}

void Read_Max_Number( int num2)
{   
    cout << "The Maximum Number is : " << num2 ;
}

int main(){
    int x, y;
    Read_Numbers(x, y);
    Read_Max_Number(Max_Number(x, y));
    return 0;
}