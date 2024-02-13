#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

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
    for (int i = 1; i <= Length; i++)
    {
        word = word + Get_Random_Type(Type);

    }
    return word;
}

string Generate_Key_Array(string arr[100], int Length)
{
    string Key = "";
    for (int i = 0; i < Length; i++)
    {
        Key = Key + Generate_Word(enRandom::CapitalLetter); +"-";
    }
    return Key;
}

void Put_Keys_in_Array(string arr[100], int &keyscount)
{
    int Length = 4;
    keyscount = Read_Positive_Number("How Many keys:\n");
    for (int i = 0; i <= keyscount; i++)
    {
        arr[i] = Generate_Key_Array(arr, Length);
    }

}

void Print_Array(string arr[100], int Keycount)
{

        for (int i = 0; i < Keycount; i++)
        {
            cout << "Key Number [" << i + 1 << "] : " << arr[i] << endl << endl;
        }
}


int main()
{
    srand((unsigned)time(NULL));
    string arr[100];
    int KeyCount = 0;
    Put_Keys_in_Array(arr, KeyCount);
    Print_Array(arr, KeyCount);
    return 0;
}