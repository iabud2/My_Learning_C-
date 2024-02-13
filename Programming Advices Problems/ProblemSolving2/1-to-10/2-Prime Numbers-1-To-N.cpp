#include <iostream>
#include <cmath>
using namespace std;

enum enNumberType
{
    Prime = 1, NotPrime = 2
};


int Read_Positive_Number()
{
    int number = 0;
    do {
        cout << "Please Enter Positive Number:\n";
        cin >> number;
    } while (number <= 0);
    return number;
}
enNumberType checkPrime(int Number)
{
    int H = round(Number / 2);
    for (int i = 2; i <= H; i++)
    {
        if (Number % i == 0)
        {
            return enNumberType::NotPrime;
        }
    }
        return enNumberType::Prime;
}

void Print_Prime_Number(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        if (checkPrime(i) == enNumberType::Prime)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    Print_Prime_Number(Read_Positive_Number());
    return 0;
}