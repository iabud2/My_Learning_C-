// Solve Problem 20

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float A;
    cout << "Enter the Area Of The Square To Calculate Circle Area:\nA = ";
    cin >> A;
    float PY = 3.14;
    float circle_area =  PY * pow(A/2, 2);
    cout << ceil(circle_area);
    return 0;
}