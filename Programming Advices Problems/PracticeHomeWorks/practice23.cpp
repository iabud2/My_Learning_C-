// Solve Problem 26, 27, 28, 29, 30, 32, 46, 50. Using while loops;

#include <iostream>
using namespace std;
//26
// int main(){
//     int num;
//     cout << "Enter The number:\n";
//     cin >> num;
//     int i = 1;
//     while (i <=num){
//         cout <<i<<endl;
//         i ++;
//     }
//         return 0;
// }


//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

// 27.

// int main(){
//     int N;
//     cout << "Enter The number:\n";
//     cin >> N;   
//     while (N >= 1){
//         cout <<N<<endl;
//         N-- ;
//     }
//         return 0;
// }

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


// 28.

// void sumOdds(){
//     int Number;
//     cout << "Enter The Number:\n";
//     cin >> Number;
//     int counter = 0;
//     int sum = 0;
//     while (counter <= Number){
//         if (counter % 2 != 0){
//             sum += counter;       
//         }
//             counter ++;
//         }
//         cout<< sum;
//     }

// int main(){
//     sumOdds();
//     return 0;
// }

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//29.

// void sumEven(){
//     int Number1;
//     cout << "Enter The Number:\n";
//     cin >> Number1;
//     int counter1 = 0;
//     int sum1 = 0;
//     while (counter1 <= Number1){
//         if (counter1 % 2 == 0){
//             sum1 += counter1;
//         }
//             counter1 ++;
//         }
//         cout<< sum1;
//     }

// int main(){
//     sumEven();
//     return 0;
// }

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//30.

// void factorial(){
//     int MyNumber;
//     cout << "Enter a number To Calculate The Factorial:\n";
//     cin >> MyNumber;

//     int factorial = 1;
//     int counter2 = 1;
//     while (counter2 <=MyNumber){
//             factorial *= counter2;
//             counter2++;
//     }
//     cout << factorial;
// }

// int main(){
//     factorial();
//     return 0;
// }

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//32.
// #include <cmath>
// void calculate_Power(int Number, int Power){

//     while (Power ==0)
//     {
//         cout <<"Your Numper power 0 = "<<pow(Number, Power)<<endl;
//         cout << "Enter Another Power Number:\n";
//         cin >> Power;
//     }
//     cout << Number << "^" << Power << " = " << pow(Number, Power);
// }

// int main(){

//     int num;
//     int pow1;
//     cout << "Enter The Number:\n";
//     cin >> num;
//     cout << "Enter The Power:\n";
//     cin >> pow1;
//     calculate_Power(num, pow1);
//     return 0;
// }

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//self test not about the homework.
// trying to solve AA, AB, ZZ by using while loop
// int main()
// {
//     int i = 65;
//     while (i <= 90)
//     {
//         int j = 65;
//         while (j <= 90)
//         {
//             cout << char(i) << char(j) << endl;
//             j++;
//         }
//         i++;
//     }
// }


//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//46. 

// int main(){
//     int A = 65;
//     int Z = 90;
//     while (A <= Z){
//         cout << char(A)<<endl;
//         A++;
//     }
//     return 0;
// }

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


//50;


// void checkPin(){
//     int Pin = 1234;
//     int user_input;
//     int tries = 3;
//     cout << "Enter Your Pin:\n";
//     cin >> user_input;
//     while (user_input != Pin && tries != 1)
//     {
//         cout <<"Sorry wrong Password!\n";
//         cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
//         cout << "Enter your Password:\n";
//         cin >> user_input;
//         tries--;
//     }
//     if (tries == 1)
//     {
//         cout << "Card Is Locked";
//     }
//     else
//     {
//         cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
//         cout << "Balance is 500 $";
//     }

// }

// int main()
// {
//     checkPin();
//     return 0;

// }