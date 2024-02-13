#include <iostream>
#include <cstdlib>
using namespace std;

/*
// My Solution;
int Read_Number(string message)
{
	int number = 0;
		cout << message;
		cin >> number;
	return number;
}

int Enter_Numbers_in_array(int arr[100], int element, int &Length)
{
	short YesOrNO = 0;
	Length = 0;
	do {
		element = Read_Number("Enter a Number: ");
		arr[Length] = element;
		cout << "Do You Want To add more numbers? [0]:No, [1]:Yes?";
		cin >> YesOrNO;

		Length++;

	} while (YesOrNO == 1);


	cout << "Array Length : " << Length;
	return Length;
}


void Print_Array(int arr[0100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[100], arrElement, Length;
	Enter_Numbers_in_array(arr, arrElement, Length);
	cout << "\nArray Elements: ";
	Print_Array(arr, Length);
}

*/

// Teacher Solution

#include <iostream>
using namespace std;
int ReadNumber()
{
	int Number;
	cout << "\nPlease enter a number? ";
	cin >> Number;
	return Number;
}
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}

void InputUserNumbersInArray(int arr[100], int &arrLength)
{
	bool AddMore = true;
	do
	{
		AddArrayElement(ReadNumber(), arr, arrLength);
		cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
		cin >> AddMore;
	} while (AddMore);
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	int arr[100], arrLength = 0;
	InputUserNumbersInArray(arr, arrLength);
	cout << "\nArray Length: " << arrLength << endl;
	cout << "Array elements: ";
	PrintArray(arr, arrLength);
	return 0;
}