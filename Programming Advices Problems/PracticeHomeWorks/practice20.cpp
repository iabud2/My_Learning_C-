// Solve Problems 26, 27 28 29, 30, 32. 46
#include <iostream>
#include <cmath>
using namespace std;



//26.


// void Loop_numbers(int y){
//     cout << "Loop:\n";
//     for (int x = 1; x <= y; x++)
//     {
//         cout << x << endl;
//     }
// }
// int main(){

//     int y;
//     cout << "Enter A number:\n";
//     cin >> y;

//     Loop_numbers(y);

//     return 0;
// }

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
// 27

// void Loop_numbers2(int y)
// {
//     cout << "Loop:\n";
//     for (int x = y; x >=1; x--)
//     {
//         cout << x << endl;
//     }
// }
// int main()
// {

//     int y;
//     cout << "Enter A number:\n";
//     cin >> y;

//     Loop_numbers2(y);

//     return 0;
// }

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


//28.

// int fnum(int x){
//     cout << "Enter A Number:\n";
//     cin >> x;
//     return x;
// }


// void  summ(int x){

//     int sum = 0;
//     for (int i = 1; i<=x; i++){
//         if (i % 2 != 0){
//             sum += i;
//         }
//         else{
//             i++;
//         }
//     }
//     cout << sum;

// }



// int main (){
//     int P;
//     fnum(P);
//     summ(P);
//     return 0;
// }

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


//29

// void sum_odd(int y)
// {   
//     int summ_odds = 0;
//     for (int x=1 ; x <= y ; x++)
//     {
//         if (x % 2 == 0)
//         {
//             summ_odds += x ;
//         }
// }
//     cout << summ_odds;
// }

// int main (){
//     int number;
//     cout << "Please Enter a Number:\n";
//     cin >> number;
//     sum_odd(number);
//     return 0;
// }

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


//30.

// void func_fact(){
//     int my_num;
//     int factorial = 1;
//     cout << "Enter The number:\n";
//     cin >> my_num;
//     if (my_num <= 0){
//         cout << "Enter A Positive number;\n";
//     }
//     else {
//     for (int i = 1; i <= my_num ; i++ ){
//         factorial *= i;
//     }}
//     cout << factorial;
// }

// int main()
// {
//     func_fact();
//     return 0;
// }

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//32.

// void Pow_Of_M(){
//     int num;
//     int m;
//     int power = 1;
    
//     cout  << "Enter The  Number:\n";
//     cin >> num;
//     cout << "Enter The Power:\n";
//     cin >> m;
//     cout << "----------------------------------\n";
//     for (int i = 0; i <= m; i++)
//     {   
//         cout << pow(num , i)<< endl;
//     }
// }

// int main()
// {
//     Pow_Of_M();
//     return 0;
// }

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


//46.

// void conversion_condition( ){
//     int B ;
//     for (B=65; B <90; B++){
//         cout << char(B)<<endl;
//     }
// }


// void conversion_condition2()
// {
//     int X ;
//     for (X = 97; X <= 122; X++)
//     {
//         cout << char(X) << endl;
//     }
// }

// int main(){
//     cout <<"Capital Letters is :\n";
//     conversion_condition();
//     cout <<"Small Letters is :\n";
//     conversion_condition2();
//     return 0;
// }


  
