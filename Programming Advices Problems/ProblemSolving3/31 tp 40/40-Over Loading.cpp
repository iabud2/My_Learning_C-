#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

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

string Join_String(string arr[10], int length, string Delimiter)
{
    string MyString;
    for (int i = 0; i < length; i++)
    {
        MyString = MyString + arr[i] + Delimiter;
    }
    return MyString.substr(0, MyString.length() - Delimiter.length());
}

int main()
{
    vector<string> MyVector = {"Ahmed", "Ali", "Khaled", "Maha", "Mona"};
    string arr[10] = {"Mohammed", "omar", "anas", "Fady", "ashraf"};
    string MyStr = Join_String(MyVector, ", ");
    string Mystr2 = Join_String(arr, 10, " ");
    cout << MyStr;
    cout << endl << Mystr2 << endl;
    return 0;
}