/*
Problem 38:
Write a program to read a number and check if it is a prime number or not.

Note: Prime number can only divide on one and on itself.
*/
#include <iostream>
#include <cmath>
using namespace std;
int Read_Number()
{   
    int number = 0;
    do {
        cout << "Please Enter Positive Number:\n";
        cin >> number;
    } while (number <= 0);
    return number;
}

enum enNumberType
{
    Prime = 1, NotPrime =2
};

enNumberType NumberType(int Number)
{
    int H = round(Number / 2);
    for (int i = 2; i <= H; i++)
    {
        if (Number % i == 0){
            return enNumberType::NotPrime;
        }
    }
    return enNumberType::Prime;
}

void Print_Number_Type(int Number)
{
    if (NumberType(Number) == enNumberType::Prime)
    {
        cout << "it's a Prime Numbers.\n";
    }
    else
    {
        cout << "it's Not a Prime Number.\n";
    }
}

int main()
{
    Print_Number_Type(Read_Number());
    return 0;
}
