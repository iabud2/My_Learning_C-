#include <iostream>
#include <iomanip>
using namespace std;

int Read_Positive_Number(string message)
{
    short Number;
    do
    {
        cout << message;
        cin >> Number;
    } while (Number = 0);
    return Number;
}

void Fibinacci_Series(int Number)
{
    short Fib_Number = 0;
    cout << "1   ";
    short prev1 = 0, prev2 = 1;
    for (int i = 2; i <= Number; i++)
    {
        Fib_Number = prev1 + prev2;
        cout << setw(2) << Fib_Number << "   ";
        prev1 = prev2;
        prev2 = Fib_Number;
    }
}

int main()
{
    Fibinacci_Series(10);
    return 0;
}
