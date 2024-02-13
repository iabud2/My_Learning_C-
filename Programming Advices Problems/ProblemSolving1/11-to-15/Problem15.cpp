/*
Problem 15:
Write a program to calculate rectangle area and print it on the screen.
*/
#include <iostream>
using namespace std;

void Read_rectangle_values(int &height, int &width)
{
    cout << "Enter The heigth :\n";
    cin >> height;
    cout << "Enter The Width :\n";
    cin >> width;
}

float calculate_Rectangle_Area(int height, int width){
    float Area = height * width;
    return Area;

}

void Print_Rectangle_Area(float Area)
{
    cout << "Reactangler Area :\nwidth * heigth =\n" << Area;
}

int main()
{
    int heigth, width;
    Read_rectangle_values(heigth, width);
    Print_Rectangle_Area(calculate_Rectangle_Area(heigth, width));
    return 0;
}