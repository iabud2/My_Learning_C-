#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

string Read_String()
{
    string message = " ";
    cout << "Enter Your String:\n";
    getline(cin, message);
    return message;
}

vector<string> Split_String(string ST1, string delimiter)
{
    vector<string> MyVector;
    int counter = 0;
    short pos = 0;
    string each_Word;
    while ((pos = ST1.find(delimiter)) != std::string::npos)
    {
        each_Word = ST1.substr(0, pos);
        if (each_Word != "")
        {
            MyVector.push_back(each_Word);
        }
        ST1.erase(0, pos + delimiter.length());
    }
    if (ST1 != "")
    {
        MyVector.push_back(ST1);
    }
    return MyVector;
}

void Print_Vector(vector<string> Myvector)
{
    for (string Word : Myvector)
    {
        cout << Word << endl;
    }
}
int main()
{
    string st1 = Read_String();
    vector<string> MyVector = Split_String(st1, " ");
    cout << "Tokens : " << MyVector.size() << endl;
    Print_Vector(MyVector);
    return 0;
}