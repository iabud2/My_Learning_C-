#include<iostream>
#include<string>
#include<cstdlib>
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
	int random_num = rand() % (to - from + 1) + from;
	return random_num;
}


int User_Choice()
{
	int Player_Choice = 0;
	do {
		 Player_Choice = Read_Number("Your Turn, [1]:Stone, [2]:Paper, [3]:Scissors ?  ");
	} while (Player_Choice <= 0 || Player_Choice > 3);

	return Player_Choice;
}

int Computer_Choice()
{
	int Pc_Choice = Random_Number(1, 3);
	return Pc_Choice;
}

string Choices(int Choice)
{
	if (Choice == 1)
		return "Stone";
	else if (Choice == 2)
		return "Paper";
	else
		return "Schissors";
}

int The_Game(int Pick_One, int Pick_Two)
{
	// If player Pick_one wins return 1, if Pick_Two wins return 2, if Draw return 3;

	if (Pick_One == Pick_Two)
	{
		return 3;
	}
	else if (Pick_One == 1 && Pick_Two == 2)
	{
		return 2;
	}
	else if (Pick_One == 1 && Pick_Two == 3)
	{
		return 1;
	}
	else if (Pick_One == 2 && Pick_Two == 1)
	{
		return 1;
	}
	else if (Pick_One == 2 && Pick_Two == 3)
	{
		return 2;
	}
	else if (Pick_One == 3 && Pick_Two == 1)
	{
		return 2;
	}
	else if (Pick_One == 3 && Pick_Two == 2)
	{
		return 1;
	}

}

int  Display_The_Round(int Player_Pick, int Computer_Pick, int Round)
{
	cout << "\n\n_________________________Round [" << Round << "]___________________\n\n";
	cout << "\nPlayer Choice :" << Choices(Player_Pick);
	cout << "\nComputerChoice : " << Choices(Computer_Pick) << endl;
	int Chooose_Winner = The_Game(Player_Pick, Computer_Pick);
	if (Chooose_Winner == 1)
	{
		system("Color 2F");
		cout << "Round winner is : " << "Player\n";
		return 1;

	}
	else if (Chooose_Winner == 2)
	{
		system("Color 4F");
		cout << "\aRound winner is : " << "Computer\n";
		return 2;

	}
	else {
		system("Color 6F");
		cout << "Draw\n";
		return 3;
	}
	cout <<"\n\n_____________________________________________________\n\n";
}




void Game_as_Many_Rounds(int &Player_Counter, int &Computer_Counter, int &Draw_Counter, int &Counter)
{

	Counter = Read_Number("How Many Rounds? ");
	int i = 1;

	do
	{
		cout << "\n\nRound [" << i << "] begins :\n\n";
		int Game_Result = Display_The_Round(User_Choice(), Computer_Choice(), i);
		if (Game_Result == 1)
		{
			Player_Counter++;
		}
		else if (Game_Result == 2)
		{
			Computer_Counter++;
		}
		else if (Game_Result == 3)
		{
			Draw_Counter++;
		}
		cout << endl;
		i++;
	} while (i <= Counter);

}


void Game_Result(int Player_Counter, int Computer_Counter, int Draw_Counter, int Rounds)
{
	cout << "\n\t\t---------------------------------------------------";
	cout << "\n\n\t\t\t\t+++ Game Over +++\t\t\n\n";
	cout << "\t\t---------------------------------------------------\n";
	cout << "\t\tGame Rounds\t\t: " << Rounds<< endl;
	cout << "\t\tPlayer Wins\t\t: " << Player_Counter;
	cout << "\n\t\tComputer Wins\t\t: " << Computer_Counter;
	cout << "\n\t\tDraw Times\t\t: " << Draw_Counter << endl;



	if (Player_Counter > Computer_Counter)
		cout << "\t\tFinal Winner\t\t: Player";
	else if (Player_Counter < Computer_Counter)
		cout << "\t\tFinal Winner\t\t: Computer";
	else if (Player_Counter == Computer_Counter)
		cout << "\t\tDraw";
}




int main()
{
	string ask = "";
	do {

		int Player_counter = 0, Computer_Counter = 0, Draw_Counter = 0, Rounds = 0;
		srand((unsigned)time(NULL));
		Game_as_Many_Rounds(Player_counter, Computer_Counter, Draw_Counter, Rounds);
		Game_Result(Player_counter, Computer_Counter, Draw_Counter, Rounds);



		cout << "\nYou want to play more? y/n? :";
		cin >> ask;
		if (ask == "n" || ask == "N")
			break;
	} while (ask != "n" || ask != "N");
	
	return 0;
}