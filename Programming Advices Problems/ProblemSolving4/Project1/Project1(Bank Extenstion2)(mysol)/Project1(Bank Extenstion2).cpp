#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const string ClientsFileName = "Bank_Clients.txt";
const string UsersFileName = "Users_Info.txt";
void ShowMainMenue();
void ShowTransactionsMenue();
void ShowManageUsersScreen();
void Login();

struct sClient
{
    string Account_Number;
    string PinCode;
    string Name;
    string Phone;
    double Account_Balance;
    bool MarkForDelete = false;
};

struct stUser_Info
{
    string UserName = "";
    string UserPassWord = "";
    int UserPermissions = 0;
    bool MarkUserForDelete = 0;
};

enum enTransactionsMenueOptions
{
    eDeposit = 1,
    eWithdraw = 2,
    eShowTotalBalance = 3,
    eShowMainMenue = 4
};

enum enMainMenueOptions
{
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eShowTransactionsMenue = 6,
    enManageUsers = 7,
    elogOut = 8,
};

enum enManageUsersOption
{
    ListUsers = 1,
    AddNewUser = 2,
    DeleteUser = 3,
    UpdateUser = 4,
    FindUser = 5,
    MainMenu = 6
};

enum enUserPermissions
{
    pFullPremetions = -1,
    pListClients = 1,
    pAddNewClient = 2,
    pDeleteClient = 4,
    pUpdateClient = 8,
    pFindClient = 16,
    pTransactions = 32,
    pManageUsers = 64,
};

stUser_Info CurrentUser;

//File Manegment Functions :
//---------------------------

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

    Client.Account_Number = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.Account_Balance = stod(vClientData[4]); // cast string to double

    return Client;
}

stUser_Info Convert_Lineto_UserRecord(string Line, string Seperator = "#//#")
{

    stUser_Info User;
    vector<string> vUser_info;

    vUser_info = SplitString(Line, Seperator);

    User.UserName = vUser_info[0];
    User.UserPassWord = vUser_info[1];
    User.UserPermissions = stoi(vUser_info[2]);

    return User;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.Account_Number + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.Account_Balance);

    return stClientRecord;
}

string ConvertRecordToUserLine(stUser_Info User, string Seperator = "#//#")
{
    string UserRecord = "";
    UserRecord += User.UserName + Seperator;
    UserRecord += User.UserPassWord + Seperator;
    UserRecord += to_string(User.UserPermissions);
    return UserRecord;
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

vector<stUser_Info> LoadUsersDataFromFile(string FileName)
{

    vector<stUser_Info> vUsers;

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;
        stUser_Info Users;
        while (getline(MyFile, Line))
        {
            Users = Convert_Lineto_UserRecord(Line);
            vUsers.push_back(Users);
        }
        MyFile.close();
    }
    return vUsers;
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

vector<stUser_Info> SaveUsersDataToFile(string FileName, vector<stUser_Info> vUsers)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out); // overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (stUser_Info U : vUsers)
        {

            if (U.MarkUserForDelete == false)
            {
                // we only write records that are not marked for delete.
                DataLine = ConvertRecordToUserLine(U);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vUsers;
}
//---------------------------

//Permissions Functions:
int ReadPermissionsToSet()
{
    int Permissions = 0; char Answer = 'n';
    cout << "\nDo you want to give full access? y/n? ";
    cin >> Answer; 
    if (Answer == 'y' || Answer == 'Y') 
    { 
        return -1; 
    }

    cout << "\nDo you want to give access to : \n ";

    cout << "\nShow Client List? y/n? ";     
    cin >> Answer; 
    if (Answer == 'y' || Answer == 'Y') 
    { 
        Permissions += enUserPermissions::pListClients; 
    }   
    
    cout << "\nAdd New Client? y/n? ";    
    cin >> Answer; 
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enUserPermissions::pAddNewClient;
    }
    
    cout << "\nDelete Client? y/n? ";    
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y') 
    {
        Permissions += enUserPermissions::pDeleteClient; 
    }
    cout << "\nUpdate Client? y/n? ";    
    cin >> Answer; 
    if (Answer == 'y' || Answer == 'Y') 
    {
        Permissions += enUserPermissions::pUpdateClient; 
    }

    cout << "\nFind Client? y/n? ";    
    cin >> Answer; 
    if (Answer == 'y' || Answer == 'Y') 
    {
        Permissions += enUserPermissions::pFindClient; 
    }
    
    cout << "\nTransactions? y/n? ";     cin >> Answer; 
    if (Answer == 'y' || Answer == 'Y') 
    {
        Permissions += enUserPermissions::pTransactions;
    }

    cout << "\nManage Users? y/n? ";     
    cin >> Answer; 
    if (Answer == 'y' || Answer == 'Y') 
    { 
        Permissions += enUserPermissions::pManageUsers; 
    }
    return Permissions;

}

bool CheckAccessPermissions(enUserPermissions Permission)
{
    if (CurrentUser.UserPermissions == enUserPermissions::pFullPremetions)
    {
        return true;
    }
    if ((Permission & CurrentUser.UserPermissions) == Permission)
    {
        return true;
    }
    return false;
}

void ShowAccessDeniedScreen()
{
    system("cls");
    cout << "\n------------------------------------\n";     
    cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";    
    cout << "\n------------------------------------\n";
}

//---------------------------
//Bank Project 1 :
//& Bank Project Extention Transaction:
//---------------------------
bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
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
            if (Client.Account_Number == AccountNumber)
            {
                MyFile.close();
                return true;
            }

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return false;
}

sClient ReadNewClient()
{
    sClient Client;

    cout << "Enter Account Number? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.Account_Number);

    while (ClientExistsByAccountNumber(Client.Account_Number, ClientsFileName))
    {
        cout << "\nClient with [" << Client.Account_Number << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.Account_Number);
    }

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.Account_Balance;

    return Client;
}

void PrintClientRecordLine(sClient Client)
{

    cout << "| " << setw(15) << left << Client.Account_Number;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.Account_Balance;
}

void PrintClientRecordBalanceLine(sClient Client)
{

    cout << "| " << setw(15) << left << Client.Account_Number;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Account_Balance;
}

void ShowAllClientsScreen()
{
    if (!CheckAccessPermissions(enUserPermissions::pListClients))
    {
        ShowAccessDeniedScreen();
        return;
    }

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

void ShowTotalBalances()
{

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.Account_Balance;

            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;
}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.Account_Number;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.Account_Balance;
    cout << "\n-----------------------------------\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient &Client)
{

    for (sClient C : vClients)
    {

        if (C.Account_Number == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.Account_Number = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.Account_Balance;

    return Client;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient> &vClients)
{

    for (sClient &C : vClients)
    {

        if (C.Account_Number == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }

    return false;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }
}

void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
        // system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";

        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient> &vClients)
{

    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);

            // Refresh Clients
            vClients = LoadCleintsDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
    }
    cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    return false;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient> &vClients)
{

    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            for (sClient &C : vClients)
            {
                if (C.Account_Number == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient> &vClients)
{

    char Answer = 'n';

    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient &C : vClients)
        {
            if (C.Account_Number == AccountNumber)
            {
                C.Account_Balance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.Account_Balance;

                return true;
            }
        }

        return false;
    }
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

void ShowDeleteClientScreen()
{
    if (!CheckAccessPermissions(enUserPermissions::pDeleteClient))
    {
        ShowAccessDeniedScreen();
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen()
{
    if (!CheckAccessPermissions(enUserPermissions::pUpdateClient))
    {
        ShowAccessDeniedScreen();
        return;
    }
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowAddNewClientsScreen()
{
    if (!CheckAccessPermissions(enUserPermissions::pAddNewClient))
    {
        ShowAccessDeniedScreen();
        return;
    }
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    AddNewClients();
}

void ShowFindClientScreen()
{
    if (!CheckAccessPermissions(enUserPermissions::pFindClient))
    {
        ShowAccessDeniedScreen();
        return;
    }
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
}

void ShowLogOutScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tLogedOut Successfully :-)";
    cout << "\n-----------------------------------\n";
}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);
}

void ShowWithDrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter withdraw amount? ";
    cin >> Amount;

    // Validate that the amount does not exceeds the balance
    while (Amount > Client.Account_Balance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.Account_Balance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);
}

void ShowTotalBalancesScreen()
{

    ShowTotalBalances();
}

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();
}

void GoBackToTransactionsMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowTransactionsMenue();
}

short ReadTransactionsMenueOption()
{
    cout << "Choose what do you want to do? [1 to 4]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
{
    switch (TransactionMenueOption)
    {
    case enTransactionsMenueOptions::eDeposit:
    {
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eWithdraw:
    {
        system("cls");
        ShowWithDrawScreen();
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eShowTotalBalance:
    {
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eShowMainMenue:
    {
        ShowMainMenue();
    }
    }
}

void ShowTransactionsMenue()
{
    if (!CheckAccessPermissions(enUserPermissions::pTransactions))
    {
        ShowAccessDeniedScreen();
        return;
    }
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tTransactions Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "===========================================\n";
    PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}

short ReadMainMenueOption()
{
    short Choice = 0;
    do 
    {
        cout << "Choose what do you want to do? [1 to 8]? ";
        cin >> Choice;
    } while (Choice > 8 || Choice <= 0);

    return Choice;
}

//-----------------------------
// Bank Extention Number 2:
//Manage Users Extention :
//-----------------------------


bool UserExistsByUsername(string Username, string FileName)
{

    vector<stUser_Info> vUser;

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {

        string Line;
        stUser_Info User;

        while (getline(MyFile, Line))
        {

            User = Convert_Lineto_UserRecord(Line);
            if (User.UserName == Username)
            {
                MyFile.close();
                return true;
            }

            vUser.push_back(User);
        }

        MyFile.close();
    }

    return false;
}

stUser_Info ReadNewUser()
{
    stUser_Info User;

    cout << "Enter Username? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, User.UserName);
    while (UserExistsByUsername(User.UserName, UsersFileName))
    {
        cout << "\nUser with [" << User.UserName << "] already exists Enter another Username : \n";
        cout << "Enter Username: ";
        getline(cin >> ws, User.UserName);
    }
    
    cout << "Password :";
    getline(cin >> ws, User.UserPassWord);
    User.UserPermissions = ReadPermissionsToSet();
    
    return User;
}

void PrintUserRecordLine(stUser_Info User)
{

    cout << "| " << setw(15) << left << User.UserName;
    cout << "| " << setw(15) << left << User.UserPassWord;
    cout << "| " << setw(15) << left << User.UserPermissions;
}

void ShowAllUsersScreen()
{

    vector<stUser_Info> vUsers = LoadUsersDataFromFile(UsersFileName);

    cout << "\n\t\t\t\t\tClient List (" << vUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    cout << "| " << left << setw(15) << "UserName";
    cout << "| " << left << setw(15) << "Password";
    cout << "| " << left << setw(15) << "Peremetions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    if (vUsers.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (stUser_Info User : vUsers)
        {

            PrintUserRecordLine(User);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

void AddNew_User()
{
    stUser_Info User;
    User = ReadNewUser();
    AddDataLineToFile(UsersFileName, ConvertRecordToUserLine(User));
}

void AddNewUsers()
{
    char AddMore = 'Y';
    do
    {
        // system("cls");
        cout << "Adding New User:\n\n";
        AddNew_User();
        cout << "\nUser Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

void ShowAddNewUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New User Screen";
    cout << "\n-----------------------------------\n";

    AddNewUsers();
}

string ReadUsername()
{
    string Username = "";

    cout << "\nPlease enter username : ";
    cin >> Username;
    return Username;
}

string ReadPassword()
{
    string Password = "";

    cout << "\nPlease enter Password : ";
    cin >> Password;
    return Password;
}

bool FindUserByUsername(string Username, vector<stUser_Info> vUsers, stUser_Info& User)
{

    for (stUser_Info U : vUsers)
    {

        if (U.UserName == Username)
        {
            User = U;
            return true;
        }
    }
    return false;
}

void PrintUserCard(stUser_Info User)
{
    cout << "\nThe following are the User Info:\n";
    cout << "-----------------------------------";
    cout << "\nUsername   : " << User.UserName;
    cout << "\nPassword    : " << User.UserPassWord;
    cout << "\nPremetions   : " << User.UserPermissions;
    cout << "\n-----------------------------------\n";
}

bool MarkUserForDeleteByUserName(string UserName, vector<stUser_Info>& vUsers)
{

    for (stUser_Info &U: vUsers)
    {

        if (U.UserName == UserName)
        {
            U.MarkUserForDelete = true;
            return true;
        }
    }

    return false;
}

bool DeleteUserByUserName(string Username, vector<stUser_Info>& vUsers)
{

    stUser_Info User;
    char Answer = 'n';

    if (FindUserByUsername(Username, vUsers, User))
    {
        if (User.UserName == "Admin")
        {
            cout << "You Cannot Delete This User";
            return false;
        }

        PrintUserCard(User);
        cout << "\n\nAre you sure you want delete this User? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkUserForDeleteByUserName(Username, vUsers);
            SaveUsersDataToFile(UsersFileName, vUsers);

            // Refresh Clients
            vUsers = LoadUsersDataFromFile(UsersFileName);

            cout << "\n\nUser Deleted Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nUser with Account Number (" << Username << ") is Not Found!";
        return false;
    }
}

void ShowDeleteUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete User Screen";
    cout << "\n-----------------------------------\n";

    vector<stUser_Info> vUser = LoadUsersDataFromFile(UsersFileName);
    string Username = ReadUsername();
    DeleteUserByUserName(Username, vUser);
}

stUser_Info ChangeUserRecord(string Username)
{
    stUser_Info User;

    User.UserName = Username;

    cout << "\n\nPassWord? ";
    getline(cin >> ws, User.UserPassWord);
    User.UserPermissions = ReadPermissionsToSet();
    return User;
}

bool UpdateUserByUsername(string Username, vector<stUser_Info>& vUsers)
{
    stUser_Info User;
    char Answer = 'n';

    if (FindUserByUsername(Username, vUsers, User))
    {
        if (User.UserName == "Admin")
        {
            cout << "You Cannot Update This User";
            return false;
        }

        PrintUserCard(User);
        cout << "\n\nAre you sure you want update this User? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            for (stUser_Info& U : vUsers)
            {
                if (U.UserName == Username)
                {
                    U = ChangeUserRecord(Username);
                    break;
                }
            }

            SaveUsersDataToFile(UsersFileName, vUsers);

            cout << "\n\nUser Updated Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nUsername with Username (" << Username << ") is Not Found!";
        return false;
    }
}

void ShowUpdateUpdateScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate User Info Screen";
    cout << "\n-----------------------------------\n";

    vector<stUser_Info> vUsers = LoadUsersDataFromFile(UsersFileName);
    string Username = ReadUsername();
    UpdateUserByUsername(Username, vUsers);
}

void ShowFindUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind User Screen";
    cout << "\n-----------------------------------\n";

    vector<stUser_Info> vUsers = LoadUsersDataFromFile(UsersFileName);
    stUser_Info User;
    string Username = ReadUsername();
    if (FindUserByUsername(Username, vUsers, User))
        PrintUserCard(User);
    else
        cout << "\nUser with Username[" << Username << "] is not found!";
}

void GoBackManageUsersScreen()
{
    cout << "\n\nPress any key to go back to manage users screen...";
    system("pause>0");
    ShowManageUsersScreen();
}

void PerformManageUsersOption(enManageUsersOption ManagaUserOption)
{
    switch (ManagaUserOption)
    {
    case enManageUsersOption::ListUsers:    
        system("cls");
        ShowAllUsersScreen();
        GoBackManageUsersScreen();
        break;
        
    case enManageUsersOption::AddNewUser:
        system("cls");
        ShowAddNewUserScreen();
        GoBackManageUsersScreen();
        break;
    case enManageUsersOption::DeleteUser:
        system("cls");
        ShowDeleteUserScreen();
        GoBackManageUsersScreen();
        break;
    case enManageUsersOption::UpdateUser:
        system("cls");
        ShowUpdateUpdateScreen();
        GoBackManageUsersScreen();
        break;
    case enManageUsersOption::FindUser:
        system("cls");
        ShowFindUserScreen();
        GoBackManageUsersScreen();
        break;
    case enManageUsersOption::MainMenu:
        ShowMainMenue();
        break;
    }
}

short ReadManageUsersOption()
{
    short Choice = 0;
    do 
    {
        cout << "Choose what do you want to do? [1 to 6]? ";
        cin >> Choice;
    }while (Choice > 6 || Choice <= 0);
    
    return Choice;
}

void ShowManageUsersScreen()
{
    if (!CheckAccessPermissions(enUserPermissions::pManageUsers))
    {
        ShowAccessDeniedScreen();
        return;
    }
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tManage Users\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Users List.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User Info.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] MainMenu.\n";
    cout << "===========================================\n";
    PerformManageUsersOption(enManageUsersOption(ReadManageUsersOption()));
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:

        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eShowTransactionsMenue:
        system("cls");
        ShowTransactionsMenue();
        break;

    case enMainMenueOptions::enManageUsers:
        system("cls");
        ShowManageUsersScreen();
        break;

    case enMainMenueOptions::elogOut:
        system("cls");
        Login();
        break;
    }
}

void ShowMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] ManageUsers.\n";
    cout << "\t[8] Logout.\n";
    cout << "===========================================\n";
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

void Login_Screen()
{
    system("cls");
    cout << "-------------------------------------------\n";
    cout << "\t\tLogin Screen\n";
    cout << "-------------------------------------------\n";
    
}

bool FindUserByUsernameAndPassword(string Username, string PassWord, stUser_Info &User)
{

    vector<stUser_Info> vUsers = LoadUsersDataFromFile(UsersFileName);
    for (stUser_Info& U : vUsers)
    {
        if (U.UserName == Username && U.UserPassWord == PassWord)
        {
            User = U;
            return true;
        }
    }
    return false;
}

bool Load_User_Info(string Username, string Password)
{
    if (FindUserByUsernameAndPassword(Username, Password, CurrentUser))
    {
        return true;
    }
    return false;
}

bool Get_Login_info()
{
    string Username = ReadUsername();
    string Password = ReadPassword();
    while (!FindUserByUsernameAndPassword(Username, Password, CurrentUser))
    {
        system("cls");
        cout << "Invalid Username or Password!\n";
        Username = ReadUsername();
        Password = ReadPassword();
    }
    return true;
}

void Login()
{
    Login_Screen();
    Get_Login_info();
    ShowMainMenue();
}

int main()
{
    Login();
    system("pause>0");
    return 0;
}