#include <iostream>
#include <string>
using namespace std;

string Read_Name(string message)
{
	string Name = "";
	cout << message;
	getline(cin, Name);
	return Name;
}

string EncryptionName(string Name)
{
	int EncryptionKey = 2;

	for (int i = 0; i <= Name.length(); i++) 
	{
		Name[i] += EncryptionKey;
		
	}
	return Name;
}

string DecryptionName(string EncryptionName)
{
	int EncryptionKey = 2;
	for (int i = 0; i <= EncryptionName.length(); i++) 
	{
		EncryptionName[i] -= EncryptionKey;
	}
	
	return EncryptionName;
}

void Print_Name(string Name)
{
	cout << "Encryption Name is: " << EncryptionName(Name) << endl;
	cout << "Decryption Name is: " << DecryptionName(EncryptionName(Name)) << endl;
}
int main()
{
	Print_Name(Read_Name("Enter Your Name:\n"));
	
	return 0;
}
