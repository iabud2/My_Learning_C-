#include <iostream>
using namespace std;

int Read_Number(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int is_Palindrome(int N)
{
    int Remainder = 0, reversed = 0;

    while (N > 0)
    {
        Remainder = N % 10;
        N /= 10;
        reversed = reversed * 10 + Remainder;
    }
    return reversed;
}

void Print_Result(int Number)
{
        if (is_Palindrome(Number) == Number)
        {
            cout << Number << " is a Plalindrome Number";
        }
        else 
        {
            cout << Number << " Not a Plalindrome Number";
        }
}

int main()
{
    Print_Result(Read_Number("enter a posititve number:\n"));

    return 0;
}

/*
 Teacher solution

#include<iostream>
#include<string>
usingnamespace std; 

int ReadPositiveNumber(stringMessage) 
{ 
    int Number = 0; 
    do    
    {         
        cout << Message << endl;         
        cin >> Number;     
    } while (Number <= 0); 
    return Number; 
} 
int ReverseNumber(intNumber) 
{ 
    int Remainder = 0, Number2 = 0; 
    while (Number > 0)     
    { 
        Remainder = Number % 10; 
        Number = Number / 10;         
        Number2 = Number2 * 10 + Remainder;     
    } return Number2;
} 
bool IsPalindromeNumber(intNumber) 
{ 
    returnNumber == 
    ReverseNumber(Number); 
}
int main() 
{ 
    if (IsPalindromeNumber(ReadPositiveNumber("Please enter a positive number?")))         
        cout << "\nYes , it is a Palindrome number.\n"; else        
        cout << "\nNo , it is NOT a Palindrome number.\n"; 
        return 0; 
}
*/
