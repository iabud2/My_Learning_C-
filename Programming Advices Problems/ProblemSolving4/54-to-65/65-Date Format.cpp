#include <iostream>
#include <vector>
#include <string>
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

string Replace_String(string &Mystring, string replace_it, string replace_To)
{
    short pos = Mystring.find(replace_it);
    while (pos != std::string::npos)
    {
        Mystring = Mystring.replace(pos, replace_it.length(), replace_To);
        pos = Mystring.find(replace_it);
    }
    return Mystring;
}

string Format_Date(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string Format_Date_String;
    Format_Date_String = Replace_String(DateFormat, "dd", to_string(Date.Day));
    Format_Date_String = Replace_String(DateFormat, "mm", to_string(Date.Month));
    Format_Date_String = Replace_String(DateFormat, "yyyy", to_string(Date.Year));
    return Format_Date_String;
}

int main()
{
    string Date_String = Read_String_Date("\nPlease Enter Date dd/mm/yyyy? : ");
    stDate Date = String_To_Date_Structure(Date_String);
    string test_format = Format_Date(Date, "\nDay :dd , Month:mm , Year:yyyy");
    cout << test_format <<endl;
    return 0;
}