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

void FillArrayWithRandomnumbers(int arr[100], int& Length)
{

	Length = Read_Number("How Many Elements in Array:\n");
	for (int i = 0; i < Length; i++)
	{
		arr[i] = Random_Number(-100, 100);
	}
}


int Negative_Count(int arr1[100], int arr1Length, int& counter)
{

	for (int i = 0; i < arr1Length; i++)
	{
		if (arr1[i] < 0)
		{
			counter++;
		}
	}
	return counter;
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
	int arr1[100], Length = 0, Number = 0;
	FillArrayWithRandomnumbers(arr1, Length);
	PrintArray(arr1, Length, "Array Elemnt is:\n");
	Negative_Count(arr1, Length, Number);
	cout << "\Negative Numbers Count is: " << Number;
	return 0;
}
