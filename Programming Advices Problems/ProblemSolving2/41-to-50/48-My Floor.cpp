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

float GetFractionPart(float Number)
{
	return Number - int(Number);
}

int MyFloor(float Number)
{
	int MyIntPart = (int)Number;
	if (abs(GetFractionPart(Number)) != 0 )
	{
		if (Number > 0)
			return MyIntPart;
		else
			return --MyIntPart;
	}
	else
		return MyIntPart;
}

int main()
{
	float Num = Read_Number("Enter A float number:\n");
	cout << "My floor : " << MyFloor(Num) << endl;
	cout << "C++ floor : " << floor(Num);
	return 0;
}