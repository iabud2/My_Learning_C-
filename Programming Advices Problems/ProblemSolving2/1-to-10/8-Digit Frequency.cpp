//My solution
/*
#include <iostream>
using namespace std;

int  Read_Number(string message)
{
    int Number = 0;
    cout << message;
    cin >> Number;
    return Number;
}
void counter(int N, int count)
{
    int Remainder = 0, counter = 0;

    cout << "Reverse_Number =\n";
    while (N > 0)
    {
        Remainder = N % 10;
        N /= 10;
        if (count == Remainder)
            counter++;

    }
    cout << count << " Was Repeated" << counter << " Times";
}
int main()
{
    int X = Read_Number("Enter The Numbers:\n");
    int Y = Read_Number("Which Number You want To now how many times was repeated?\n");
    counter(X, Y);
    return 0;
}
*/

//teacher solution
#include<iostream>
using namespace std; 
int ReadPositiveNumber(string Message) 
{ 
    int Number = 0; 
    do    
    {         
        cout << Message << endl;         
        cin >> Number;     
    } while (Number <= 0); 
    return Number; 
} 
int CountDigitFrequency(short DigitToCheck, int Number) 
{ 
    int FreqCount = 0, Remainder = 0; 
    while (Number > 0)     
    {         
        Remainder = Number % 10; 
        Number = Number / 10; 
        if (DigitToCheck == Remainder)         
        {             
            FreqCount++;         
        }    
    } 
    return FreqCount; 
} 

int main() 
{ 
    int Number = ReadPositiveNumber("Please enter the main number?"); 
    short DigitToCheck = ReadPositiveNumber("Please enter one digit to check?");     
    cout << "\nDigit " << DigitToCheck << " Frequency is " << CountDigitFrequency(DigitToCheck, Number) << " Time(s).\n"; 
    return 0; }