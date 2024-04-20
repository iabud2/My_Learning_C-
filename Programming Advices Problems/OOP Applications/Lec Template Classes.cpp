#include <iostream>
using namespace std;

template <class T>
class Calculator
{
private:
    T Number1, Number2;

public:
    Calculator(T N1, T N2)
    {
        Number1 = N1;
        Number2 = N2;
    }

    void PrintResults()
    {
        cout << "Numbers: " << Number1 << " and " << Number2 << "." << endl;
        cout << Number1 << " + " << Number2 << " = " << Add() << endl;
        cout << Number1 << " - " << Number2 << " = " << Subtract() << endl;
        cout << Number1 << " x " << Number2 << " = " << Multibly() << endl;
        cout << Number1 << " / " << Number2 << " = " << Divide() << endl;
    }
    T Add()
    {
        return Number1 + Number2;
    }

    T Subtract()
    {
        return Number1 - Number2;
    }

    T Multibly()
    {
        return Number1 * Number2;
    }

    T Divide()
    {
        return Number1 / Number2;
    }
};

int main()
{
    Calculator<int> IntCalculator(10, 2);
    Calculator<float> FloatCalculator(10.10, 2.2);
    cout << "Int Calculator Results :" << endl;
    IntCalculator.PrintResults();
    cout << "Float Caculator Results : " << endl;
    FloatCalculator.PrintResults();

    return 0;
}