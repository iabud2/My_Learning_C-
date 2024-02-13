#include <iostream>
#include <cstdlib>
using namespace std;

int Read_Number(string message)
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
	int random_num = rand() % (to - from + 1) + from;
	return random_num;
}

void FillArrayWithRandomnumbers(int arr[1000], int &Length)
{

	Length = Read_Number("How Many Elements in Array:\n");
	for (int i = 0; i < Length; i++)
	{
		arr[i] = Random_Number(1, 100);
	}
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
			return i;
	}
	return -1;
}

bool CheckInArray(int arr[100], int num, int Length)
{

	int Result = FindNumberPositionInArray(num, arr, Length);
	cout << "Number [" << num << "] :\n";
	if (Result != -1)
	{

		cout << "Found at Position : " << Result << endl;
		cout << "Aslo Found in order : " << Result + 1 << endl;
		return 1;
	}
	else
	{
		cout << "Sorry Number Not Found :(";
		return 0;
	}
}
void Print_Array(int arr[0100], int Length)
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
	int arr[100];
	int Length = 0;
	FillArrayWithRandomnumbers(arr, Length);
	Print_Array(arr, Length);
	int Number = Read_Number("Enter The Number:\n");
	CheckInArray(arr, Number, Length);
	return 0;
}
