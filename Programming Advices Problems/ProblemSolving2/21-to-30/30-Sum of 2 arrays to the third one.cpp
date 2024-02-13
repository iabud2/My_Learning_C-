#include <iostream>
#include <cstdlib>
using namespace std;



float Read_Number(string message)
{
	float number = 0;
	do
	{
		cout << message;
		cin >> number;
	} while (number <= 0);
	return number;
}

int Random_Number(int from, int to)
{
	int	random_num = rand() % (to - from + 1) + from;
	return random_num;
}

void FillArrayWithRandomnumbers(int arr[100], int& Length)
{


	for (int i = 0; i < Length; i++)
	{
		arr[i] = Random_Number(1, 100);

	}
}

void sum_array(int arr1[100], int arr2[100], int arr3[100], int Length)
{
	for (int i = 0; i<Length; i++)
	{
		arr3[i] = arr1[i] + arr2[i];
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
	int arr1[100], arr2[100], arr3[100];
	int Length = Read_Number("Enter The array length:\n");
	FillArrayWithRandomnumbers(arr1, Length);
	FillArrayWithRandomnumbers(arr2, Length);
	cout << "\nArray 1 Elemnts:\n";
	Print_Array(arr1, Length);
	cout << "\nArray 2 Elemnts:\n";
	Print_Array(arr2, Length);
	sum_array(arr1, arr2, arr3, Length);
	cout << "\nArray of Sums :\n";
	Print_Array(arr3, Length);

	return 0;

}

