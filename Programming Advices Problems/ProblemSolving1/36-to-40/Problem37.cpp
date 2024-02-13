/*
Problem 37:
Write a program to read numbers from user and sum them, 
keep reading until the user enters -99.

then print the Sum on screen.
*/
#include <iostream>
#include <string>   
using namespace std;
float Read_Numbers(string message)
{
    int Number;
    cout << message << endl;
    cin >> Number;
    return Number;
}

float calculator()
{
    int sum = 0;
    int Number1 = 0;
    int Counter = 1;
    do 
    {
        Number1 = Read_Numbers("Please Enter Number " + to_string(Counter) + " :");
        if (Number1 == -99)
        {
            break;
        }
        sum += Number1;
        Counter++;

    }while(Number1 != -99);

    return sum; 
}



int main()
{
    cout <<calculator() << endl;
}