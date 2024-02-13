// Soling Problems 36, 44, 45 using Switch - case , statement.
#include <iostream>
using namespace std;



//36.

// int main(){
//     float num1, num2;
//     cout << "Entet First Number:\n";
//     cin >> num1;
//     cout << "Entet Seocnd Number";
//     cin >> num2;

//     char Opetation; 

//     switch (Opetation)
//     {
//     case '+':
//         cout <<  num1 + num2; 
//         break;
    
//     case '-':
//         cout <<  num1 - num2; 
//         break;
    
//     case '*':
//         cout <<  num1 * num2; 
//         break;
    
//     case '/':
//         cout <<  num1 / num2; 
//         break;
    
//     default:
//      cout << "Wrong Day.";
//         break;
//     }

//     return 0;
// }


//---------------------------------------

//44.

// enum enW_Days{Sun=1, Mon=2, Tue=3, Wed=4, Thue=5, Fri=6, Sat=7};

// void Main_Menu(){
//     cout << "------------------------------------------\n";
//     cout << "       Week Days        " << endl;
//     cout << "************************" << endl;
//     cout << "Enter The Week Day Number\n";
//     cout << "1: Sunday" << endl;
//     cout << "2: Monday" << endl;
//     cout << "3: Tuesday" << endl;
//     cout << "4: Wednesday" << endl;
//     cout << "5: Thursday" << endl;
//     cout << "6: Friday" << endl;
//     cout << "7: Saturday" << endl;
//     cout << "-----------------------------------------\n";
// }

// enW_Days Read_Days(){
//     int choice;
//     cin >> choice;
//     return enW_Days(choice);
// };

// string choose_day(enW_Days Days)
// {
//     switch (Days)
//     {

//     case 1:
//         return "Sunday";
//         break;
//     case 2:
//         return "Monday";
//         break;
//     case 3:
//         return "Tuesday";
//         break;
//     case 4:
//         return "Wendnesday";
//         break;
//     case 5:
//         return "Thursday";
//         break;
//     case 6:
//         return "Friday";
//         break;
//     case 7:
//         return "Saturday";
//         break;
//     default:
//         return "Wrong Value ! Not A week day";
//     }
// }

// int main()
// {
//     Main_Menu();
//     cout << "Today is :"<<choose_day(Read_Days());
//     return 0;
// }



//--------------------------------------------

//45.
// int main()
// {
//     int month;
//     cout << "Enter The number Of month:\n";
//     cin >> month;
//     switch (month) {

//         case 1 :
//             cout << "Jenuary";
//         break;

//         case 2 :
//             cout << "February";
//         break;

//         case 3 :
//         cout << "Merch";
//         break;

//         case 4 :
//         cout << "Apri;";
//         break;

//         case 5 :
//         cout << "May";
//         break;
        
//         case 6 :
//         cout << "June";
//         break;

//         case 7 :
//         cout << "July";
//         break ;

//         case 8 : 
//         cout << "August";
//         break ;
        
//         case 9 :    
//         cout << "September";
//         break;

//         case 10 : 
//         cout << "October";
//         break;

//         case 11 :
//         cout << "November";
//         break ;
    
//         case 12 :
//         cout << "Devember";
//         break ;

//         default :
//         cout << "Wrong Month";
//         break;
//     }

//     return 0;
// }