#include <iostream>
using namespace std;

class clsA
{
public:
    int Var;
    static int counter;
    clsA()
    {
        counter++;
    }
    void Print()
    {
        cout << "\nVar : " << Var << endl;
        cout << "Counter : " << counter << endl;
    }
};
int clsA::counter = 0;
int main()
{
    clsA A1, A2, A3;
    A1.Var = 10;
    A2.Var = 20;
    A3.Var = 30;
    
    A1.Print();
    A2.Print();
    A3.Print();

    A1.counter = 500;

    A1.Print();
    A2.Print();
    A3.Print();

    return 0;
}