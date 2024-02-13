/*
Problem 8;
Write a program to ask the user to enter:
• Mark1,
Then Print the “PASS” if mark >=50, otherwise print “Fail”
*/

#include <iostream>
using namespace std;

enum enStatus {PASS = 1, FAIL = 2};

int  Read_Mark()
{
    int Mark;
    cout << "Enter Your Mark:";
    cin >> Mark;
    return Mark;
}

enStatus check_Mark(int Mark)
{

    if (Mark >=50){
        return enStatus::PASS;
    }
    else {
        return enStatus::FAIL;
    }
}

void Print_Status(int Number)
{
    if (check_Mark(Number) == enStatus::PASS)
        cout << "PASS";
    else 
        cout <<"FAIL";
}

int main()
{
    Print_Status(Read_Mark());
    return 0;
}