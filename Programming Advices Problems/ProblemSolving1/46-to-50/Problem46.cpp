/*
Problem 46:
Write a program to print all letters from A to Z
*/
#include <iostream>
using namespace std;
void Print_Letters(){
    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << endl;
    }
}

int main()
{
    Print_Letters();
    return 0;
}
