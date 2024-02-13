/*
Problem 25:
Write a program to ask the user to enter :
• Age
If age is between 18 and 45 print “Valid Age”,
otherwise print “Invalid Age” and re-ask user to enter a valid age.


Note: You should keep asking user to enter a valid age until s/she enters it.
*/
#include <iostream>
using namespace std;

int Read_Age()
{
    int Age;
    cout << "Enter Your Age :\n";
    cin >> Age;
    return Age;
}

bool Check_Age(int Age)
{
    return Age > 18 && Age < 45;
}

int Input_Until_Valid_age(int age)
{   
    
    while (!Check_Age(age)){
        cout << "Invalid Age!\n";
        age = Read_Age();
    };

    return age;
    
}
void PrintResult(int Age)
{
    if (Check_Age(Age))
        cout << "Valid Age";
}

int main()
{
    PrintResult(Input_Until_Valid_age(Read_Age()));
    return 0;
}