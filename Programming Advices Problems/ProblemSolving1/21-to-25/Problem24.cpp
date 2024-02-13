/*
Problem 24:
Write a program to ask the user to enter :
• Age

If age is between 18 and 45 print “Valid Age” otherwise print “Invalid Age”
*/

#include <iostream>
using namespace std;

int Read_Age()
{
    int Age;
    cout << "Enter Your Age :\n";
    cin >> Age;
    return Age;
}

bool Check_Age(int Age)
{
    return Age > 18 && Age < 45;
}

void PrintResult(int Age)
{
    if (Check_Age(Age))
    cout << "Valid Age";
    else 
    cout << "Invalid Age";
}

int main()
{
    PrintResult(Read_Age());
    return 0;
}