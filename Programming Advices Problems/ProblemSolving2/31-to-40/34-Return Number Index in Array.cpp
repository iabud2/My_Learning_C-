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

void FillArrayWithRandomnumbers(int arr[1000], int& Length)
{

	Length = Read_Number("How Many Elements in Array:\n");
	for (int i = 0; i < Length; i++)
	{
		arr[i] = Random_Number(1, 100);

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

void find_in_array(int arr[1000], int Length, int Number)
{
	Number = Read_Number("Enter The Number You Looking For: \n");
	cout << "Number You Are Looking for is : " << Number;
	for (int i = 0; i< Length; i++)
	{
		if (arr[i] == Number)
		{
			cout << "\nNumber Found at Position: " << i;
			cout << "\nNumber Found at order:" << i + 1 << endl;
			break;
		}
		else if (arr[i] != Number && i == Length - 1)
		{
			cout << "\nNumber Not Found Sorry\n";
		}
	}

}

int main()
{
	srand((unsigned)time(NULL));
	int arr[1000];
	int Length = 0;
	int Number = 0;
	FillArrayWithRandomnumbers(arr, Length);
	Print_Array(arr, Length);
	find_in_array(arr, Length, Number);
	
	return 0;

}



/*
Teacher Solution
short FindNumberPositionInArray(int Number, int arr[100], int arrLength) 
{
	for (int i = 0; i < arrLength; i++) 
	{	
		if (arr[i] == Number) return i;
	}
	return -1; }

	
int main() 
{ 

	srand((unsigned)time(NULL)); 

	int arr[100], arrLength;     

	FillArrayWithRandomNumbers(arr, arrLength);     

	cout << "\nArray 1 elements:\n";     

	PrintArray(arr, arrLength); int Number = ReadNumber();     

	cout << "\nNumber you are looking for is: " << Number << endl; 

	short NumberPosition = FindNumberPositionInArray(Number, arr, arrLength); 

	if (NumberPosition == -1)         

	cout << "The number is not found :-(\n"; 

	else    

	{         

	cout << "The number found at position: ";         

	cout << NumberPosition << endl;         

	cout << "The number found its order  : ";          

	cout << NumberPosition + 1 << endl;     

	} 

	return 0; 	
}
*/