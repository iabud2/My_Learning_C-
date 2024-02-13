
#include <iostream>
using namespace std;

//my sol
/*
string Read_Number()
{
    string Number = "";
    cout << "enter The Number:\n";
    cin >> Number;
    return Number;
}

int check_String_Length(string Number)
{
    return Number.length();
}

int numbers(string Numbers)
{
    int sum = 0;
    for (int i = (check_String_Length(Numbers)); i >= 0; i--)
    {
        sum += i;
    }
 
    return sum;
}

void Print_Numbers(int Sum)
{
    cout << Sum;
}

int main()
{
    Print_Numbers(numbers(Read_Number()));

    return 0;
}*/

// Teacher sol

int  Read_Number()
{
    int Number = 0;
    cout << "enter The Number:\n";
    cin >> Number;
    return Number;
}

void loop_Numbers(int N)
{   
    int Remainder = 0;
    int sum = 0;
    while(N > 0)
    {
        Remainder = N % 10;
        N /= 10;
        sum += Remainder;
    }
    cout << sum;
}

int main()
{
    loop_Numbers(Read_Number());
    return 0;
}

