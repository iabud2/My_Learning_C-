#include <iostream>
#include <cstdlib>
using namespace std;



void FillArray(int arr[100], int& Length)
{
	Length = 6;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;

}


bool IsPalindromeArray(int arr[10], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		if (arr[i] != arr[Length - 1 - i])
		{
			return false;
		}
	}
	return true;
}

void PrintArray(int arr[10], int arrLength, string message)

{
	cout << message << endl;
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << "\n";
}


int main()
{
	int arr1[10], Length = 0;
	FillArray(arr1, Length);
	PrintArray(arr1, Length, "Array Element:\n");
	if (IsPalindromeArray(arr1, Length))
		cout << "Array Is a Palidrome Array.";
	else
		cout << "It's not a Palidrome Array.";

	return 0;
}
