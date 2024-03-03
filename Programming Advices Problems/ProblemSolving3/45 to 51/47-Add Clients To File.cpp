#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

const string Clients_Data = "Clients_Data.txt";

struct stClinetData
{
    string Account_Number;
    string PinCode;
    string Name;
    string phone;
    float Account_Balance;
};

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
    Client_D += to_string(Client.Account_Balance);
    return Client_D;
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
    Client = Get_Client_Data();
    Add_Data_To_File(Clients_Data, Convert_Record_To_Line(Client, "#//#"));
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

int main()
{
    Add_Clients();
    return 0;
}
