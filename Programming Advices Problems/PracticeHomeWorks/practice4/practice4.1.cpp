#include <iostream>
using namespace std;
int main()
{
    string Name;
    int Age;
    string City;

    int Monthly_salary;
    int yearly_salary;
    char Gender;
    bool Married;
    cout << "Enter Your Name :\n";
    cin >> Name;
    cout << "Enter Your Age :\n";
    cin >> Age ;
    cout << "What Is Your City :\n";
    cin >> City ;
    cout << "How much Money You Make Per Month?\n";
    cin >> Monthly_salary;
    cout << "What Is Your Gender M Male or F Female\n";
    cin >> Gender ;
    cout <<"Married Or Not : 1 If Yes And 0 If not\n";
    cin >> Married;
    cout << Name<< endl << Age <<" Years";
    cout << City<< endl << Monthly_salary<<endl;
    cout << yearly_salary <<endl<<Gender<<endl;
    cout << Married;
    return 0;
}


//-------------------------------------------------------
