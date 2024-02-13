/*
Problem 22:
Write a program to calculate circle area Inscribed in an Isosceles Triangle,
then print it on the screen.
The use should enter:
-a
-b
a & b is a triangle sides.
*/
#include <iostream>
#include <cmath>
using namespace std;

void Read_Values(float &A, float &B)
{
    cout << "Enter The First Value:\n";
    cin >> A;
    cout << "Enter The Second Value:\n";
    cin >> B;
}

float calculate_Circle_Area(float A, float B ){
    float PI = 3.14;
    float Area = (PI) * (pow(B, 2)/4)*((2*A-B)/(2*A+B));
    return Area;
}

void Print_Area(float Area)
{
    cout << Area;
}

int main()
{
    float A, B;
    Read_Values(A, B);
    Print_Area((calculate_Circle_Area(A, B)));
    return 0;
}