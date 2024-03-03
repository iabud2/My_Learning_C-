#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void LoadDataToVector(string FileName, vector<string> &MyData)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            MyData.push_back(Line);
        }
    }
    for (string &Name : MyData)
    {
        cout << " -- " << Name << endl;
    }
    MyFile.close();
}



int main()
{
    vector<string> Data;
    LoadDataToVector("MyFile.txt", Data);

    return 0;
}