#include <iostream>
using namespace std;

class clsCalculator
{

private:
    float _Result = 0;
    string _Operation = "";
    float _Previous_Result = 0;
    float _last_Number = 0;

    bool is_Zero(float Value)
    {
        return (Value == 0);
    }

public:
    void Clear()
    {
        _Operation = "Clear";
        _Previous_Result = _Result;
        _last_Number = 0;
        _Result = 0;
    }

    void Add(float Number)
    {
        _last_Number = Number;
        _Operation = "Adding";
        _Previous_Result = _Result;
        _Result += Number;
    }

    void Subtract(float Number)
    {
        _last_Number = Number;
        _Operation = "Subtracting";
        _Previous_Result = _Result;
        _Result -= Number;
    }

    void Divide(float Number)
    {
        _last_Number = Number;

        if (is_Zero(Number))
            Number = 1;

        _Operation = "Divide";
        _Previous_Result = _Result;
        _Result /= Number;
    }

    void Multibly(float Number)
    {
        _last_Number = Number;
        _Operation = "Multibly";
        _Previous_Result = _Result;
        _Result *= Number;
    }

    void CancelLastOperation()
    {
        _last_Number = 0;
        _Operation = "Cancel Last Operation";
    }

    int GetFinalResult()
    {
        return _Result;
    }

    void PrintResult()
    {
        if (_Operation != "Clear" || _Operation != "Cancel Last Operation")
        {
            cout << "\nResult After " << _Operation << " " << _last_Number << " is :" << _Result << endl;
        }
        else
        {
            cout << "\nResult After " << _Operation << " is :" << _Result << endl;
        }
    }
};

int main()
{
    clsCalculator Calculator1;

    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Subtract(2);
    Calculator1.PrintResult();

    Calculator1.Divide(0);
    Calculator1.PrintResult();

    Calculator1.Multibly(2);
    Calculator1.PrintResult();

    Calculator1.Clear();
    Calculator1.PrintResult();

    return 0;
}