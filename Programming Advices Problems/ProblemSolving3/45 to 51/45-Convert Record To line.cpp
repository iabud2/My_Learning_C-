#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

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

    cout << "Enter Account Number? ";
    getline(cin, ClientData.Account_Number);
    cout << "Enter PinCode? ";
    getline(cin, ClientData.PinCode);
    cout << "Enter Name? ";
    getline(cin, ClientData.Name);
    cout << "Enter Phone? ";
    getline(cin, ClientData.phone);
    cout << "Enter AccountBalance? ";
    cin >> ClientData.Account_Balance;
    return ClientData;
}

string Get_Client_Data_in_one_Line(stClinetData Client, string Separator)
{
    string Client_D;
    Client_D += Client.Account_Number + Separator;
    Client_D += Client.Name + Separator;
    Client_D += Client.PinCode + Separator;
    Client_D += Client.phone + Separator;
    Client_D += to_string(Client.Account_Balance);
    return Client_D;
}

int main()
{
    stClinetData Client; 
    string Client_Data = Get_Client_Data_in_one_Line(Get_Client_Data(), "#//#");
    cout << Client_Data;
    return 0 ;
}
