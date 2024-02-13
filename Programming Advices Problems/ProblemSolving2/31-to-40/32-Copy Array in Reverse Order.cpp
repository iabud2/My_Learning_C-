#include <iostream>
#include <cstdlib>
using namespace std;



int Random_Number(int from, int to)
{
	int	random_num = rand() % (to - from + 1) + from;
	return random_num;
}

void FillArrayWithRandomnumbers(int arr[100], int& Length)
{
	cout << "Enter The array Length:\n";
	cin >> Length;
	cout << endl;

	for (int i = 0; i < Length; i++)
	{
		arr[i] = Random_Number(1, 100);

	}
}



void ReverseArray(int Array1[100], int Array2[100],  int Length)
{
	int counter = 1;
	for (int i = 0; i < Length; i++)
	{
		Array2[i] = Array1[Length - counter];
		counter++;
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
	int arr1[100], arr2[100], Length;
	FillArrayWithRandomnumbers(arr1, Length);
	cout << "\nArray Elements:\n";
	Print_Array(arr1, Length);
	ReverseArray(arr1, arr2, Length);
	cout << "\nReversed Array:\n";
	Print_Array(arr2, Length);
	return 0;
}