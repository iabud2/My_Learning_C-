/*
Problem 21:
Write a program to calculate circle area along the circumference, 
then print it on the screen.

The use should enter:
L
*/
#include <iostream>
#include <cmath>
using namespace std;

void Read_Num(float &L)
{
    cout << "Enter the circumference:\n";
    cin >> L;
}

float calculate_Circle_Area(float L)
{
    float PI = 3.14;
    float Area = (pow(L, 2))/(4 * PI);
    return Area;
}

void Print_Circle_Area(float Area)
{
    cout << Area;
}

int main()
{
    float L;
    Read_Num(L);
    Print_Circle_Area(calculate_Circle_Area(L));
    return 0;
}