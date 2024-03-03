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

void Print_Record(stClinetData Client)
{
    cout << "| " << setw(15) << left << Client.Account_Number;
    cout << "| " << setw(8) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(15) << left << Client.phone;
    cout << "| " << setw(20) << left << Client.Account_Balance;
}

void Print_All_Records(vector<stClinetData> Client)
{
    cout << "\n\t\t\tClients List [" << Client.size() << "] Client(s)";
    cout << "\n--------------------------------------------------------------";
    cout << "----------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(8) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(15) << "Phone Number";
    cout << "| " << left << setw(20) << "Account Balance";
    cout << "\n------------------------------------------------------------";
    cout << "------------------------------------------------------\n\n";
    for (stClinetData &ClinetData : Client)
    {
        Print_Record(ClinetData);
        cout << endl;
    }
    cout << "\n---------------------------------------------------------";
    cout << "---------------------------------------------------------\n";
}

int main()
{
    vector <stClinetData> Each_Record = Load_Data_From_File(Clients_Data);
    Print_All_Records(Each_Record);
    return 0;
}