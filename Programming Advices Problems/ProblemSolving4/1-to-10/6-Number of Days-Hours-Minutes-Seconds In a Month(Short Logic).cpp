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
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short Days_In_Month(int Year, int Month)
{

    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Months of 31 Days (1, 3 , 5, 7, 8, 10, 12)
    if (Month > 12 || Month <= 0)
    {
        return 0;
    }
    return((Month == 2)?(is_Leap(Year)?29:28):arr[Month - 1]);
}

short Hours_In_Year(int Year, int Month)
{
    return Days_In_Month(Year, Month) * 24;
}

int Minuts_In_Year(int Year, int Month)
{
    return Hours_In_Year(Year, Month) * 60;
}

int Seconds_In_Year(int Year, int Month)
{
    return Minuts_In_Year(Year, Month) * 60;
}

int main()
{
    int Year = Read_Number("Please Enter a Year to check ? \n");
    int Month = Read_Number("Enter a Month to Check : \n");
    cout << "Number of Days    in Month [" << Month << "] is " << Days_In_Month(Year, Month) << endl;
    cout << "Number of Hours   in Month [" << Month << "] is " << Hours_In_Year(Year, Month) << endl;
    cout << "Number of Minutes in Month [" << Month << "] is " << Minuts_In_Year(Year, Month) << endl;
    cout << "Number of Seconds in Month [" << Month << "] is " << Seconds_In_Year(Year, Month) << endl;
}