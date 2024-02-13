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



void Print_Array(int arr[100], int Length)
{
	cout << "Array elments is :\n\n";
	for (int i = 0; i < Length; i++)
	{
		cout << arr[i] << " ";
	}cout << endl;
}

int Sum_Array(int Array[100], int Length)
{
	int sum = 0;
	for (int i = 0; i < Length; i++)
	{
		sum += Array[i];
	}
	return sum;
}

float Average_Array_Elements(int arr[100], float Length)
{
	float sum = Sum_Array(arr, Length);
	return float(sum / Length);
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100];
	int Length;
	Making_Array(arr, Length);
	Print_Array(arr, Length);
	int Sum = Sum_Array(arr, Length);
	cout << "\nThe Sum of Array Elemnts = " << Sum << endl;
	cout << "\nAverage Value for Array Elements is:\n" << Average_Array_Elements(arr, Length);
	return 0;
}
