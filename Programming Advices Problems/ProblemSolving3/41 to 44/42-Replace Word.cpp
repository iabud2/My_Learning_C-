#include <iostream>
#include <vector>
#include <string>
using namespace std;

string Replace_String(string Mystring, string replace_it, string replace_To)
{
    short pos = Mystring.find(replace_it);
    while (pos != std::string::npos)
    {
        Mystring = Mystring.replace(pos, replace_it.length(), replace_To);
        pos = Mystring.find(replace_it);
    }
    return Mystring;
}

int main()
{
    string My_String = "Welcome To Jordan, Jordan is a nice country";
    cout << "String before Replace Function :\n"
        << My_String << endl;
    My_String = Replace_String(My_String, "Jordan", "Usa");
    cout << "String after  Replace function :\n"
        << My_String;
    return 0;
}