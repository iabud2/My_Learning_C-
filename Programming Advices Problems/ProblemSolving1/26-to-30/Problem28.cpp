/*
Problem 28:
Write a Program to Sum odd numbers from 1 to N.
*/

#include <iostream>
using namespace std;

enum enNumberType {ODD = 1 , EVEN=2};

int Read_number()
{
    int N;
    cout << "Enter a Number:\n";
    cin >> N;
    return N;
}

enNumberType Check_Number(int N)
{
    if (N % 2 == 0)
    {
        return enNumberType::EVEN;
    }
    else
    {
        return enNumberType::ODD;
    }
}

int summ_odd_numbers(int Number){

    int sum = 0;
    for (int i = 0; i <= Number; i++)
    {
        if (Check_Number(i)== enNumberType::ODD)
            sum += i;
    }
    return sum;
}

void Print_sum_odd(int sum)
{
    cout << summ_odd_numbers(sum);
}

int main()
{
    Print_sum_odd(Read_number());
    return 0;
}