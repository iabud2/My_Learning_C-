#include<iostream>
#include<string>
using namespace std;

//##Teacher solution:

/*
int Read_Number()
{
    int number = 0;
    cout << "Please Enter Positive Number:\n";
    cin >> number;
    return number;
} 



void get_Last_Number(int number)
{
    int Remainder = 0;
    while(number > 0)
    {
        Remainder = number % 10;
        number = number / 10;
        cout << Remainder << endl;
    }
}

int main()
{
    get_Last_Number(Read_Number());
    return 0;
}*/

//##My Solution:

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

void Print_Numbers(string Numbers) 
{
    for (int i = (check_String_Length(Numbers)); i >= 0; i--)
    {
        cout << Numbers[i] << endl;
    }
}

int main()
{
    Print_Numbers(Read_Number());
    return 0;
}