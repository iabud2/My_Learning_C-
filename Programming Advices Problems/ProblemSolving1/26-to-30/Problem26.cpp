/*
Problem 26:
Write a program to print numbers from 1 to N.
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
    for (int i = 1; i<=N; i++)
    {
        cout << i << endl;    
    }
}

void Numbers_using_While_loop(int N){
    int i = 1;
    while (i <= N)
    {
        cout << i << endl;
        i++;
    }
}

void Numbers_Using_do_while(int N)
{
    int i = 1;
    do
    {
        cout << i << endl;
        i++;
    } while (i <= N);
    
}
int main()
{
    // Numbers_using_for_loop(Number());
    // Numbers_using_While_loop(Number());
    Numbers_Using_do_while(Number());
    return 0;
}