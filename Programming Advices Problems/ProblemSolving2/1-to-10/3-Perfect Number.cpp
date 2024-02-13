

#include <iostream>
#include <cmath>
using namespace std;



int Read_Number()
{
    int number = 0;
    do {
        cout << "Please Enter Positive Number:\n";
        cin >> number;
    } while (number <= 0);
    return number;
}

int Do_Operations(int number)
{
    int sum = 0;
    int H = round(number / 2);

    for (int i = 1; i < number; i++) 
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

bool check_Perfect_Or_Not(int Num)
{
    if (Do_Operations(Num) == Num)
    {
        return true;
    }
    else
        return false;
}

void Read_Result(int num)
{
    if (check_Perfect_Or_Not(num))
        cout << num << " Is a Perfect Number";
    else
        cout << num << " Not a Perfect Number";
}

int main()
{
    Read_Result(Read_Number());
    return 0;
}