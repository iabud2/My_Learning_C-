/*
Problem 23:
Write a program to calculate circle area,
circle described around an arbitrary triangle,
then print it on the screen.
The use should enter:
-a
-b
-C
*/

#include <iostream>
#include <cmath>
using namespace std;

void Read_Values(float &A, float &B, float &C)
{
    cout << "Enter The First side:\n";
    cin >> A;
    cout << "Enter The Second side:\n";
    cin >> B;
    cout << "Enter The Third side:\n";
    cin >> C;
}

float calculate_Circle_Area(float A, float B, float C)
{   
    float PI = 3.14; 
    float P = (A + B + C)/2;
    float Area = PI * (pow((A * B * C)/(4 * sqrt(P * (P - A) *
                        (P - B) * (P - C))), 2));
    return Area;
}

void Print_Result(float Area)
{
    cout << Area;
}

int main()
{
    float a, b, c;
    Read_Values(a, b, c);
    Print_Result(calculate_Circle_Area(a, b, c));
    return 0 ;
}

