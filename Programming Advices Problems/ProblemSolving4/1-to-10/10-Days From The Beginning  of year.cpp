#include <iostream>
#include <cctype>
#include <iomanip>
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
    return ((Month == 2) ? (is_Leap(Year) ? 29 : 28) : arr[Month - 1]);
}

short Find_day(short Day, short month, short year)
{
    short A = (14 - month) / 12;
    short y = year - A;
    short m = month - (12 * A) - 2;
    short d = ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))) % 7;
    return d;
}

short Days_From_Beginning(short Day, short Month, short Year)
{
    short sum = 0;
    for (int i = 1; i < Month; i++)
    {
        sum += Days_In_Month(Year, i);
    }
    sum += Day;
    return sum;
}

int main()
{
    short Year = Read_Number("Enter The Year : ");
    short Month = Read_Number("Enter The Month :");
    short Day = Read_Number("Enter The Day :");
    printf("Number of Days From The Beginning of the year is : %d", Days_From_Beginning(Day, Month, Year));
    return 0;
}