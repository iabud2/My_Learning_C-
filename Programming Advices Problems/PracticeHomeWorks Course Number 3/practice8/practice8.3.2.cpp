//  Solve Problem 31

#include <iostream>
using namespace std;


int main()
{
    cout << "Enter Any Number :\n";
    float num1;
    cout << "num1 = ";
    cin >> num1;
    cout <<num1<<"^2 = "<< round(pow(num1,2))<<endl;
    cout <<num1<<"^3 = "<< round(pow(num1,3))<<endl;
    cout <<num1<<"^4 = "<< round(pow(num1,4))<<endl;
    return 0;
}