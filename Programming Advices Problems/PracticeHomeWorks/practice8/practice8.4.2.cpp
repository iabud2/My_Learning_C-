// Sol for problem 23
#include <iostream>
#include <cmath>
using namespace std;



int main()
{
    float A;
    float B;
    cout << "Enter The values of triangle sides to calculate circle Area\nA = ";
    cin >> A;
    cout <<"B = ";
    cin >> B;
    float PY = 3.14;
    float calculate_area = (PY * pow(B,2)/4) *((2 * A - B)/(2 * A + B));
    cout << floor(calculate_area);
    return 0 ;

}
