#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

enum enOperationType
{
	Add = 1, subtract = 2, Multiply = 3, Divine = 4, Mix = 5
};
enum enQuizzLevel
{
	Easy = 1, Med = 2, Hard = 3, MixL = 4
};
struct stQuestions
{
	int Number1 = 0;
	int Number2 = 0;
	enQuizzLevel Q_Level;
	enOperationType O_Type;
	int Answer = 0;
	int PlayerAnswer = 0;
	bool Result = false;
};
struct stQuizz
{
	int NumberOfQuestions = 0;
	int RightAnswers = 0;
	int WrongAnswers = 0;
	stQuestions Questions[100];
	enQuizzLevel QuesitonsLevel;
	enOperationType OperationType;
	bool isPass = false;
};

enOperationType ReadOperationType()
{
	int OpType = 0;
	do {
		cout << "Enter operation Type [1] Sum, [2] Subtract, [3] Multiply, [4] Divine, [5] Mix : \n";
		cin >> OpType;
	} while (OpType < 1 || OpType > 5);
	return (enOperationType)OpType;
}

enQuizzLevel ReadQuizzLevel()
{
	int Q_Level;
	do {
		cout << "Enter Quizz Level [1] Easy, [2] Med, [3] Hard, [4] Mix :\n";
		cin >> Q_Level;
	} while (Q_Level < 1 || Q_Level > 4);
	return (enQuizzLevel)Q_Level;
}

int Random_Number(int from, int to)
{
	int Randint = rand() % (to - from + 1) + from;
	return Randint;
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return Number1 + Number2;
		break;
	case enOperationType::subtract:
		return Number1 - Number2;
		break;
	case enOperationType::Multiply:
		return Number1 * Number2;
		break;
	case enOperationType::Divine:
		return Number1 / Number2;
		break;
	}
}

string QuizzLevelName(enQuizzLevel QuizzLevel)
{
	string arrQuizzLevelName[4] = { "Easy", "Med", "Hard", "Mix" };
	return arrQuizzLevelName[QuizzLevel - 1];
}

string QuestionOperationSymplo(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::subtract:
		return "-";
	case enOperationType::Multiply:
		return "*";
	case enOperationType::Divine:
		return "/";
	default:
		return "Mix";
	}
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void ScreenColor(bool Status)
{
	if (Status)
	{
		system("color 2F");
	}
	else
	{
		cout << "\a";
		system("color 4F");
	}
}

enOperationType MixOperations()
{
	int Op_T = Random_Number(1, 4);
	return enOperationType(Op_T);
}

int HowManyQuestions()
{
	int Number = 0;
	do {
		cout << "Enter How Many Questions Do You Want To Answer ? ";
		cin >> Number;

	} while (Number <= 0);
	return Number;
}

stQuestions GetQuestion(enOperationType Type, enQuizzLevel Level)
{
	stQuestions Question;
	if (Type == enOperationType::Mix)
	{
		Type = MixOperations();
	}
	if (Level == enQuizzLevel::MixL)
	{
		Level = enQuizzLevel(Random_Number(1, 3));
	}
	
	Question.O_Type = Type;
	
	switch (Level)
	{
	case enQuizzLevel::Easy:
		Question.Number1 = Random_Number(1, 9);
		Question.Number2 = Random_Number(1, 9);
		Question.Answer = SimpleCalculator(Question.Number1, Question.Number2, Question.O_Type);
		Question.Q_Level = Level;
		return Question;
	case enQuizzLevel::Med:
		Question.Number1 = Random_Number(10, 49);
		Question.Number2 = Random_Number(10, 49);
		Question.Answer = SimpleCalculator(Question.Number1, Question.Number2, Question.O_Type);
		Question.Q_Level = Level;
		return Question;
	case enQuizzLevel::Hard:
		Question.Number1 = Random_Number(50, 100);
		Question.Number2 = Random_Number(50, 100);
		Question.Answer = SimpleCalculator(Question.Number1, Question.Number2, Question.O_Type);
		Question.Q_Level = Level;
		return Question;
	}

	return Question;
}

int UserAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

void GetQuizz(stQuizz &Quizz)
{
	for (int Question = 0; Question < Quizz.NumberOfQuestions; Question++)
	{
		Quizz.Questions[Question] = GetQuestion(Quizz.OperationType, Quizz.QuesitonsLevel);
	}
}

void PrintQuestion(stQuizz &Quizz, int QuestionNumber)
{
	cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
	cout << Quizz.Questions[QuestionNumber].Number1 << endl;
	cout << Quizz.Questions[QuestionNumber].Number2;
	cout << "\t" << QuestionOperationSymplo(Quizz.Questions[QuestionNumber].O_Type);
	cout << "\n------------\n\n";
}	

void CorrectTheAnswer(stQuizz& Quizz, int QuestionNumber)
{
	if (Quizz.Questions[QuestionNumber].PlayerAnswer != Quizz.Questions[QuestionNumber].Answer)
	{
		Quizz.Questions[QuestionNumber].Result = false;
		cout << "Wrong Answer\n";
		cout << "Right Answer is : " << Quizz.Questions[QuestionNumber].Answer << endl;
		Quizz.WrongAnswers++;
	}
	else
	{
		Quizz.Questions[QuestionNumber].Result = true;
		cout << "Right Answer \n\n";
		Quizz.RightAnswers++;
	}
	ScreenColor(Quizz.Questions[QuestionNumber].Result);
}

void Ask_And_Correct_Each_Question(stQuizz &Quizz)
{
	for (int Question = 0; Question < Quizz.NumberOfQuestions; Question++)
	{
		PrintQuestion(Quizz, Question);
		Quizz.Questions[Question].PlayerAnswer = UserAnswer();
		CorrectTheAnswer(Quizz, Question);
	}
	Quizz.isPass = (Quizz.RightAnswers >= Quizz.WrongAnswers);
}

string GetFinalResult(bool isPassOrNot)
{
	if (isPassOrNot)
	{
		system("color 2F");
		return "Pass";
	}
	else
	{
		system("color 4F");
		return "Faild";
	}
}

void PrintQuizzResults(stQuizz Quizz)  
{  
		cout << "\n";      
		cout << "______________________________\n\n"; 
		cout << " Final Resutls is " << GetFinalResult(Quizz.isPass);     
		cout << "\n______________________________\n\n"; 
		cout << "Number of Questions: " << Quizz.NumberOfQuestions << endl;      
		cout << "Questions Level    : " << QuizzLevelName(Quizz.QuesitonsLevel) << endl;      
		cout << "OpType             : " << QuestionOperationSymplo(Quizz.OperationType) << endl;
		cout << "Number of Right Answers: " << Quizz.RightAnswers << endl;
		cout << "Number of Wrong Answers: " << Quizz.WrongAnswers << endl;      
		cout << "______________________________\n"; 
}
void PlayMathGame()
{
	stQuizz Quizz;
	Quizz.NumberOfQuestions = HowManyQuestions();
	Quizz.OperationType = ReadOperationType();
	Quizz.QuesitonsLevel = ReadQuizzLevel();
	
	GetQuizz(Quizz);
	Ask_And_Correct_Each_Question(Quizz);
	PrintQuizzResults(Quizz);
}

void StartGame()
{
	char PlayAgain = 'Y';
	do {
		ResetScreen();
		PlayMathGame();
		cout << "\nyou want to play again? [y/n]? ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}