#include <iostream>
#include <cstdlib>
using namespace std;

enum enNumberType
{
	Prime = 1, NotPrime = 2
};

enNumberType NumberType(int Number)
{
	int H = round(Number / 2);
	for (int i = 2; i <= H; i++)
	{
		if (Number % i != 0)
		{
			return enNumberType::NotPrime;
		}
		else
		{
			return enNumberType::Prime;
		}
	}
}


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



void Copy_Prime_Numbers(int SourceArray[100], int PrimeArray[100], int Length, int &arr2Length)
{
	int counter = 0;
	for (int i = 0; i < Length; i++)
	{
		if (NumberType(SourceArray[i]) == enNumberType::Prime)
		{
			PrimeArray[counter] = SourceArray[i];
			counter++;
		}
	}
	arr2Length = --counter;
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
	int arr1[100], arr1Length;
	FillArrayWithRandomnumbers(arr1, arr1Length);
	int	arr2[100], arr2Length = 0;
	Copy_Prime_Numbers(arr1, arr2, arr1Length, arr2Length);
	cout << "\nThe Original Array Is:\n";
	Print_Array(arr1, arr1Length);
	cout << "\nPrime Numbers Array:\n";
	Print_Array(arr2, arr2Length);






	return 0;
}

