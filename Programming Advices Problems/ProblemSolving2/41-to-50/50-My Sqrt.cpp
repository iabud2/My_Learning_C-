#include <iostream>
#include <cmath>
using namespace std;




int Read_Number(string message)
{
	int  number = 0;

	cout << message;
	cin >> number;
	return number;
}


float MySqrt(int Number)
{
	return pow(Number, 0.5);
}


int main()
{
	float Num = Read_Number("Enter A float number:\n");
	cout << "My sqrt : " << MySqrt(Num) << endl;
	cout << "C++ sqrt : " << sqrt(Num);
	return 0;
}