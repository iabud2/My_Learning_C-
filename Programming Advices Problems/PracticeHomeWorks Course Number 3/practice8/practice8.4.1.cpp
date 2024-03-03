// Sol for problems 21

// After Find The reuslt Set use Floor And Print The Results
#include <iostream>
#include <cmath>
using namespace std;


int main (){
    float L;
    cout << "Enter The  Circumference:\nL = ";
    cin >> L;
    float PY = 3.14 * 4 ;
    float Area = pow(L,2) / PY;
    cout << floor(Area);
    return 0;
}




