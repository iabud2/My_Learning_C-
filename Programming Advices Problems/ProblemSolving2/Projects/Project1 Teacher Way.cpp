#include <iostream>
#include <cstdlib>
using namespace std;

enum enChoices {Stone = 1, Paper = 2, Scissors = 3};
enum enWinner {Player = 1, Computer = 2, Draw = 3};

struct stRoundInfo
{
	short Round = 0;
	enChoices PlayerChoice;
	enChoices ComputerChoice;
	enWinner Winner;
	string WinnerNam = "";
};

struct stGameResult
{
	short Rounds = 0;
	short PlayerWins = 0;
	short ComputerWins = 0;
	short Drawtimes = 0;
	enWinner GameWinner;
	string GameWinnerName = "";
};

int Random_Number(int from, int to)
{
	int randint = rand() % (to - from + 1) + from;
	return randint;
}

string WinnerName(enWinner Winner)
{
	string Array_winners[3] = {"Player", "Computer", "Draw"};
	return Array_winners[Winner - 1];
}

string ChoiceName(enChoices Choice)
{
	string ArrayChoices[3] = { "Stone", "Paper", "Scissors" };
	return ArrayChoices[Choice - 1];
}

enWinner GameRules(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}
	switch (RoundInfo.PlayerChoice)
	{
	case enChoices::Stone:
		if (RoundInfo.ComputerChoice == enChoices::Paper)
		{
			return enWinner::Computer;
		}
		break;
	case enChoices::Paper:
		if (RoundInfo.ComputerChoice == enChoices::Scissors)
		{
			return enWinner::Computer;
		}
		break;
	case enChoices::Scissors:
		if (RoundInfo.ComputerChoice == enChoices::Stone)
		{
			return enWinner::Computer;
		}
		break;
	}
	return enWinner::Player;	
}

void Set_Screen_Color(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Computer:
		system("Color 4F");
		cout << "\a";
		break;
	case enWinner::Player:
		system("Color 2F");
		break;
	case enWinner::Draw:
		system("Color 6F");
		break;
	}
}

void Print_Round_Result(stRoundInfo RoundInfo)
{
	cout << "\n____________Round [" << RoundInfo.Round << "]____________\n\n";
	cout << "Player Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	Set_Screen_Color(RoundInfo.Winner);
	cout << "Round Winner : " << WinnerName(RoundInfo.Winner) << endl;
	cout << "\n__________________________________\n" << endl;

}

enWinner Game_Winner(short PlayerCounter, short ComputerCounter)
{
	if (PlayerCounter > ComputerCounter)
	{
		return enWinner::Player;
	}
	else if (PlayerCounter < Computer)
	{
		return enWinner::Computer;
	}
	else
	{	
		return enWinner::Draw;
	}
}

stGameResult Get_Game_Result(short Rounds, short PlayerWins, short ComputerWins, short Draw)
{
	stGameResult GameResults;

	GameResults.Rounds = Rounds;
	GameResults.PlayerWins = PlayerWins;
	GameResults.ComputerWins = ComputerWins;
	GameResults.Drawtimes = Draw;
	GameResults.GameWinner = Game_Winner(PlayerWins, ComputerWins);
	GameResults.GameWinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

enChoices ReadPlayerChoice()
{
	short Choice = 1;
	do {
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
		cin  >> Choice;
	} while (Choice < 1 || Choice > 3);

	return enChoices(Choice);
}

enChoices GetComputerChoice()
{
	return enChoices(Random_Number(1, 3));
}

stGameResult PlayGame(short Rounds)
{
	stRoundInfo RoundInfo;
	short PlayerWins = 0, ComputerWins = 0, Draw = 0;
	for (short RoundCounter = 1; RoundCounter <= Rounds; RoundCounter++)
	{
		cout << "\nRound [" << RoundCounter << "] Begins:\n";
		RoundInfo.Round = RoundCounter;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = Game_Winner(RoundInfo.PlayerChoice, RoundInfo.ComputerChoice);
		RoundInfo.WinnerNam = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player)
			PlayerWins++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWins++;
		else
			Draw++;

		Print_Round_Result(RoundInfo);
	}
	return Get_Game_Result(Rounds, PlayerWins, ComputerWins, Draw);
}

string Tabs(int HowManyTabs)
{
	string t = "";
	for (int i = 1; i <= HowManyTabs; i++)
	{
		t = t + "\t";
		cout << t;
	}
	return t;
}

void Show_Game_Over_Screen()
{
	cout << Tabs(2) << "__________________________________________________________\n\n";
	cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";
	cout << Tabs(2) << "__________________________________________________________\n\n";
}

void Show_final_Result(stGameResult FinalGameResult)
{
	cout << Tabs(2) <<"_____________________ [Game Results ]_____________________\n\n";
	cout << Tabs(2) << "Game Rounds        : " << FinalGameResult.Rounds << endl;
	cout << Tabs(2) << "Player1 won times  : " << FinalGameResult.PlayerWins << endl;
	cout << Tabs(2) << "Computer won times : " << FinalGameResult.ComputerWins << endl;
	cout << Tabs(2) << "Draw times         : " << FinalGameResult.Drawtimes << endl;
	cout << Tabs(2) << "Final Winner       : " << FinalGameResult.GameWinnerName << endl;
	cout << Tabs(2) << "___________________________________________________________\n";

	Set_Screen_Color(FinalGameResult.GameWinner);
}

short How_Many_Rounds()
{
	short Game_Rounds = 0;
	do {
		cout << "How Many Rounds:\n";
		cin >> Game_Rounds;
	} while (Game_Rounds < 1 || Game_Rounds > 10);
	return Game_Rounds;
 }

void Reset_Screen()
{
	system("cls");
	system("Color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';
	do {
		Reset_Screen();
		stGameResult Game = PlayGame(How_Many_Rounds());
		Show_Game_Over_Screen();
		Show_final_Result(Game);

		cout << endl << "Do You Want To play Again? (y,n) : ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}