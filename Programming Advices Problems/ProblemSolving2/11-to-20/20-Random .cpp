#include <iostream>
#include <cstdlib>
using namespace std;

enum enRandom {
	SmallLetter = 1,
	CapitalLetter = 2,
	SpecialCharactter = 3,
	Digit = 4
};

int Read_Input()
{
	int Number = 0;
	do {

		cout << "What do you want to print?\n";
		cout << "Enter (1) for Small letter , (2) for capital letter,\n(3) for special character, (4) for Digit:\n";
		cin >> Number;
	} while (Number < 0 || Number > 4);
	return Number;
}

enRandom pick_Out_Put(int User_Input)
{
	switch (User_Input)
	{
	case 1 :
		return enRandom::SmallLetter;
	case 2:
		return enRandom::CapitalLetter;
	case 3:
		return enRandom::SpecialCharactter;
	case 4:
		return enRandom::Digit;
	}

}


int Random_Number(int from, int to)
{
	int	random_num = rand() % (to - from + 1) + from;
	return random_num;
}

char Output(int number)
{
	if (pick_Out_Put(number) == enRandom::SmallLetter)
	{
		return char(Random_Number(97, 122));
	}
	else if (pick_Out_Put(number) == enRandom::CapitalLetter) 
	{
		return char(Random_Number(65, 90));
	}
	else if (pick_Out_Put(number) == enRandom::SpecialCharactter)
	{
			
	}
	else if (pick_Out_Put(number) == enRandom::Digit)
	{
		return char(Random_Number(48, 57));
	}
	else 
	{
		cout << "Sorry Wrong Input";
	}
}

int main()
{
	srand((unsigned)time(NULL));
	cout << Output(Read_Input());
	return 0;
}
