/*
Problem 6:
Write a program to ask the user to enter:
• First Name
• Last Name
*/
#include <iostream>
using namespace std;


struct stName
{
    string F_Name;
    string L_Name;
};

stName Read_Name()
{
    stName Name;
    cout << "First Name:\n";
    cin >> Name.F_Name;
    cout << "Last Name:\n";
    cin >> Name.L_Name;

    return Name;
}

string Full_Name(stName Name, bool reversed){
    string FullName = "";
    if (reversed)
        {FullName =   Name.L_Name + " " + Name.F_Name;}
    else 
        {FullName =  Name.F_Name + " " + Name.L_Name; }

    return FullName;
}

void Print_Name(string FullName){

    cout << FullName;
    
}

int main(){

    Print_Name(Full_Name(Read_Name(), 1));
    return 0;
}
