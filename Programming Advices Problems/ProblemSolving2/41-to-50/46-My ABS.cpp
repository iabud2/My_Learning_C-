#include <iostream>
#include <cmath>
using namespace std;




float Read_Number(string message)
{
	float  number = 0;
		cout << message;
		cin >> number;
	return number;
}

float My_Abs(float Number)
{
	if (Number <= 0)
	{
		return (Number * -1);
	}
	else {
		return Number;
	}
}

int main()
{
	float Number = Read_Number("Enter a Number:\n");
	cout << "My abs : " << My_Abs(Number) << endl;
	cout  << "C++ abs : " << abs(Number);
	return 0;
}