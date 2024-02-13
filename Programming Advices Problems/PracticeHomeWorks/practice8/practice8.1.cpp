// solve problem num 16 

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter The Diagonal And Side Are Or Rectangle To Calculate Rectangle Area\n";
    float a;
    cout << "a = ";
    cin >> a;
    float d;
    cout << " d = ";
    cin >> d ;

    float  Area = a * sqrt(pow(d,2) - pow(a, 2));
    cout << "Rectangle Area = "<< Area;
    return 0;

    



}