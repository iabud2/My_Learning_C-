#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string Join_String(vector <string> MyVector, string Delimiter)
{
    string MyString;
    for (string s1 : MyVector)
    {
        if (s1 != MyVector.back())
            MyString = MyString + s1 + Delimiter;
        else
            MyString = MyString +s1;
    }
    return MyString;
}

int main()
{
    vector <string> MyVector = {"Ahmed", "Ali", "Khaled", "Maha", "Mona"};
    
    string MyStr = Join_String(MyVector, ", ");
    cout << MyStr;
    return 0;
}