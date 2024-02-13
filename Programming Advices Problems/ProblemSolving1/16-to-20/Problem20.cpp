/*
Problem 20:
Write a program to calculate Circle area inscribed in a square,
then print it on the screen.
The user should enter:
A = Square side.
*/
#include <iostream>
#include <cmath>
using namespace std;

void Read_Square_Side(float &A)
{
    cout << "Enter A Square Side:\n";
    cin >> A;
}

float Calculate_Circle_Area(float A)
{
    float PI = 3.14;
    float Area = (PI) * (pow((A/2), 2));
    return Area;
}

void Print_Circle_Area(float Area)
{
    cout << Area;
}

int main()
{
    float A;
    Read_Square_Side(A);
    Print_Circle_Area(Calculate_Circle_Area(A));
    return 0;
}