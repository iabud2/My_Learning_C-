/*
Problem 33:
Write a program to ask the user to enter:
• Grade


Then print the grade as follows: 
• 90 – 100 Print A
• 80 – 89 Print B
• 70 – 79 Print C
• 60 – 69 Print D
• 50 - 59 Print E
• Otherwise Print F

*/
#include <iostream>
using namespace std;

int Read_Greade()
{
    int Grade;
    do {
        cout << "Enter The Grade:\n";
        cin >> Grade;
    }while ( Grade < 0 || Grade > 100);

    return Grade;  
}

string Read_Grade_Letter(int Grade)
{
    if (Grade >= 90)
        return "A";
    else if (Grade >= 80)
        return "B";
    else if (Grade >= 70)
        return "C";
    else if (Grade >= 60)
        return "D";
    else if (Grade >= 50)
        return "E";
    else 
        return "F";
}

void Print_Grade_Letter(string Grade)
{

    cout << "Yout Grade is : "<< Grade;
}

int main()
{
    Print_Grade_Letter(Read_Grade_Letter(Read_Greade()));
    return 0;
}