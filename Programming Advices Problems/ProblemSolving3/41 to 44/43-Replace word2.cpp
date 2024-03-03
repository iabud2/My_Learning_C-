#include <iostream>
#include <vector>
#include <string>
using namespace std;

string Upper_String(string Words)
{
    for (int i = 0; i < Words.length(); i++)
    {
        Words[i] = toupper(Words[i]);
    }
    return Words;
}

string Join_String(vector<string> MyVector, string Delimiter)
{
    string MyString;
    for (string s1 : MyVector)
    {
        if (s1 != MyVector.back())
            MyString = MyString + s1 + Delimiter;
        else
            MyString = MyString + s1;
    }
    return MyString;
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

string Replace_Word_in_String(string S1, string Replace_it, string Replace_to, bool Match_Case)
{
    vector<string> vS1 = Split_String(S1, " ");
    for (string &S : vS1)
    {
        if (Match_Case)
        {
            if (S == Replace_it)
            {
                S = Replace_to;
            }
        }
        else
        {
            if (Upper_String(S) == Upper_String(Replace_it))
            {
                S = Replace_to;
            }
        }
    }
    return Join_String(vS1, " ");
}
int main()
{
    string My_String = "Welcome To Jordan , Jordan is a nice country";
    cout << "String Before Replace :\n" << My_String << endl;
    cout << "\nString After Relpace Without Match Case:\n" << Replace_Word_in_String(My_String, "Jordan", "USA", true) << endl;
    cout << "\nString After Relpace With Match Case:\n" << Replace_Word_in_String(My_String, "jordan", "USA", false) << endl;
    return 0;
}