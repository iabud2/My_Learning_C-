// solve problem number 19
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float D;
    cout << "Enter Value of Diameter To Calculate the Circle Area :\nD = ";
    cin >> D;
    float PY = 3.14;
    float circle_area = (PY * pow(D,2))/4;
    cout << ceil(circle_area);
    return 0 ;
}