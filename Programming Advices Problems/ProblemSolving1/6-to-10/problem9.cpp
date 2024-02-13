/*
Problem 9.
Write a program to ask the user to enter: 
• Number1, Number2, Number3
*/
#include <iostream>
using namespace std;

int arr[3];

void read_Numbers(int arr[3])
{
    for (int i=0; i<3; i++){
        cout << "Enter Number "<< i+1 <<" :\n";
        cin >> arr[i];
    }
}

int sum_Numbers(int arr[3]){
    int sum = 0;
    for (int i = 0; i<3; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void Print_sum(int sum)
{
    cout << sum;
}
int main()
{
    read_Numbers(::arr);
    Print_sum(sum_Numbers(::arr));
    return 0 ;
}