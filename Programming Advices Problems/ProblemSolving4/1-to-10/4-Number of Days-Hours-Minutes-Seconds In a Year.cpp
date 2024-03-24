#include <iostream>
#include <cctype>
using namespace std;

int Read_Number(string message)
{
    int Number = 0;
    do
    {
        cout << message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

bool is_Leap(int Year)
{
    // this
    //  return((Year % 400 == 0)?true:(Year % 100 == 0)?false:(Year % 4 == 0)?true:false);
    // or this
    return ((Year % 4 == 0 & Year % 100 != 0) || (Year % 400 == 0));
}

short Days_In_Month(int Year)
{
    return (is_Leap(Year) ? 366 : 365);
}

short Hours_In_Year(int Year)
{
    return Days_In_Month(Year) * 24;
}

int Minuts_In_Year(int Year)
{
    return Hours_In_Year(Year) * 60;
}

int Seconds_In_Year(int Year)
{
    return Minuts_In_Year(Year) * 60;
}

int main()
{
    int Year = Read_Number("Please Enter a Year to check ? \n");
    cout << "Number of Days    in Year [" << Year << "] is " << Days_In_Month(Year) << endl;
    cout << "Number of Hours   in Year [" << Year << "] is " << Hours_In_Year(Year) << endl;
    cout << "Number of Minutes in Year [" << Year << "] is " << Minuts_In_Year(Year) << endl;
    cout << "Number of Seconds in Year [" << Year << "] is " << Seconds_In_Year(Year) << endl;
}