#include <iostream>
using namespace std;

// Solving problems number 33, 34, 36, 44, 45;


//33.


// int main(){
//     int grade;
//     cout <<"Enter Your Grade:\n";
//     cin >> grade;
//     if (grade >=90 && grade<=100){
//         cout <<"Your Grade Is (A)";
//     }
//     else if (grade >=80 && grade<=89){
//         cout <<"Your Grade Is (B)";
//     }
//     else if (grade >=70 && grade<=79){
//         cout <<"Your Grade Is (C)";
//     }
//     else if (grade >=60 && grade<=69){
//         cout <<"Your Grade Is (D)";
//     }
//     else if (grade >=50 && grade<=59){
//         cout <<"Your Grade Is (E)";
//     }
//     else {
//         cout << "Your Grade Is (F)";
//     }

//     return 0;
// }


//-----------------------------------------------------

//34.

// int commision_Percentage(int sales_amount){

//     cout << "Enter Sales amount:\n";
//     cin>> sales_amount;
//     if (sales_amount >=1000000){
//         cout << "Percentage is 1%\n";
//         cout << "You will git "<< sales_amount * 0.01;
        
//     }
//     else if (sales_amount >=500000 && sales_amount < 1000000){
//         cout << "Perscentage is 2%\n";
//         cout << "You will git " << sales_amount * 0.02;
//     }
//     else if (sales_amount >=100000 && sales_amount < 500000){
//         cout << "Perscentage is 3%\n";
//         cout << "You will git " << sales_amount * 0.03;
//     }
//     else if (sales_amount >=50000 && sales_amount < 100000){
//         cout << "Perscentage is 5%\n";
//         cout << "You will git " << sales_amount * 0.05;
//     }
//     else {
//         cout << "Perscentage is 0%\n";
//         cout << "No commision this month ;( \n";
//     };
//     return sales_amount;

// }

// int main(){
//     int my_sales_amount;
//     cout << commision_Percentage(my_sales_amount);
//     return 0;
    
// }

// i was having problem here ,, The program print the salary amount after calculate commisiom;


//------------------------------------------------------


//36.

// struct stnumbers {
//     float num1;
//     float num2;
//     string operation_user;
// };

// void func_Read_Nums(stnumbers &numbers){
    
    
//     cout <<"Enter First Number:\n";
//     cin >> numbers.num1;
//     cout <<"Enter The Second Number:\n";
//     cin >> numbers.num2;
// }

// void func_operations(stnumbers nums){

    
//     cout << "Enter The Operation:\n";
//     cin >> nums.operation_user;

//     if (nums.operation_user == "+"){
//         cout << nums.num1 + nums.num2;
//     }
//     else if (nums.operation_user == "-"){
//         cout << nums.num1 - nums.num2;
//     }
//     else if (nums.operation_user == "*"){
//         cout << nums.num1 * nums.num2;
//     }
//     else if (nums.operation_user == "/"){
//         cout << nums.num1 / nums.num2;
//     }
//     else {
//         cout << "Invalid operation";
//     }
    

// }

// int main(){
//     stnumbers My_numbers;
//     My_numbers.num1;
//     My_numbers.num2;
//     My_numbers.operation_user;
//     func_Read_Nums(My_numbers);
//     func_operations(My_numbers);
//     return 0;

// }


//-------------------------------------------------------

//44.

// int main()
// {
//     int day;
//     cout << "Enter The number Of Day:\n";
//     cin >> day;
//     if (day == 1){
//         cout << "Sunday";
//     }
//     else if (day == 2){
//         cout << "Monday";
//     }
//     else if (day == 3){
//         cout << "Tuesday";
//     }
//     else if (day == 4){
//         cout << "Wendnesday";
//     }
//     else if (day == 5){
//         cout << "Thursday";
//     }
//     else if (day == 6){
//         cout << "Friday";
//     }
//     else if (day == 7){
//         cout << "Saturday";
//     }
//     else {
//         cout<<"Wrong Day";
//     }

//     return 0;
// }


//=======================================


//45.

// int main()
// {
//     int month;
//     cout << "Enter The number Of month:\n";
//     cin >> month;
//     if (month == 1)
//     {
//         cout << "Jenuary";
//     }
//     else if (month == 2)
//     {
//         cout << "February";
//     }
//     else if (month == 3)
//     {
//         cout << "Merch";
//     }
//     else if (month == 4)
//     {
//         cout << "Apri;";
//     }
//     else if (month == 5)
//     {
//         cout << "May";
//     }
//     else if (month == 6)
//     {
//         cout << "June";
//     }
//     else if (month == 7)
//     {
//         cout << "July";
//     }
//     else if (month == 8)
//     {
//         cout << "August";
//     }
//     else if (month == 9)
//     {
//         cout << "September";
//     }
//     else if (month == 10)
//     {
//         cout << "October";
//     }
//     else if (month == 11)
//     {
//         cout << "November";
//     }
//     else if (month == 12)
//     {
//         cout << "Devember";
//     }
//     else {
//         cout << "Wrong Month";
//     }

//     return 0;
// }
