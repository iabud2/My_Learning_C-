#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string Read_String()
{
    string message = " ";
    cout << "Enter Your String:\n";
    getline(cin, message);
    return message;
}


int Count_Words(string ST1)
{
    int counter = 0;
    string delimter = " ";
    short pos = 0;
    string each_Word;
    while ((pos = ST1.find(delimter)) != std::string::npos)
    {
        each_Word = ST1.substr(0, pos);
        if (each_Word != "")
        {
            counter ++;
        }
        ST1.erase(0, pos + delimter.length());
    
    }
    if (ST1 != "")
    {
        counter ++;
    }
    return counter;
}

int main()
{
    string st1 = Read_String();
    int counte_words = Count_Words(st1);
    cout << "We Have " << counte_words << " Word/s in the string.";
}