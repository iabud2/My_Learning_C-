/*
Problem 36.
Write a program to ask the user to enter:
• Number1
• Number 2
• OperationType

--

Then perform the calculation according to the Operation Type as follows:
• “+” : add the two numbers.
• “-” : Subtract the two numbers.
• “*” : Multiply the two numbers.
• “/” : Divide the two numbers.

*/
#include <iostream>
using namespace std;

enum enOperations
{
    Add = 1,
    Subtract = 2,
    Multiply = 3,
    Divide = 4
};

void Read_Numbers(float &Number1, float &Number2)
{

    cout << "Enter First Number:\n";
    cin >> Number1;
    cout << "Enter Second Number:\n";
    cin >> Number2;
}

enOperations Operations()
{
    int Operation;
    do
    {
        cout << "Enter Oparation:([1] + , [2] - , [3] * , [4] /)\n";
        cin >> Operation;

    } while (Operation < 1 || Operation > 4);
    return (enOperations)Operation;
}

float calculation(char Operation, float Number1, float Number2)
{
    float result;
    if (Operation == enOperations::Add)
        result = Number1 + Number2;
    else if (Operation == enOperations::Subtract)
        result = Number1 - Number2;
    else if (Operation == enOperations::Multiply)
        result = Number1 *Number2;
    else if (Operation == enOperations::Divide)
    {    result = Number1 / Number2;
    }
    return (float)result;
}

void Read_Result(float Result)
{
    cout << Result;
}
int main()
{
    float X, Y;
    Read_Numbers(X, Y);
    Read_Result(calculation(Operations(), X, Y));
    return 0;
}
