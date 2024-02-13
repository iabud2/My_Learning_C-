/*
Problem 17:
Write a program to calculate triangle area then print it on the screen.
The usee should enter:
-a,
-h.
Area = 0.5 *a*h
a = Basse, h = heigth; 

*/
#include <iostream>
#include <cmath>
using namespace std;



void Read_triangle_Values(int &a, int &h)
{

    cout << "Enter The base Value:\n";
    cin >> a;
    cout << "Enter The heigth value:\n";
    cin >> h;

}

float calculate_Triangle_area(int a, int h)
{
    float Area = 0.5 * a * h;
    return Area;
}

void Print_Triangle_Area(float Area)
{
    cout << Area;
}

int main()
{
    int a, h;
    Read_triangle_Values(a, h);
    Print_Triangle_Area(calculate_Triangle_area(a, h));
    return 0;

}