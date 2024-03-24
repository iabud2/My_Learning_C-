#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

enum enAtmOptions
{
    eQuickWithDraw = 1,
    eNormalWithraw = 2,
    eDeposit = 3,
    eCheckBalanse = 4,
    eLogOut = 5,
};  

sClient CurrentClient;

string ClientsFileName = "Bank_Clients.txt";

void ShowAtmMainScreen();
void Login();
void Atm_ShowNormalWithDrawScreen();
void Atm_ShowQuickwithDrawScreen();

vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length()); /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // cast string to double

    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

vector<sClient> LoadCleintsDataFromFile(string FileName)
{

    vector<sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out); // overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                // we only write records that are not marked for delete.
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }
    return vClients;
}

bool FindClientByAccountNumberAndPinCode(string Account_Number, string PinCode, sClient& Client)
{

    vector<sClient> vClient = LoadCleintsDataFromFile(ClientsFileName);

    for (sClient &C : vClient)
    {

        if (C.AccountNumber == Account_Number && C.PinCode == PinCode)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

short ReadAtmMainMenuOption()
{
    short choice = 0;
    do {
        cout << "Chosse Whar do you Want to do ? [1 to 5] : ";
        cin >> choice;
    } while (choice <= 0 || choice > 5);
    return choice;
}

short Atm_ReadQuick_WithDrawAmount()
{
    short Amount = 0;
    do {
        cout << "\nChoose the amount [1 to 9] ? ";
        cin >> Amount;
    } while (Amount <= 0 || Amount > 9);
    return Amount;
}

double Atm_PerformQuickWithDrawChoice(short Amount_Choice)
{
    switch (Amount_Choice)
    {
    case 1:
        return 20;
        break;
    case 2:
        return 50;
        break;
    case 3:
        return 100;
        break;
    case 4:
        return 200;
        break;
    case 5:
        return 400;
        break;
    case 6:
        return 600;
        break;
    case 7:
        return 800;
        break;
    case 8:
        return 1000;
        break;
    case 9:
        ShowAtmMainScreen();
        return 0;
    }
}

bool Atm_WithDraw(string AccountNumber, double Amount, vector<sClient> &vClients)
{

    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this WithDraw? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance -= Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }
        }
    }
    return false;
}

void Atm_Perform_Quick_WithDraw()
{
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    double Amount;
    cout << "\nYour Balance is : " << CurrentClient.AccountBalance << endl;
    // Validate that the amount does not exceeds the balance  
        Amount = Atm_PerformQuickWithDrawChoice(Atm_ReadQuick_WithDrawAmount());
        if (Amount > CurrentClient.AccountBalance)
        {
            cout << "\nThe amount exceeds your balance, make another choice.\n";
            cout << "Press Anykey to continue...";
            system("pause>0");
            Atm_ShowQuickwithDrawScreen();
        }

    Atm_WithDraw(CurrentClient.AccountNumber, Amount, vClients);
    CurrentClient.AccountBalance -= Amount;
}

void Atm_ShowQuickwithDrawScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tQuick Withdraw Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] 20 \t\t[2] 50\n";
    cout << "\t[3] 100\t\t[4] 200\n";
    cout << "\t[5] 400\t\t[6] 600\n";
    cout << "\t[7] 800\t\t[8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    Atm_Perform_Quick_WithDraw();
}

int ReadNormalWithDrawAmont()
{
    int Amount = 0;
    do
    {
        cout << "\nEnter an amount multiple of 5's ? ";
        cin >> Amount;
    } while (Amount % 5 != 0);
   
    return Amount;
}

void Atm_Perform_Normal_WithDraw()
{
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    int Amount = ReadNormalWithDrawAmont();

    if (Amount > CurrentClient.AccountBalance);
    {
        if (Amount > CurrentClient.AccountBalance) {
            cout << "\nThe amount exceeds your balance, make another choice.\n";
            cout << "Press Anykey to continue...";
            system("pause>0");
            Atm_ShowNormalWithDrawScreen(); return;
        }

    }

    Atm_WithDraw(CurrentClient.AccountNumber, Amount, vClients);
    CurrentClient.AccountBalance -= Amount;
}

void Atm_ShowNormalWithDrawScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tNormal Withdraw Screen\n";
    cout << "===========================================\n";
    Atm_Perform_Normal_WithDraw();
}

bool Atm_Deposit(string AccountNumber, double Amount, vector<sClient>& vClients)
{

    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this WithDraw? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }
        }
    }
    return false;
}

double ReadDepositAmount() 
{ 
    double Amount;     
    cout << "\nEnter a positive Deposit Amount? ";     
    cin >> Amount; 
    while (Amount <= 0) 
    { 
        cout << "\nEnter a positive Deposit Amount? ";         
        cin >> Amount; 
    } 
    return Amount; 
}

void Atm_Perform_DepositScreen()
{
    double Deposit_Amount = ReadDepositAmount();
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    Atm_Deposit(CurrentClient.AccountNumber, Deposit_Amount, vClients);
    CurrentClient.AccountBalance += Deposit_Amount;
}

void Atm_ShowDepositScreen()
{
    system("cls");     
    cout << "===========================================\n";    
    cout << "\t\tDeposit Screen\n";     
    cout << "===========================================\n";
    Atm_Perform_DepositScreen();
}

void Atm_ShowBalanceScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tCheck Balance Screen\n";
    cout << "===========================================\n";
    cout << "\nYour Balance is : " << CurrentClient.AccountBalance;
    cout << "\n\n";
}

void GoBackToAtmMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowAtmMainScreen();
}

void PerformAtmScreen(enAtmOptions AtmOption)
{
    switch (AtmOption)
    {
    case eQuickWithDraw:
        Atm_ShowQuickwithDrawScreen();
        GoBackToAtmMenue();
        break;
    case eNormalWithraw:
        Atm_ShowNormalWithDrawScreen();
        GoBackToAtmMenue();
        break;
    case eDeposit:
        Atm_ShowDepositScreen();
        GoBackToAtmMenue();
        break;
    case eCheckBalanse:
        Atm_ShowBalanceScreen();
        GoBackToAtmMenue();
        break;
    case eLogOut:
        Login();
        break;
    }
}

bool LoadUserInfo(string Account_Number, string PinCode)
{

    if (FindClientByAccountNumberAndPinCode(Account_Number, PinCode, CurrentClient))
        return true;
    else
        return false;
}

string ReadAccountNumber()
{
    string Username = "";

    cout << "\nPlease enter Account Number : ";
    cin >> Username;
    return Username;
}

string ReadPinCode()
{
    string Password = "";

    cout << "\nPlease enter Password : ";
    cin >> Password;
    return Password;
}

bool Get_Login_info()
{
    string Acc_Number = ReadAccountNumber();
    string Pincode = ReadPinCode();

    while (!FindClientByAccountNumberAndPinCode(Acc_Number, Pincode, CurrentClient))
    {
        system("cls");
        cout << "Invalid Username or Password!\n";
        Acc_Number = ReadAccountNumber();
        Pincode = ReadPinCode();
    }
    return true;
}

void Atm_Login_Screen()
{
    system("cls");
    cout << "-------------------------------------------\n";
    cout << "\t\tLogin Screen\n";
    cout << "-------------------------------------------\n";

}

void Login()
{
    Atm_Login_Screen();
    Get_Login_info();
    ShowAtmMainScreen();
}

void ShowAtmMainScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tAtm Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";
    PerformAtmScreen(enAtmOptions(ReadAtmMainMenuOption()));
}

int main()
{
    Login();
    ShowAtmMainScreen();
    return 0;
}