// solving Problems 4, 8, 11, 24, 49, Using conditions
#include <iostream>
using namespace std;
// 4.
// int main()
// {
//     int age;
//     cout << "Enter Your Age\n";
//     cin >> age;
//     string liecense;
//     cout << "Driver License?(y/n):\n";
//     cin >> liecense;
//     if ( age > 21 && liecense == "y"){
//         cout << "Hired";
//     }
//     else {
//         cout << "Rejected";
//     }

//     return 0;
// }

//---------------------------------------------

// 8.

// int main(){
//     int mark ;
//     cout << "Enter The Mark:\n";
//     cin >> mark;
//     if (mark <=50){
//         cout << "fail";
//     }
//     else {
//         cout << "passed";
//     }
//     return 0;
// }

//-------------------------------------------

// 11.

// struct stdegree
// {
//     int mark1;
//     int mark2;
//     int mark3;
// };

// void Read_Degree(stdegree &degree)
// {
//     cout << "Enter Your Marks:\n";
//     cin >> degree.mark1;
//     cin >> degree.mark2;
//     cin >> degree.mark3;
// }

// int Avg_Degree(stdegree marks)
// {
//     return(marks.mark1 + marks.mark2 + marks.mark3 )/ 3;
// }

// int main()
// {
//     stdegree Student[3];

//     Read_Degree(Student[0]);
//     if (Avg_Degree(Student[0]) <=50){
//         cout << "FAIL";
//     }
//     else {
//         cout << "PASS";
//     }
//     return 0;
// }

//-----------------------------------------------------

// 23

// int main()
// {
//     int age;
//     cout << "Enter Your Age:\n";
//     cin >> age;
//     if (age >= 18 && age < 45)
//     {
//         cout << "Valid Age.";
//     }
//     else
//     {
//         cout << "Invalid Age.";
//     }
//     return 0;
// }


//------------------------------------------------------

//49

// int main()
// {
//     int pass = 1234;
//     int user;
//     int balance = 7500;
//     cout << "Enter Your Password:\n";
//     cin >> user;
//     if (pass == user){
//         cout << "Your balance is : " <<balance;
//     }
//     else{
//         cout <<"Sorry Wrong PIN";
//     }

//     return 0;
// } 