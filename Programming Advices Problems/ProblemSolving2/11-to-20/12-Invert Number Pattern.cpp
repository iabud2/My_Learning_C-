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

void InvertedPatterns(int number)
{
    for (int i = number; i>0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << i;
        }
        cout <<endl;
    }
}

int main()
{
    InvertedPatterns(Read_Number("Enter a Positive number:\n"));
    return 0;
}


/*
Teacher Solution

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
void PrintInvertedNumberPattern(intNumber) 
{     
        cout << "\n"; 
        for (int i = Number; i >= 1; i--)     
        { 
            for (int j = 1; j <= i; j++)        
            {             cout << i;         
            }         cout << "\n";     
        } 
} 
int main()
{
        PrintInvertedNumberPattern(ReadPositiveNumber("Please enter a positive number?")); 
        return 0;
 }
*/