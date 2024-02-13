//solving problems 1, 2, 14, 15, 16, 18, 19, 20, 21, 22, 23, 31, 32, 42, 43
#include <iostream>
#include <string>
#include<cmath>
using namespace std; 
//1

// void my_name(string name)
// {
//     cout << name ;
// }

// int main()
// {
//     string name = "Abdullah";
//     my_name(name);
// }


//-------------------------------------

//2 

// void ename(string name)
// {
//     cout<<"Hello "<<name;
// }

// int main()
// {
//     string name;
//     cout << "Enter Your Name:\n";
//     cin.ignore(1, '\n');
//     getline(cin, name);
//     ename(name);
    
//     return 0;
// }

//----------------------------------------------


//14

// int swap_func(int num1, int num2)
// {
//     return num2 , num1;
// }

// int main()
// {
//     int num1, num2;
//     cout << "enter the first number: \n";
//     cin >> num1;
//     cout << "enter the second number: \n";
//     cin >> num2;

//     cout << swap_func(num1, num2);
//     return 0 ;


// }

//------------------------------------------------

//15

// int rectangle_area(float a , float b)
// {
//     return a * b ;
// }

// int main()
// {
//     float a;
//     cout << "Enter the hieght value :\n";
//     cin >> a;
//     float b;
//     cout << "Enter the width value :\n";
//     cin >> b;

//     cout << rectangle_area(a, b);
//     return 0 ;
// }

//-----------------------------------------------

//16

// float rectangle_area2(float a, float d){
//     return a * sqrt(pow(d, 2) - pow(a,2));
// }


// int main()
// {
//     float a, d;
//     cout << "Enter The value of the side area:\n";
//     cin >> a;
//     cout << "Enter The Diagonal:\n";
//     cin >> d;
//     cout << rectangle_area2(a, d);
//     return 0;
// }



//--------------------------------------------------


//18

// float circle_area(float r)
// {
//     const float PY = 3.14;
//     return PY * pow(r , 2);
// }

// int main()
// {
//     float r;
//     cout << "Enter half of The diagonal:\n";
//     cin >> r;
//     cout << circle_area(r);
//     return  0;

// }

//---------------------------------------------------

//19

// float circle_area2(float D)
// {
//     const float PY = 3.14;
//     return (PY * pow(D, 2))/4;
// }


// int main()
// {
//     float D;
//     cout <<"Enter The Diagonal\n";
//     cin >> D;
//     cout << circle_area2(D);
//     return 0;
// }


//---------------------------------------

//20

// float circle_area3 (float A)
// {
//     const float PY = 3.14;
//     return (PY * pow(A, 2))/4 ;
// }

// int main()
// {
//     float A;
//     cout << "Enter The value of any square sides:\n";
//     cin >> A;
//     cout << circle_area3(A);
//     return 0;
// }

//----------------------------------------

//21

// float circle_area_cir(float L)
// {
//     const float PY = 3.14;
//     return (pow(L, 2)/(4 * PY));
// }

// int main()
// {
//     float L;
//     cout << "Enter The circumference value:\n";
//     cin >> L;
//     cout << circle_area_cir(L);
// }

//-------------------------------------------

//22

// float circle_area_iso_tri(float a, float b)
// {
//     const float PY = 3.14;
//     return (PY*pow(b,2)/4)*((2*a -b )/(2*a + b));
// }

// int main()
// {
//     float a, b;
//     cout << "Enter the values of the triangle side:\n";
//     cin >> a;
//     cin >> b;
//     cout << circle_area_iso_tri(a, b);
//     return 0;
// }

//----------------------------------------------

//23

// float circle_area_ins_tri(float a, float b, float c)
// {   
//     const float PY = 3.14;
//     float P = (a+b+c)/2;
//     float area = PY * pow((a * b * c )/(4 * sqrt(P * (P-a) * (P-b) * (P-c))), 2);
//     return area;
// }

// int main()
// {
//     float a, b ,c;
//     cout << "Enter THe triangle sides valyes:\n";
//     cin >> a;
//     cin >> b;
//     cin >> c;
//     cout << circle_area_ins_tri(a, b ,c);
//     return 0;
// }


//----------------------------------------------

//31

// void power()
// {
//     int num;
//     cout << "Enter The Number :\n";
//     cin >> num;
//     cout << pow(num, 2) << "\n";
//     cout << pow(num, 3) << "\n";
//     cout << pow(num, 4) << "\n";
// }

// int main()
// {
//     power();
//     return 0;
// }


//-----------------------------------------------

//32 
// int func_power(int num, int m)
// {
//     return pow(num, m);
// }

// int main()
// {
//     int number;
//     cout << "Enterr The Number:\n";
//     cin >> number;
//     cout << "Enter the Power:\n";
//     int power;
//     cin >> power;
//     cout << func_power(number, power);
//     return 0;

// }

//---------------------------------------------------


//42

// int task_dur(float days, float hours, float minutes, float seconds)
// {
//     int sec_of_day = days * 24 * 60 * 60;
//     int sec_of_hours = hours * 60 *60;
//     int sec_of_min = minutes * 60;
//     return sec_of_day + sec_of_hours + sec_of_min + seconds; 
// }

// int main()
// {
//     int days;
//     cout << "Enter The number or the days;\n";
//     cin >> days;
//     int hour;
//     cout << "Enter The Number of The Hours:\n";
//     cin >> hour;
//     int min;
//     cout << "Enter The Number of minutes:\n";
//     cin >> min;
//     int sec;
//     cout << "Enter The Seconds:\n";
//     cin >>  sec;
//     cout << task_dur(days, hour, min, sec);
//     return 0;
// }

//---------------------------------------------------

//43


// void task_dur2()
// {
//     int sec_num;
//     cout<< "Enter The Seocnds\n";
//     cin >> sec_num ;
//     int  day = 24 * 60 *60;
//     int hour = 60 * 60;
//     int min = 60;
//     int  day_in_sec = floor(sec_num / day);
//     int  reminder = sec_num % day;
//     int  hour_in_sec = floor(reminder/hour);
//     int reminder2 = sec_num % hour;
//     int min_in_sec = floor(reminder2 / min);
//     int reminder3 = sec_num % min;

//     cout << day_in_sec<< ":" << hour_in_sec << ":"<<min_in_sec<<":"<<reminder3;

// }

// int main(){

//     task_dur2();
//     return 0 ;
// }