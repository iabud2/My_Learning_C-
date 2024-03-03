#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string Clients_Data = "Clients_Data.txt";

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

stClinetData Convert_Line_To_Record(string Data, string Separetor = "#//#")
{
    stClinetData ClientData;
    vector<string> vData = Split_String(Data, Separetor);
    ClientData.Account_Number = vData[0];
    ClientData.PinCode = vData[1];
    ClientData.Name = vData[2];
    ClientData.phone = vData[3];
    ClientData.Account_Balance = vData[4];
    return ClientData;
}

vector<stClinetData> Load_Data_From_File(string File_Name)
{
    vector<stClinetData> vClient;
    fstream MyFile;
    MyFile.open(File_Name, ios::in);
    {
        if (MyFile.is_open())
        {
            string line;
            stClinetData Client;
            while (getline(MyFile, line))
            {
                Client = Convert_Line_To_Record(line);
                vClient.push_back(Client);
            }
            MyFile.close();
        }
    }
    return vClient;
}

bool Find_Clinet_By_Account_Number(stClinetData &Client, string Acc_Number)
{
    vector<stClinetData> vClint = Load_Data_From_File(Clients_Data);
    for (stClinetData Record : vClint)
    {
        if (Record.Account_Number == Acc_Number)
        {
            Client = Record;
            return true;
        }
    }
    return false;
}

void PrintClientCard(stClinetData Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.Account_Number;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.phone;
    cout << "\nAccount Balance : " << Client.Account_Balance;
}

string Read_Account_Number()
{
    string Acc_Number;
    cout << "PLease Enter Account Number : ";
    cin >> Acc_Number;
    return Acc_Number;
}

int main()
{
    stClinetData Client;
    string Account_Number = Read_Account_Number();
    if (Find_Clinet_By_Account_Number(Client, Account_Number))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\n\n Sorry Client with Account Number (" << Account_Number << ") Not Found \n";
    }

    return 0;
}