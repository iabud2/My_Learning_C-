#include <iostream>
#include <string>   
using namespace std;

struct stinfo
{
    string F_Name;
    string L_Name;
    int age;
    string phone;
};

void Read_Info(stinfo &info)
{

    cout << "Enter Your First Name:\n";
    cin >> info.F_Name;
    cin.ignore(1, '\n');
    cout << "Enter Your Second Name\n";
    cin >> info.L_Name;
    cout << "How old are you:\n";
    cin >> info.age;
    cout << "Enter Your Phone Number:\n";
    cin >> info.phone;
}



void print_One_Person(stinfo info){
    cout <<"---------------------------------------------------\n";
    cout << "First Name :" << info.F_Name << endl;
    cout << "Last Name :" << info.L_Name << endl;
    cout << "Age  :" << info.age << endl;
    cout << "Phone Number :" << info.phone << endl;
    cout <<"---------------------------------------------------\n";
}

void Read_persons_info(stinfo person[2]){
    cout<< "*****************************************\n";
    cout << "Perosn1 :\n";
    Read_Info(person[0]);
    cout<< "\n*****************************************\n";
    cout << "Perosn2 :\n";
    Read_Info(person[1]);
    cout<< "\n*****************************************\n";
}
void Print_Persons_Info(stinfo person[2])
{
    print_One_Person(person[0]);
    
    print_One_Person(person[1]);
}

int main()
{
    stinfo person[2];
    Read_persons_info(person);
    Print_Persons_Info(person);

    return 0;
}