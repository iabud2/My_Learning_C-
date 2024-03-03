// solving problems  42
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout << "Enter The task Dration :\n";
    short int  Days;
    cout <<"Days : ";
    cin>> Days;
    short int hours;
    cout<<"hours : ";
    cin >> hours;
    short int minutes;
    cout << "minutes : ";
    cin >> minutes;
    short int seconds;
    cout << "Seconds :";
    cin >> seconds;
    
    int dur_in_hours = Days * 24 + hours;
    int dur_in_min = dur_in_hours * 60 + minutes ;
    int dur_in_seconds = dur_in_min * 60 + seconds;
    cout << round(dur_in_seconds);
    return 0;

}