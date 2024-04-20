#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;


class clsUtil
{

public:

	enum enCharType {
		SmallLetter = 1,
		CapitalLetter = 2,
		Digit = 3,
		SpecialCharactter = 4,
		Mix = 5,
	};

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}


	static int Random_Number(int from, int to)
	{
		int	random_num = rand() % (to - from + 1) + from;
		return random_num;
	}

	static char Random_Character(enCharType CharType)
	{
		if (CharType == enCharType::Mix)
		{
			CharType = (enCharType)Random_Number(1, 3);
		}

		switch (CharType)
		{
		case clsUtil::SmallLetter:
			return char(Random_Number(97, 122));
			break;
		case clsUtil::CapitalLetter:
			return char(Random_Number(65, 90));
			break;
		case clsUtil::Digit:
			return char(Random_Number(48, 57));
			break;
		case clsUtil::SpecialCharactter:
			return char(Random_Number(33, 47));
			break;
		default:
			return char(Random_Number(65, 90));
			break;
		}
	}

	static string Generate_Word(enCharType Type, int Length = 4)
	{
		string word = "";
		for (int i = 1; i <= Length; i++)
		{
			word = word + Random_Character(Type);

		}
		return word;
	}

	static string Generate_Key(enCharType Type, int WordLength = 4, int WordsCount = 4)
	{
		string key = "";
		for (int i = 1; i <= WordsCount; i++)
		{
			if (i == WordsCount)
				key = key + Generate_Word(Type, WordLength);
			else
				key = key + Generate_Word(Type, WordLength) + "-";
		}
		return key;
	}


	static void Generated_Keys(int Amount, enCharType CharType)
	{
		for (int i = 1; i <= Amount; i++)
		{
			cout << "Key Number [" << i << "] : ";
			cout << Generate_Key(CharType) << endl;
		}
	}


	static  void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}


	static  void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void shuffle_Array(int arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			Swap(arr[Random_Number(1, Length) - 1], arr[Random_Number(1, Length) - 1]);
		}

	}

	static void shuffle_Array(string arr[100], int Length)
	{

		for (int i = 0; i < Length; i++)
		{
			Swap(arr[Random_Number(1, Length) - 1], arr[Random_Number(1, Length) - 1]);
		}

	}

	static void Print_Array(int arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	static void Print_Array(string arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	static void FillArrayWithRandomNumbers(int arr[100], int Length, int from, int to)
	{
		for (int i = 0; i < Length; i++)
		{
			arr[i] = Random_Number(from, to);
		}
	}

	static void FillArrayWithRandomWords(string arr[100], int Length, enCharType CharType, int WordLength)
	{
		for (int i = 0; i < Length; i++)
		{
			arr[i] = Generate_Word(CharType, WordLength);
		}
	}

	static void FillArrayWithRandomKeys(string arr[100], int keyscount, enCharType CharType, int WordLength = 4, int WordsCount = 4)
	{
		for (int i = 0; i < keyscount; i++)
		{
			arr[i] = Generate_Key(CharType, 6, WordsCount);
		}
	}

	static string Tabs(int HowManyTabs)
	{
		string t = "";
		for (int i = 1; i <= HowManyTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;
	}

	static string  EncryptText(string Text, short EncryptionKey = 2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}

	static string  DecryptText(string Text, short EncryptionKey = 2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
		return Text;

	}

	static string Number_To_Text(int Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string arr[] =
			{ "", "One", "Two", "Three", "Fou", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
			 "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "", "", "Twenty", "Thirty", "Forty", "fifty", "Sixty", "Seventy", "Eighty", "nenety" };
			return arr[Number / 10] + " " + Number_To_Text(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + Number_To_Text(Number % 100);
		}
		if (Number >= 200 && Number <= 999)
		{
			return Number_To_Text(Number / 100) + " Hundred " + Number_To_Text(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + Number_To_Text(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999)
		{
			return Number_To_Text(Number / 1000) + "Thousand " + Number_To_Text(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + Number_To_Text(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999)
		{
			return Number_To_Text(Number / 1000000) + "Millions " + Number_To_Text(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + Number_To_Text(Number % 1000000000);
		}
		if (Number >= 2000000000 && Number <= 999999999999)
		{
			return Number_To_Text(Number / 1000000000) + "Billions " + Number_To_Text(Number % 1000000000);
		}
		else
		{
			return "Out Of Range";
		}
	}

};

