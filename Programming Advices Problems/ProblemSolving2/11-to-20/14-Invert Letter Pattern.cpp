#include <iostream>
using namespace std;

/*
//My sol


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

void Inverted_Askii_Patterns(int number)
{

    for (int i = number; i >= 1; i--)
    {
        for (int j = 1; j  <= i; j++)
        {   

            cout << char(i + 64);

        }
        cout << endl;
    }
}

int main()
{
    Inverted_Askii_Patterns(Read_Number("Enter a Positive number:\n"));
    return 0;
}
*/


 
int ReadPositiveNumber(string Message) 
{   int Number = 0; 
    do    
    {         
        cout << Message << endl;         
        cin >> Number;     
    } while (Number <= 0); 
    return Number; 
} 
void PrintInvertedLetterPattern(int Number) 
{     
    cout << "\n"; 
    for (int i = 65 + Number - 1; i >= 65; i--)         
    {   
        for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)         
        {             
            cout << char(i);         
        }         
    cout << "\n";     
    } 
} 
int main() 
{     
    PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positive number?")); 
    return 0; 
}
