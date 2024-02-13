/*
Problem 31:
Write a Program to Ask The User to Enter:
• Number.

Then Print the Number^2 , Number^3 , Number^4
*/

#include <iostream>
#include <cmath>
using namespace std;

int Read_Number()
{
    int Number;
    cout << "Enter a Number:\n";
    cin >> Number;
    return Number;
}

void Calculata_Power(int N)
{
    cout << N<<"^"<< "2 = " << pow(N, 2)<<endl;
    cout << N<<"^"<< "3 = " << pow(N, 3)<<endl;
    cout << N<<"^"<< "4 = " << pow(N, 4)<<endl;
}

int main()
{
    Calculata_Power(Read_Number());
    return 0;
}

