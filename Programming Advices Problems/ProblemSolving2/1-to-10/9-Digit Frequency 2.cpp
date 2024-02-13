#include <iostream>
using namespace std;

int Read_Number(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}


int counter(int N, int count)
{
    int Remainder = 0, counter = 0;

    while (N > 0)
    {
        Remainder = N % 10;
        N /= 10;
        if (count == Remainder)
            counter++;
    }
        return counter;
}

void Read_Frequency(int Numbers)
{
    for (int i = 0; i < 10; i++)  
    {
        int DigitCounter = counter(Numbers, i);
        if (DigitCounter != 0)
        {
            cout << "Digit " << i << "Was Repeated " << DigitCounter << "Time(s)\n";
        }
    }
}

int main()

{
    int X = Read_Number("Enter The Numbers:\n");
    int Y = Read_Number("Which Numbers You want To now how many times was repeated?\n");
    Read_Frequency(X);
    return 0;
}
