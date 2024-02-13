/*
Problem 18 :
Write a program to calculate circle area then print it on the screen.
The use should enter:
-r.
*/

#include <iostream>
#include <cmath>
using namespace std;

void Read_circle_values(float &r)
{
    cout << "Enter (r) Value:\n";
    cin >> r;
}

float Calculate_Cirtcle_Area(float r)
{   
    float PI = 3.14;
    float area = PI * pow(r, 2);
    return area;
}

void Print_Circle_Area(float Area)
{
    cout << Area;
}

int main()
{
    float r;
    Read_circle_values(r);
    Print_Circle_Area(Calculate_Cirtcle_Area(r));
    return 0;
}