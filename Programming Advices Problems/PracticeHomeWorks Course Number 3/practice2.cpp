

#include <iostream>
using namespace std;
int main()
{   
    cout<<"-------------------------------------\n";
    cout<<"Hello Enter The Number Of KiloBytes\n";
    cout<< "-------------------------------------\n";
    int kb;
    cin >> kb ;
    cout << "This is Thnumber Of your KiloBytes\n"<< kb;
    cout << " You Entered :"<< kb <<" kb\n";
    cout << "-----------\n";
    int byte = kb * 1024 ;
    cout << "It's equal to :"<< byte <<" bytes\n" ;
    cout << "-----------\n";
    int bit1 = byte * 8 ;
    cout << "It's Also Equal To :"<< bit1 << " bits\n";
    cout << "-----------";
    return 0;
}
