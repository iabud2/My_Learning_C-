#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream MyFile;
    MyFile.open("MyFile.txt", ios::app);
    if (MyFile.is_open())
    {
        MyFile << "Mahmoud Yousef\n";
        MyFile << "Abdullah Khalid\n";
        MyFile.close();
    }
    return 0;
}