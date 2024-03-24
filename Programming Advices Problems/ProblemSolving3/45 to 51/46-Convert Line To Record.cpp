#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

struct stClinetData
{
    string Account_Number;
    string PinCode;
    string Name;
    string phone;
    string Account_Balance;
};

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

stClinetData Get_Data_From_Line(string Data)
{
    stClinetData ClientData;
    vector<string> vData = Split_String(Data, "#//#");
    ClientData.Account_Number = vData[0];
    ClientData.PinCode  = vData[1];
    ClientData.Name = vData[2];
    ClientData.phone = vData[3];
    ClientData.Account_Balance = vData[4];
    return ClientData;
}

int main()
{
    stClinetData Client;
    string ClientData = "150A#//#9090#//#8065#//#Ahmed Mohammed#//#10203040#//#50.905";
    Client = Get_Data_From_Line(ClientData);
    cout << "Account Number : " << Client.Account_Number;
    cout << "\nPin Code : " << Client.PinCode << endl;
    cout << "Name : " << Client.Name << endl;
    cout << "Phone Number : " << Client.phone << endl;
    cout << "Account Balance : " << Client.Account_Balance << endl;
    return 0;
}
