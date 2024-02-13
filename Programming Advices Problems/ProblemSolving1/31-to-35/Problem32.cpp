/*
Problem 32:
Write a program to ask the user to enter: 
• Number
• M

Then Print the Number^M
*/
#include <iostream>
#include <cmath>
using namespace std;

int Read_Number()
{
    int Number;
    do
    {
        cout << "Enter a Number:\n";
        cin >> Number;
    } while ( Number == 0);
    return Number;
}

int Read_Power()
{
    int Power;
    cout << "Enter The Power:\n";
    cin >> Power;
    return Power;
}

int Calculate_Power(int M, int N)
{
    if (M == 0){
        return 1;
    }
    else {
        return pow(N, M);
    }
}

void Read_Output(int Result)
{
    cout << Result ;
}

int main()
{
    Read_Output(Calculate_Power(Read_Power() , Read_Number()));
    return 0;
}