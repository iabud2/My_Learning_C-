#include <iostream>
using namespace std;

class clsA
{
    int B;

public:
    static int Function1()
    {
        return 5;
    }
    int Function2()
    {
        return 10;
    }
};

int main()
{
    cout << clsA::Function1() << endl;
    // cannot call Function1 after declare object beacause it's not Static Function.
    clsA A;
    cout << A.Function1() << endl;
    cout << A.Function2() << endl;
    return 0;
}