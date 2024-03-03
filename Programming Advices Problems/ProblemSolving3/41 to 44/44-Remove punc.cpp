#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string Remove_Punc(string s1)
{
    string s2;
    for (int i = 0; i < s1.length(); i++)
    {
        if (!ispunct(s1[i]))
        {
            s2 += s1[i];
        }
    }
    return s2;
}

int main()
{
    string st = "Hello, Mohammed: it's ahmed?";
    cout << "This is the string after using Remove_Punc Function :\n" << Remove_Punc(st) << endl;
    return 0;
}