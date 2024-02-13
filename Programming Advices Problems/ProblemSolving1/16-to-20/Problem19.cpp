/*
Problem 19:
Write a program to calculate circle area through diameter,
then print it on the screen.

The use should enter:
-D
D = Diagonal
*/
#include <iostream>
#include <cmath>
using namespace std;

float Read_D_Value(int &D)
{
    
    cout << "Enter The Diagonal Value:\n";
    cin >> D;
    return D;
}

float Calculate_Circle_Area(float D)
{
    float PI = 3.14;
    float Area = (PI * pow(D, 2))/(4);
    return Area;
}

void Print_Circle_Area(float Area)
{
    cout << Area;
}

int main()
{
    int D = 0;
    Print_Circle_Area(Calculate_Circle_Area(Read_D_Value(D)));
    return 0;
}