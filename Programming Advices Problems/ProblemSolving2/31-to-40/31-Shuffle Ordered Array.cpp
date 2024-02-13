#include <iostream>
#include <cstdlib>
using namespace std;





int Read_Number(string message)
{
	int number = 0;
	do
	{
		cout << message;
		cin >> number;
	} while (number <= 0);
	return number;
}

void FillArray(int arr[100], int& Length)
{


	for (int i = 0; i < Length; i++)
	{
		arr[i] = i + 1;

	}
}

void Swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;

}
int Random_Number(int from, int to)
{
	int	random_num = rand() % (to - from + 1) + from;
	return random_num;
}

void shuffle_Array(int arr[100],int Length)
{

	cout << "Array Elements After shuffle:\n";
	for (int i =  0; i<Length; i++)
	{
		Swap(arr[Random_Number(1, Length) - 1], arr[Random_Number(1, Length) - 1]);
	}

}

void Print_Array(int arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));
	int Array[100], Length;

	Length = Read_Number("Enter array Length:\n");
	FillArray(Array, Length);
	cout << "Original Array is :\n";
	Print_Array(Array, Length);
	shuffle_Array(Array, Length);
	Print_Array(Array, Length);
	return 0;

}