#include <iostream>

using namespace std;


int Read_Number(string message)
{
	int Name = 0;
	cout << message;
	cin >> Name;
	return Name;
}

void Making_Array(int arr[100], int &Length)
{
	cout << "Enter The array Length:\n";
	cin >> Length;
	cout << endl << endl;
	cout << "You Making Array Of " << Length << ": \n\n";
	cout << "Enter Array Elemnts :\n\n";
	
	for (int i = 0; i < Length; i++)
	{
		cout << "Elemnt [" << i + 1 <<"] : ";
		cin >> arr[i];

	}cout << endl;
}

int Duplicate_Counter(int arr[100], int Length, int Number)
{
	int counter = 0;
	for (int i = 0; i < Length; i++)
	{
		if (arr[i] == Number)
		{
			counter++;
		}
	}
	return counter;
}

void Print_Array(int arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << arr[i]<< " ";
	}cout << endl;
}

void Array_info(int Number_Check, int myarr[100], int Length)
{
	cout << "the original array is :\n";
	Print_Array(myarr, Length);
	cout << endl << "Number " << Number_Check << " is repeated " << Duplicate_Counter(myarr, Length, Number_Check) << " Time(s)\n";
}

int main()
{
	int myarr[100], Array_Length;
	Making_Array(myarr,Array_Length);

	int check_Number = Read_Number("Enter the number you want to check:\n");
	Array_info(check_Number, myarr, Array_Length);


	return 0;

}

