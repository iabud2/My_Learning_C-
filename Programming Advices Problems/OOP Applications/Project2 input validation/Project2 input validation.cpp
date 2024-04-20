#include <iostream>
#include "clsInputValidate.h"
#include "clsDate.h"

using namespace std;

int main()
{
	cout << clsInputValidate::IsNumberBetween(9, 5, 10) << endl;

	cout << clsInputValidate::IsNumberBetween(5.1, 2.2, 10.2) << endl;
	clsDate Date1, Date2(1, 1, 2020), Date3(3, 3, 2022);
	cout << clsInputValidate::IsDateBetween(Date1, Date2, Date3) << endl;

	int x = clsInputValidate::ReadIntNumber();
	cout << "x = " << x << endl;

	cout << "Enter int Number Between 1 And 5 :\n";
	int A = clsInputValidate::ReadIntNumberBetween(1, 10);
	cout << "A = " << A << endl;


	double Y = clsInputValidate::ReadDblNumber();
	cout << "Y = " << Y << endl;

	cout << "Enter Double Number Between 1.1 And 2.5 :\n";
	double Z = clsInputValidate::ReadDblNumberBetween(1.1, 2.5);
	cout << "Z =" << Z << endl;
	return 0;
}
