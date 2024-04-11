#include <string>
#include <iostream>
using namespace std;

class Person
{

//this is Private Members only Can use inside the class
private:
    int Variable1 = 10, Variable2 = 20;
    
    string Function1()
    {
        return to_string(Variable1 + Variable2);
    }

// this is Public Members Can use it inside the class or outside the class
public:
    string FirstName;
    string LastName;
    
    string FullName()
    {
        return FirstName + " " + LastName + " Number from private class is :"  + Function1() ;    
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