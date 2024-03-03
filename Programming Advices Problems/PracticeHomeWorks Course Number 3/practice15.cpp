#include <iostream>
#include <string>
using namespace std;

struct stInfo {
    string Full_Name;
    int Age;
    string Country;
    string Ctiy;
    int Salaray;
    string Gender;
    string Martial_status;
};

void Read_Info(stInfo &info )
{
    cout<<"Enter Your Name:\n";
    getline(cin, info.Full_Name);
    cout<<"How Old are You\n";
    cin >> info.Age;
    cout << "Where Are you From:\n";
    cin >> info.Country;
    cout << "Which City?\n";
    cin >> info.Ctiy;
    cout << "How much your salary per month \n";
    cin >> info.Salaray;
    cout << "Type your Gender?\n";
    cin >> info.Gender;
    cout << "martial status?\n";
    cin >> info.Martial_status;
}

void Print_Info(stInfo info){
    cout << "===============================================\n";
    cout << "Full Name: " << info.Full_Name << endl;
    cout << "Age: " << info.Age << " Years" << endl;
    cout << "Country: " << info.Country << endl;
    cout << "City: " << info.Ctiy << endl;
    cout << "Yearly Salary: " << info.Salaray * 12 << endl;
    cout << "Gender :" << info.Gender << endl;
    cout << "Martial Status :" << info.Martial_status;
    cout << "===============================================\n";
}

int main(){
    stInfo person1;
    Read_Info(person1);
    Print_Info(person1);
    return 0;
}