/*
Problem10.
Write a program to ask the user to enter:
• Mark1, Mark2, Mark3
*/
#include <iostream>
using namespace std;


int arr[3];

void read_Numbers(int arr[3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Number " << i + 1 << " :\n";
        cin >> arr[i];
    }
}

int sum_Numbers(int arr[3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += arr[i];
    }
    return sum;
}

float average_Mark(float sum)
{
    return  sum  / 3;
}




void Print_sum(float average)
{
    cout << "Your Degree Is : " << average << endl;

}
int main()
{
    read_Numbers(::arr);
    Print_sum(average_Mark(sum_Numbers(::arr)));
    return 0;
}