// Write a program to ask the user to enter a number, then print “ODD” if its odd, Or “Even” if its even.
#include <iostream>
using namespace std;


enum enNumberType{ODD = 1, Even = 2};

int  read_Number()
{
    int Number;
    cout << "Enter Number To check Even Or Odd";
    cin >> Number;
    return Number;
}

enNumberType Check_Number_Type(int Number)
{
    int Num = Number % 2 ;
    if (Num ==0)
    {
        return enNumberType::Even;
    }
    else 
    {
        return enNumberType::ODD;
    }
}

void Print_Number_Type(enNumberType NumberType)
{

    if (NumberType == enNumberType::Even)
    {
        cout << "Number Is Even ";
    }    
    else 
    {
        cout << "Number Is Odd";
    }
}

int main()
{
    Print_Number_Type(Check_Number_Type(read_Number()));
    return 0;
}


