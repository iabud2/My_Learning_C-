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
    bool Mark_ForDelete = false;
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

string Convert_Record_To_Line(stClinetData Client, string Separator)
{
    string Client_D;
    Client_D += Client.Account_Number + Separator;
    Client_D += Client.Name + Separator;
    Client_D += Client.PinCode + Separator;
    Client_D += Client.phone + Separator;
    Client_D += Client.Account_Balance;
    return Client_D;
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

bool Find_Clinet_By_Account_Number(string Acc_Number, vector<stClinetData> vClint, stClinetData &Client)
{
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

vector<stClinetData> Save_New_Data_In_File(string File_Name, vector<stClinetData> Client)
{
    fstream MyFile;
    MyFile.open(File_Name, ios::out);
    string Each_Line;
    if (MyFile.is_open())
    {
        for (stClinetData &Line : Client)
        {
            if (Line.Mark_ForDelete == false)
            {
                Each_Line = Convert_Record_To_Line(Line, "#//#");
                MyFile << Each_Line << endl;
            }
        }
        MyFile.close();
    }
    return Client;
}

stClinetData UpDate_Client_Data(string Account_Number)
{
    stClinetData ClientData;
    cout << "Adding New Client : \n";
    ClientData.Account_Number = Account_Number;
    cout << "Enter PinCode : ";
    getline(cin >> ws, ClientData.PinCode);

    cout << "Enter Name : ";
    getline(cin, ClientData.Name);

    cout << "Enter Phone : ";
    getline(cin, ClientData.phone);

    cout << "Enter AccountBalance :  ";
    cin >> ClientData.Account_Balance;
    return ClientData;
}

bool Update_Record_In_File(string Account_Number, vector<stClinetData> &vclient)
{

    stClinetData Client_Data;
    char Make_Sure = 'n';
    if (Find_Clinet_By_Account_Number(Account_Number, vclient, Client_Data))
    {
        PrintClientCard(Client_Data);
        cout << "\nAre you sure you want to update information for this client ? [y/n] : ";
        cin >> Make_Sure;
        cin.ignore(Make_Sure, '\n');
        if (Make_Sure == 'y' || Make_Sure == 'Y')
        {
            for (stClinetData &client : vclient)
            {
                if (client.Account_Number == Account_Number)
                {
                    client = UpDate_Client_Data(Account_Number);
                    break;
                }
            }
            Save_New_Data_In_File(Clients_Data, vclient);
            vclient = Load_Data_From_File(Clients_Data);
            cout << "\n\nClient Updated Successfully!\n";
            return true;
        }
    }
    else
    {
        cout << "\nAccount with Number (" << Account_Number << ") Not Found\n\n";
    }
    return false;
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
    vector<stClinetData> vClients = Load_Data_From_File(Clients_Data);
    string Account_Number = Read_Account_Number();
    Update_Record_In_File(Account_Number, vClients);
    return 0;
}