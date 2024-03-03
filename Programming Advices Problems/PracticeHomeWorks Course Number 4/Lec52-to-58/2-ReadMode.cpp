#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void ReadTxtFile(string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            cout << Line << endl;
        }
    }
}

int main()
{
    ReadTxtFile("MyFile.txt");
    return 0;
}