#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate
{
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

string Read_String_Date(string Message)
{
    string String_Date = "";
    cout << Message;
    getline(cin, String_Date);
    return String_Date;
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

stDate String_To_Date_Structure(string Date_String)
{
    vector<string> vDate = Split_String(Date_String, "/");
    stDate Date;
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}

string Date_To_String(stDate Date)
{
    string String_Date;
    String_Date += to_string(Date.Day) + "/";
    String_Date += to_string(Date.Month) + "/";
    String_Date += to_string(Date.Year);
    return String_Date;
}
int main()
{
    string Date_String = Read_String_Date("\nPlease Enter Date dd/mm/yyyy? : ");
    stDate Date = String_To_Date_Structure(Date_String);
    cout << "\nDay : " << Date.Day << endl;
    cout << "\nMonth : " << Date.Month << endl;
    cout << "\nYear : " << Date.Year << endl;

    cout << "\nYou Entered : " << Date_To_String(Date) << "\n";

    return 0;
}
