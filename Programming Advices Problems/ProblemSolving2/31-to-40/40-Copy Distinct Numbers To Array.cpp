#include <iostream>
#include <cstdlib>
using namespace std;



void FillArray(int arr[100] , int &Length)
{
	Length = 10;
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;
}


void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}


short FindNumberPositionInArray(int Number, int arr[100], int arrLength) 
{
	for (int i = 0; i < arrLength; i++) 
	{
		if (arr[i] == Number) 
			return i;
	}	return -1; 
} 

bool IsNumberInArray(int Number, int arr[100], int arrLength) 
{ 
	return FindNumberPositionInArray(Number, arr, arrLength) != -1; 
} 

void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
{
	for (int i = 0; i < SourceLength; i++)
	{
		if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
		{
			AddArrayElement(arrSource[i], arrDestination, DestinationLength);
		}
	}
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
	int arr1[100], arr1Length = 0;
	FillArray(arr1, arr1Length);
	int arr2[100], arr2Length = 0;
	PrintArray(arr1, arr1Length, "Array Elements:");
	CopyDistinctNumbersToArray(arr1, arr2, arr1Length, arr2Length);
	PrintArray(arr2, arr2Length, "\nDistinct Array Elements:");
	return 0;
}
