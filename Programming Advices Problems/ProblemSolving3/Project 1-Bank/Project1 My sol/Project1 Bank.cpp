#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

const string Clients_Data = "Bank_Clients.txt";
void  Main_Menue();

enum enClient_Services
{
    ShowClients = 1,
    Add_Client = 2,
    DeleteClient = 3,
    Update_Client = 4,
    FindClient = 5,
    Exit = 6,
};

enClient_Services Choose_Service()
{
    short Number = 0;
    do
    {
        cout << "Choose What Do You Want To Do : [1 - 6] : ";
        cin >> Number;
    } while (Number > 6 || Number <= 0);
    return enClient_Services(Number);
}

struct stClinetData
{
    string Account_Number;
    string PinCode;
    string Name;
    string phone;
    string Account_Balance;
    bool Mark_For_Delete = false;
};

string Read_Account_Number()
{
    string Acc_Number;
    cout << "PLease Enter Account Number : ";
    cin >> Acc_Number;
    return Acc_Number;
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

stClinetData Get_Client_Data()
{
    stClinetData ClientData;
    cout << "Adding New Client : \n";

    cout << "Enter Account Number : ";
    getline(cin >> ws, ClientData.Account_Number);

    cout << "Enter PinCode : ";
    getline(cin, ClientData.PinCode);

    cout << "Enter Name : ";
    getline(cin, ClientData.Name);

    cout << "Enter Phone : ";
    getline(cin, ClientData.phone);

    cout << "Enter AccountBalance :  ";
    cin >> ClientData.Account_Balance;
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

stClinetData Convert_Line_To_Record(string Data, string Separetor = "#//#")
{
    stClinetData ClientData;
    vector<string> vData = Split_String(Data, Separetor);
    ClientData.Account_Number = vData[0];
    ClientData.Name = vData[1];
    ClientData.PinCode = vData[2];
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

bool Find_Clinet_By_Account_Number(string Acc_Number, stClinetData& Client)
{
    vector<stClinetData> vClient = Load_Data_From_File(Clients_Data);
    for (stClinetData Record : vClient)
    {
        if (Record.Account_Number == Acc_Number)
        {
            Client = Record;
            return true;
        }
    }
    return false;
}

void Add_Data_To_File(string FileName, string NewLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    {
        if (MyFile.is_open())
        {
            MyFile << NewLine << endl;
            MyFile.close();
        }
    }
}

void Add_New_client()
{
    stClinetData Client;
    string Account_Number = Read_Account_Number();
    if (!Find_Clinet_By_Account_Number(Account_Number, Client))
    {
        Client = Get_Client_Data();
        Add_Data_To_File(Clients_Data, Convert_Record_To_Line(Client, "#//#"));
    }
    else
    {
        cout << "\nAccount Number " << Client.Account_Number << "Already Exists\n";
    }
}

void reset_Screen()
{
    system("cls");
    system("color 0F");
}

void Add_Clients()
{
    char New_Client = 'y';
    do
    {
        Add_New_client();
        cout << "Client Added Sccessflly, Do You Want To Add New Client? [y/n] : ";
        cin >> New_Client;
        cin.ignore(New_Client, '\n');
        reset_Screen();
    } while (New_Client == 'Y' || New_Client == 'y');
}

void Print_Record(stClinetData Client)
{
    cout << "| " << setw(15) << left << Client.Account_Number;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(8) << left << Client.PinCode;
    cout << "| " << setw(15) << left << Client.phone;
    cout << "| " << setw(20) << left << Client.Account_Balance;
}

void Print_All_Records(vector<stClinetData> Client)
{
    cout << "\n\t\t\tClients List [" << Client.size() << "] Client(s)";
    cout << "\n--------------------------------------------------------------";
    cout << "----------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(8) << "Pin Code";
    cout << "| " << left << setw(15) << "Phone Number";
    cout << "| " << left << setw(20) << "Account Balance";
    cout << "\n------------------------------------------------------------";
    cout << "------------------------------------------------------\n\n";
    for (stClinetData& ClinetData : Client)
    {
        Print_Record(ClinetData);
        cout << endl;
    }
    cout << "\n---------------------------------------------------------";
    cout << "---------------------------------------------------------\n";
}

bool Mark_Client_To_Delete_Record(vector<stClinetData>& Client_info, string Account_Number)
{

    for (stClinetData& Data : Client_info)
    {
        if (Data.Account_Number == Account_Number)
        {
            Data.Mark_For_Delete = true;
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
        for (stClinetData& Line : Client)
        {
            if (Line.Mark_For_Delete == false)
            {
                Each_Line = Convert_Record_To_Line(Line, "#//#");
                MyFile << Each_Line << endl;
            }
        }
        MyFile.close();
    }
    return Client;
}

bool Delete_Record_In_File(vector<stClinetData>& vclient)
{

    stClinetData Client_Data;
    char Make_Sure = 'n';
    string Account_Number = Read_Account_Number();
    if (Find_Clinet_By_Account_Number(Account_Number, Client_Data))
    {
        PrintClientCard(Client_Data);
        cout << "\nAre You Sure You Want To Delete this Clients ? [y/n] : ";
        cin >> Make_Sure;
        if (Make_Sure == 'y' || Make_Sure == 'Y')
        {
            Mark_Client_To_Delete_Record(vclient, Account_Number);
            Save_New_Data_In_File(Clients_Data, vclient);
            vclient = Load_Data_From_File(Clients_Data);
            cout << "\n\nClient Deleted Successfully!\n";
            return true;
        }
    }
    else
    {
        cout << "\nAccount with Number (" << Account_Number << ") Not Found\n\n";
    }
    return false;
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

bool Update_Record_In_File(vector<stClinetData>& vclient)
{

    stClinetData Client_Data;
    char Make_Sure = 'n';
    string Account_Number = Read_Account_Number();
    if (Find_Clinet_By_Account_Number(Account_Number, Client_Data))
    {
        PrintClientCard(Client_Data);
        cout << "\nAre you sure you want to update information for this client ? [y/n] : ";
        cin >> Make_Sure;
        cin.ignore(Make_Sure, '\n');
        if (Make_Sure == 'y' || Make_Sure == 'Y')
        {
            for (stClinetData& client : vclient)
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

void Find_Client()
{
    stClinetData Client;
    string Account_Number = Read_Account_Number();
    if (Find_Clinet_By_Account_Number(Account_Number, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\n\n Sorry Client with Account Number (" << Account_Number << ") Not Found \n";
    }
}



void Go_Back_to_Main_Menu()
{
    cout << "\n\nPress any key to go back to Main Menue...\n\n";
    system("pause>0");
    system("cls");
    Main_Menue();
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}

void Bank_Application()
{
    stClinetData Clients;
    vector<stClinetData> vClients_Data = Load_Data_From_File(Clients_Data);
    enClient_Services Service;

    Service = Choose_Service();
    switch (Service)
    {
    case enClient_Services::ShowClients:
    {
        system("cls");
        Print_All_Records(vClients_Data);
        Go_Back_to_Main_Menu();
        break;
    }
    case enClient_Services::Add_Client:
    {
        system("cls");
        Add_Clients();
        Go_Back_to_Main_Menu();
        break;
    }
    case enClient_Services::DeleteClient:
    {
        system("cls");
        Delete_Record_In_File(vClients_Data);
        Go_Back_to_Main_Menu();
        break;
    }
    case enClient_Services::Update_Client:
    {
        system("cls");
        Update_Record_In_File(vClients_Data);
        Go_Back_to_Main_Menu();
        break;
    }
    case enClient_Services::FindClient:
    {
        system("cls");
        Find_Client();
        Go_Back_to_Main_Menu();
        break;
    }
    case enClient_Services::Exit:
    {
        system("cls");
        ShowEndScreen();
        break;
    }
    }
}

void Main_Menue()
{
    cout << "=============================================================\n";
    cout << "\n\t\t\t Main Menue Screen\n";
    cout << "=============================================================\n";
    cout << "\t\t[1] Show Clients\n";
    cout << "\t\t[2] Add New Clients\n";
    cout << "\t\t[3] Delete Client\n";
    cout << "\t\t[4] Update Clint Info\n";
    cout << "\t\t[5] Find Client\n";
    cout << "\t\t[6] Exit\n";
    cout << "=============================================================\n";
    Bank_Application();
}



int main()
{
    Main_Menue();
    system("pause>0");
    return 0;
}
