/*
Problem 11.
Write a program to ask the user to enter:
• Mark1, Mark2, Mark3

##
Then Print the Average of entered Marks, and print “PASS” 
if average>=50,
otherwise print “FAIL”
*/

#include <iostream>
using namespace std;

enum enStatus
{
    Pass = 1,
    Fail = 2
};
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
    return sum / 3;
}

enStatus checkAvergae(float average)
{
    if (average >= 50)
        return enStatus::Pass;
    else
        return enStatus::Fail;
}

void Print_sum(float average)
{
    cout << "Your Degree Is : " << average << endl;
    if (checkAvergae(average) == enStatus::Pass)
        cout << "You Passed !" << endl;
    else
        cout << "You Failed" << endl;
}
int main()
{
    read_Numbers(::arr);
    Print_sum(average_Mark(sum_Numbers(::arr)));
    return 0;
}