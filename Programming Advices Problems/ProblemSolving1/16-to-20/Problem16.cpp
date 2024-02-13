/*
Problem 16:
Write a program to calculate rectangle
area through diagonal and side area of
rectangle and print it on the screen.
*/
#include <iostream>
#include <cmath>
using namespace std;

void Read_Rectangle_Value(int &Side, int &Diagonal)
{
    cout << "Enter The Rectangle Side:\n";
    cin >> Side;
    cout << "Enter The Diagonal:\n";
    cin >> Diagonal;
}

float calculate_Rectngle_Area(int side, int diagonal)
{
    float Area = side * sqrt(pow(diagonal, 2) - pow(side, 2));
    return Area;
}

void Print_Rectangle_Area(float Area)
{
    cout <<"Rectangle Area =\n"<< Area;
}

int main()
{
    int a, d;
    Read_Rectangle_Value(a, d);
    Print_Rectangle_Area(calculate_Rectngle_Area(a, d));
    return 0;
}
