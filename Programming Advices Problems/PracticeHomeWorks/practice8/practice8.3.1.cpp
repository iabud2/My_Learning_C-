// solving problems 23, 42, 43
//  After finding The result use round and print the results
#include <iostream>
#include <cmath>
using namespace std;


int main(){
    float a, b ,c;
    cout << "Enter The Values Of The triangle sides To calculate circle area\nA = ";
    cin >> a;
    cout << "B = "; 
    cin >> b;
    cout << "C = ";
    cin >> c;
    float PY = 3.14;
    float p = (a+b+c)/2;
    float circle_area = PY * pow((a*b*c)/(4 * (sqrt(p*(p-a)*(p-b)*(p-c)))), 2);
    cout << round(circle_area);
    return 0 ;

}



