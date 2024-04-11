#include <iostream>
using namespace std;

class Person
{

public:
    string FirstName;
    string LastName;
    
    string FullName()
    {
        return FirstName + " " + LastName;    
    }
};

int main()
{
    Person Person1;
    Person1.FirstName = "Mohammed";
    Person1.LastName = "Ahmed";
    cout << Person1.FullName();
    
    
    return 0; 
}