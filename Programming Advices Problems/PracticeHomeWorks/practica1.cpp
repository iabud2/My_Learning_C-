

#include <iostream>
using namespace std;

int main()
{
    cout << "+=========================================\n";
    cout << "+==    Calculate Your Age Apllication   ==\n";
    cout << "+=========================================\n";

    int age;
    cin >> age;

    int age_in_days = age * 365;
    int age_in_hours = age_in_days * 24;
    int age_in_min = age_in_hours * 60;
    int age_in_sec = age_in_min * 60;
    cout << "Age in\nDays : " << age_in_days << " days\n";
    cout << "hours : " << age_in_hours << " hours\n";
    cout << "Minutes : " << age_in_min << " Minutes\n";
    cout << "Seconds : " << age_in_hours << " Seconds\n";
    return 0;
} 