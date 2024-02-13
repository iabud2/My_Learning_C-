// Solving Promblem num 18
#include <iostream>
#include <cmath>
using namespace std;


int main(){
    cout << "Enter The Radius To Calculate The Circle Area\nr = ";
    float radius;
    cin >> radius;
    const float PY = 3.14;
    float circle_area = PY * pow(radius, 2);
    cout << "The Circle Are = "<< ceil(circle_area);
    return 0;
}
