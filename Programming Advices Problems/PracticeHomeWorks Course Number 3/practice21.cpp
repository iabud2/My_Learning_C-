#include <iostream>
using namespace std;

struct stinfo{
    string First_Name;
    string Last_Name;
    int age;
    string Phone;

};

void Read_Info(stinfo &info){
    cout << "Please enter FirstName?\n";
    cin >> info.First_Name;

    cout << "Please enter LastName?\n";
    cin >> info.Last_Name;

    cout << "Please enter Age?\n";
    cin >> info.age;

    cout << "Please enter Phone?\n";
    cin >> info.Phone ;
    cout << endl;
}

void Print_Info(stinfo info){

    cout << "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
    cout << "FirstName: " << info.First_Name << endl;
    cout << "LastName: "  << info.Last_Name << endl ;
    cout << "Age: " << info.age << endl ;
    cout << "Phone :" << info.Phone << endl ;
    cout << "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
}


void Read_Persons_info(stinfo Persons[100], int Length){
    cout << "How Many Persons:\n ";
    cin >> Length;

    for (int i = 0; i < Length; i++){
        cout << "\n_________________________________________\n";
        cout << "Enter Person's "<< i + 1 << " info\n:";
        Read_Info(Persons[i]);
        cout << "\n_________________________________________\n";
    }
}

void Print_Persons_info(stinfo Persons[100], int Length){
    
    for (int i = 0; i < Length ; i++){
        cout << "Person's"<< i + 1 <<" info\n";
        Print_Info(Persons[i]);
    }

}

int main(){
    stinfo people[100];
    int Length = 0;

    Read_Persons_info(people, Length);
    Print_Persons_info(people, Length);

    return 0;
}