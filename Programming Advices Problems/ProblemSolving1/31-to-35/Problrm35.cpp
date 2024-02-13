/*
Problem 35:
Write a program to ask the user to enter: 
• Pennies, Nickels, Dimes, Quarters, Dollars

Then calculate the total pennies , total dollars and print them on screen

giving that:
• Penny = 1
• Nickel = 5
• Dime = 10
• Quarter = 25
• Dollar = 100
*/
#include <iostream>
using namespace std;
struct stPiggy_Bank
{
    int Penny, Nickel , Dime, Quarter , Dollar;
};

stPiggy_Bank Read_Money()
{
    stPiggy_Bank Money;
    cout << "Enter Pennies:\n";
    cin >> Money.Penny;
    cout << "Enter Nickels:\n";
    cin >> Money.Nickel;
    cout << "Enter Dimes:\n";
    cin >> Money.Dime;
    cout << "Enter Quarters:\n";
    cin >> Money.Quarter;
    cout << "Enter Dollars:\n";
    cin >> Money.Dollar;
    return Money;
}


float Calculate_Piggy_Bank(stPiggy_Bank Money)
{
    float TotalMoney = Money.Penny * 1 + Money.Nickel * 5
                        + Money.Dime * 10 + Money.Quarter *25
                        + Money.Dollar * 100;
    return TotalMoney;
}

void print_Money(float Money)
{
    string choice;


    do {
    cout << "You Need It by Dollars Or Pennies D/P?\n";
    cin >> choice;
    if (choice == "P"){
        cout << Money;
        break;
    }
    else if (choice == "D")
    {
        cout << Money / 100;
        break;
    }
    else {
        cout << "Wrong Input, ";
    }
    }while(choice != "D" || choice !="P");
}

int main()
{
    print_Money(Calculate_Piggy_Bank(Read_Money()));
    return 0;
}