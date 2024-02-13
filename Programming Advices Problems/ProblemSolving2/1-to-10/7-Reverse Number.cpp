#include <iostream>
using namespace std;

int  Read_Number()
{
    int Number = 0;
    cout << "Enter The Number:\n";
    cin >> Number;
    return Number;
}

void Get_Reverse_Numbers(int N)
{
    int Remainder = 0, Reversed = 0;
    cout << "Reverse_Number =\n";
    while (N > 0)
    {
        Remainder = N % 10;
        N /= 10;
        Reversed = Reversed * 10 + Remainder;
    
    }
    cout << Reversed;
}

int main()
{
    Get_Reverse_Numbers(Read_Number());
    return 0;
}