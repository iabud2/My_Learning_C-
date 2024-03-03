#include <iostream>
#include <cmath>
using namespace std;

int MyPower(int Base, int Power)
{
    if (Power != 0)
    {
        return(Base * MyPower(Base, Power - 1));
    }
    else
    {
        return 1;
    }
}

int main() {

    cout << MyPower(2, 4);
    return 0;
}