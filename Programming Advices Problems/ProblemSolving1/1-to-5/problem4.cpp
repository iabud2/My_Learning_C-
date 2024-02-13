/* Problem 4 :
Write a program to ask the user to enter his / her :
• Age
• Driver license
 */
#include <iostream>
using namespace std;
struct stInfo
{
    int age;
    bool Has_Driver_License;
};

stInfo Read_Info()
{
    stInfo Info;

    cout << "How Old Are You:";
    cin >> Info.age;
    cout << "You Have Driver License";
    cin >> Info.Has_Driver_License;
    
    return Info; 
}

bool Is_Accepted(stInfo Info)
{
    
    return(Info.age > 21 && Info.Has_Driver_License);
}

void print_Result(stInfo Info)
{

    if (Is_Accepted(Info))
    {
        cout << "congrat You Hired !";
    }
    else
    {
        cout << "Sorry Rejected";
    }
}

int main()
{
    print_Result(Read_Info());
    return 0;
}