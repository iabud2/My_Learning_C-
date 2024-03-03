#pragma warning(disable : 4996) 
#include<ctime>
#include<iostream>
using namespace std; 
int main()  
{ 
    time_t t = time(0);   
    char* dt = ctime(&t);   
    cout << "Local date and time is: " << dt << "\n";
    tm* gmtm = gmtime(&t);    
    dt = asctime(gmtm);    
    cout << "UTC date and time is: " << dt; 
} 