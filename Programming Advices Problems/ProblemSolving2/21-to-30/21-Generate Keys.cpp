#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
/*
//My Solution


int Read_Positive_Number(string message)
{
    int Number = 0;
    do {
        cout << message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int Get_Random_Key()
{
    int from = 65, to = 90;
    int	random_num = rand() % (to - from + 1) + from;
    return random_num;
}


void  get_key_times()
{
    string Part = "";
    int G = 4;
    while (G > 0)
    {
        for (int i = 4; i > 0; i--) 
        {
            Part = Part + char(Get_Random_Key());
        }
        if (G == 1)
            cout << Part;
        else
            cout << Part<<"-";
        Part = "";
        G--;
    }
        
}


void Print_Keys(int count)
{
    for (int i = 1; i <= count; i++)
    {
        cout << "Key Number [" << i << "] :"; 
        get_key_times();
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    Print_Keys(Read_Positive_Number("How Many keys You Want To Generate?\n"));
    return 0;
}
*/


//Teacher Solution:

enum enRandom {
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharactter = 3,
    Digit = 4
};

int Read_Positive_Number(string message)
{
    int Number = 0;
    do {

        cout << message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}


int Random_Number(int from, int to)
{

    int	random_num = rand() % (to - from + 1) + from;
    return random_num;
}


char Get_Random_Type(enRandom Type)
{
    switch (Type) 
    {

    case enRandom::SmallLetter:
        {
            return char(Random_Number(97, 122));
            break;
        }
    case enRandom::CapitalLetter:
        {   
            return char(Random_Number(65, 90));
            break;
        }
    case enRandom::SpecialCharactter:
        {
            return char(Random_Number(33, 47));
            break;
        }
    case  enRandom::Digit:
        {
            return char(Random_Number(48, 57));
            break;
        }
    }
}


string Generate_Word(enRandom Type)
{
    short Length = 4;
    string word = "";
    for (int i = 1; i <=Length; i++)
    {
        word = word + Get_Random_Type(Type);

    }
    return word;
}

string Generate_Key(enRandom Type)
{
    string key = "";
    for (int i = 1; i<=4; i++)
    {
        if (i == 4)
            key = key + Generate_Word(Type);
        else
            key = key + Generate_Word(Type) + "-";
    }
    return key;
}

void Print_Generated_Keys(int Amount)
{
    for (int i = 1; i<=Amount; i++)
    {
        cout << "Key Number [" << i << "] : ";
        cout << Generate_Key(enRandom::CapitalLetter)<< endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    Print_Generated_Keys(Read_Positive_Number("How Many Keys?\n"));
    return 0;
}