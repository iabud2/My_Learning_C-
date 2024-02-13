/*
Problem 5:
Write a program to ask the user to enter his/her:
• Age
• Driver license
• Has Recommendation!
*/
#include <iostream>
using namespace std;

struct stInfo
{
    int Age;
    bool Driver_License;
    bool Has_Recommendation;
};

stInfo Read_Info()
{   
    stInfo Info;
    cout << "How Old  Are you?\n";
    cin >> Info.Age;
    cout << "Do You Have Driver License?\n";
    cin >> Info.Driver_License;
    cout << "Has Any Recommendation?\n";
    cin >> Info.Has_Recommendation;
    return Info;
}

bool is_Accepted(stInfo Info)
{
    if (Info.Has_Recommendation)
    {
        return  true;
    }
    else 
    {
        return (Info.Age > 21 & Info.Driver_License);
    }
}

void Print_Result(stInfo Info)
{
    if (is_Accepted(Info))
    {
        cout << "Hired !";
    }
    else 
    {
        cout << "Rejected";
    }
}

int main()
{
    Print_Result(Read_Info());
    return 0;
}