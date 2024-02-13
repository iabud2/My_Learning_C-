// solving problem  43

#include <iostream>
#include <cmath>
using namespace std;


int main()
{   int seconds;
    cout <<"Enter The Seconds of The Task duration:\n";
    cin >> seconds;

    int sec_per_day = 24 * 60 *60;
    int seconds_per_hour = 60 * 60;
    int seconds_per_min = 60;

    float Num_of_days = round(seconds / sec_per_day);
    float remainder = seconds % sec_per_day;
    float Num_of_hours = round(remainder /seconds_per_hour);
    float remainder2 = seconds % seconds_per_hour;
    float Num_of_min = round(remainder2 / seconds_per_min);
    float remainder3 = seconds % seconds_per_min;
    cout <<Num_of_days<<":"<<Num_of_hours<<":"<<Num_of_min<<":"<<remainder3;
    return 0;
}