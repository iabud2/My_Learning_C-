/*
Problem 7:
Write a program to ask the user to enter: • Number
Then Print the “Half of the <Number> is <???>”
*/
#include <iostream>
#include <string>
using namespace std;

int read_Num()
{
    int Number;
    cout << "Enter A number:\n";
    cin >> Number;
    return Number;
}

float caculate_Half_Number(int Number)
{
    return (float)Number / 2;
}

void Print_Half_Number(int Number)
{
    cout << "Half of"<< to_string(Number) << " is = " << to_string(caculate_Half_Number(Number));
}

int main()
{
    Print_Half_Number(read_Num());
    return 0;
}