//Write a program to ask the use to enter his / her name and  print it on screen.
#include <iostream>
#include <string>
using namespace std;

string readName(string &Name){
    cout << "Enter Your Name :\n";
    getline(cin, Name);
    return Name;
}

void printName(string Name){
    cout << "Hello "<<Name;
}

int main(){
    string myName;
    printName(readName(myName));
    return 0;
}