#include <iostream>
#include <cstdlib>
using namespace std;

int Read_Number(string message)
{
	int  number = 0;
	do
	{
		cout << message;
		cin >> number;
	} while (number <= 0);
	return number;
}

int Random_Number(int from, int to)
{
	int random_num = rand() % (to - from + 1) + from;
	return random_num;
}

void FillArrayWithRandomnumbers(int arr[1000], int& Length)
{

	Length = Read_Number("How Many Elements in Array:\n");
	for (int i = 0; i < Length; i++)
	{
		arr[i] = Random_Number(1, 100);
	}
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}


void Copy_Array_Elements(int arr1[100], int arr2[100], int arr1Length, int &arr2Length)
{
	for (int i=0; i < arr1Length; i++)
	{
		AddArrayElement(arr1[i], arr2, arr2Length);
	}
	
}


void PrintArray(int arr[100], int arrLength, string message)
{
	cout << message << endl;
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << "\n";
}


int main()
{
	srand((unsigned)time(NULL));
	int arr1[100],arr2[100], arrLength = 0, arr2Length = 0;
	FillArrayWithRandomnumbers(arr1, arrLength);
	PrintArray(arr1, arrLength, "\nArray Number[1] elements :\n");
	Copy_Array_Elements(arr1, arr2, arrLength, arr2Length);
	PrintArray(arr2, arrLength, "\nArray Number [2] elements :\n");
	return 0;
}
