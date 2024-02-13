/*
Problem 14:
Write a program to ask the user to enter: 
• Number1
• Number2
Then print the two numbers , then Swap the two numbers and print them
*/
#include <iostream>
#include <string>
using namespace std;


void Read_2_Numbers(int &Num1, int &Num2)
{
        cout <<"Enter Number 1 :\n";
        cin >> Num1;
        cout <<"Enter Number 2 :\n";
        cin >> Num2;
}

void Swap_Numbers(int &num1, int &num2)
{ 
    int temp = num1;
    num1 = num2;
    num2 = temp;

}

void Print_Numbers(int num1, int num2)
{
    cout << "\n------------------------\n";
    cout << "Number 1 =\n"<< num1 << endl;
    cout << "Number 2 =\n"<< num2 << endl;
}

int main()
{   
    int A, B;
    Read_2_Numbers(A, B);
    Print_Numbers(A, B);
    Swap_Numbers(A, B);
    cout << "------------------";
    cout << "\nAfter Swap";
    Print_Numbers(A, B);
    return 0;
}
