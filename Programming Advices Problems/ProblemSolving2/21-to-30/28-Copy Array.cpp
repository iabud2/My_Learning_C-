#include <iostream>
#include <cstdlib>
using namespace std;

int Read_Number(string message)
{
	int Name = 0;
	cout << message;
	cin >> Name;
	return Name;
}

int Random_Number(int from, int to)
{
	int	random_num = rand() % (to - from + 1) + from;
	return random_num;
}

void Making_Array(int arr[100], int& Length)
{
	cout << "Enter The array Length:\n";
	cin >> Length;
	cout << endl;

	for (int i = 0; i < Length; i++)
	{
		arr[i] = Random_Number(0, 100);

	}
}

void Copy_Array(int Array1[100], int Array2[100], int Length)
{
	cout << "Copied Array is: ";
	for (int i = 0; i < Length; i++)
	{
		Array2[i] = Array1[i];
	}
}

void Print_Array(int arr[100], int Length)
{
	cout << "Array elments is :\n\n";
	for (int i = 0; i < Length; i++)
	{
		cout << arr[i] << " ";
	}cout << endl;
}



int main()
{
	srand((unsigned)time(NULL));
	int arr[100]; 
	int arr2[100];
	int Length;
	Making_Array(arr, Length);
	Print_Array(arr, Length);
	Copy_Array(arr, arr2, Length);
	Print_Array(arr2, Length);


	

	return 0;
}
