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

int counter(int N)
{
    int Remainder = 0, reversed = 0;

    while (N > 0)
    {
        Remainder = N % 10;
        N /= 10;
        reversed = reversed * 10 + Remainder;
    }
    return reversed;
}

void normal_Number(int Number)
{
    cout << "Your Number is :\n";
    cout << counter(Number);
}
    
int main()
{
    normal_Number(counter(Read_Number("enter a posititve number:\n")));

    return 0;
}
