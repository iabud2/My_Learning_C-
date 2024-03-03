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
    MyFile.close();
    cout << "Vector Completly Filled";
}

void LoadDataFromVector(string FileName, vector<string> &MyData)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (string &Name : MyData)
        {
            if (Name != "")
            {
                MyFile << Name << endl;
            }
        }
    }
    MyFile.close();
    cout << "Data Completly Added!";
}

void DeleteRecordFromFile(string FileName, string Record)
{
    vector<string> MyData;
    LoadDataToVector(FileName, MyData);
    for (string &Line : MyData)
    {
        if (Line == Record)
        {
            Line = "";
        }
    }
    LoadDataFromVector(FileName, MyData);
}

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
    cout << "File Content B4 Edit\n";
    ReadTxtFile("MyFile.txt");
    DeleteRecordFromFile("MyFile.txt", "Ali");
    cout << "\nFile Content After Edit\n";
    ReadTxtFile("MyFile.txt");
    return 0;
}