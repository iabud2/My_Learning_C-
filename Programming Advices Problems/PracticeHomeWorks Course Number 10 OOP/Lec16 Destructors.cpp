#include <iostream>
using namespace std;

class clsTest
{
public:
    clsTest()
    {
        cout << "\nHi, Iam Constructor\n";
    }
    ~clsTest()
    {
        cout << "Hi, Iam Destructor\n";
    }
};

void Fun1()
{
    clsTest Test1;
}

void Fun2()
{
    clsTest *Test = new clsTest;
    delete Test;
}

int main()
{
    Fun1();
    Fun2();
    system("pause>0");
    return 0;
}