
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

void Askii_Patterns(int number)
{

    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            cout << char(i + 64);

        }
        cout << endl;
    }
}

int main()
{
    Askii_Patterns(Read_Number("Enter a Positive number:\n"));
    return 0;
}