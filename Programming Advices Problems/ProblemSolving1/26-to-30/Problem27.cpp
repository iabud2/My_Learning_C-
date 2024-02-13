/*
Problem 27:
Write a program to print numbers from N to 1.
*/

#include <iostream>
using namespace std;

int Number()
{
    int N;
    cout << "Enter A Number:\n";
    cin >> N;
    return N;
}

void Numbers_using_for_loop(int N)
{
    for (int i = N; i >= 1; i--)
    {
        cout << i << endl;
    }
}

void Numbers_using_While_loop(int N)
{
    int i = N;
    while (i >= 1)
    {
        cout << i << endl;
        i--;
    }
}

void Numbers_Using_do_while(int N)
{
    int i = N;
    do
    {
        cout << i << endl;
        i--;
    } while (i >= 1);
}

int main()
{
    // Numbers_using_for_loop(Number());
    // Numbers_using_While_loop(Number());
    Numbers_Using_do_while(Number());
    return 0;
}