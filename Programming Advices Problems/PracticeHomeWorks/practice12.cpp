#include <iostream>
#include <string>
using namespace std;


int main()
{
    string full_name;
    cout << "Please Enter String\n";
    getline(cin, full_name);
    string num;
    cout <<"Please Enter number\n";
    getline(cin, num);
    cout <<"Please Enter Another number\n";
    string num2;
    getline(cin ,num2);
    cout << "****************************************************\n";
    cout << "The Length of THe first String is"<< full_name.length()<<endl;
    cout << "Characters at 0, 2,4,7 are :"<< full_name[0]<<full_name[2]<<full_name[4]
    <<full_name[7]<<endl;
    cout << "Concatenating String2 and string3 ="<< num + num2 <<endl;
    cout << stoi(num) * stoi(num2);
    return 0 ;

}
