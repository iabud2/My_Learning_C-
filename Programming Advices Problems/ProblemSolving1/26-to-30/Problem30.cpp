/*
Problem 30:
Write a program to calculate factorial of N!
Note: User should only enter positive number,
other wise reject it and ask to enter again
*/

#include <iostream>
using namespace std;

int Read_Positive_Number()
{
    int N;
    do {
        cout << "Enter a Positive Number:\n";
        cin >> N;
    } while (N < 0 );
    return N; 
}



int Calculate_Factorial(int N)
{
    int i = 1;
    int Factorial = 1;
        while (i <= N)
        {
           Factorial *= i;
            i++;
        }
    return Factorial;
}   

void Print_Factorial(int Factorial)
{
    cout <<"Factorial = "<< Factorial;
}
int main()
{
    Print_Factorial(Calculate_Factorial(Read_Positive_Number()));
    return 0;
}