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

void Fibonacci_Series(int Number, int prev1, int prev2)
{

    short Fib_Number = 0;
    if (Number > 0)
    {
        Fib_Number = prev1 + prev2;
        cout << setw(2) << Fib_Number << "   ";
        prev1 = prev2;
        prev2 = Fib_Number;
        Fibonacci_Series(Number - 1, prev1, prev2);
    }
}

int main()
{
    Fibonacci_Series(10, 0, 1);
    return 0;
}
