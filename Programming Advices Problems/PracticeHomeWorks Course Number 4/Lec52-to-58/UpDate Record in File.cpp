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

void UpdateRecordInFile(string FileName, string OldRecord, string NewRecord)
{
    vector<string> MyData;
    LoadDataToVector(FileName, MyData);
    for (string &Line : MyData)
    {
        if (Line == OldRecord)
        {
            Line = NewRecord;
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
    cout << "\nFile Content B4 Edit:\n\n";
    ReadTxtFile("MyFile.txt");
    UpdateRecordInFile("MyFile.txt", "Ali", "Omar");
    cout << "\n\nFile Content After Edit:\n\n";
    ReadTxtFile("MyFile.txt");
    return 0;
}