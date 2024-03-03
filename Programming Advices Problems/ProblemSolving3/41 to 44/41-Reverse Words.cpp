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
    return message;\
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

string Reverse_String(string MyS)
{
    string Reversed_String = "";
    vector<string> MyVector = Split_String(MyS, " ");
    vector<string>::iterator i = MyVector.end();
    while (i != MyVector.begin())
    {
        --i;
        Reversed_String += *i + ' ';
    }
    Reversed_String = Reversed_String.substr(0, Reversed_String.length() - 1);
    return Reversed_String;
}

int main()
{
    string st1 = "Mona Mohammed Ahmed Mahmoud";
    cout << Reverse_String(st1);
    return 0;
}