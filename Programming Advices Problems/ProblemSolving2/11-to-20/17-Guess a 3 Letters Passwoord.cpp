

#include <iostream>
using namespace std;

string Read_Password(string message)
{
	string Password = "";
	do {
		cout << message;
		cin >> Password;
	} while (Password.length() > 3 || Password.length() < 3);
	return Password;
}

bool Guess_Password(string MyPAssword)
{
	string Password= "";
	int counter = 0;
	for (int i = 65; i <= 90; i++)
	{

		for (int j = 65; j <= 90; j++)
		{

			for (int k = 65; k <= 90; k++)
			{

				counter++;
				Password =  Password + char(i) + char(j) + char(k);
				cout << "Trian Number  (" << counter << ") => " << Password << endl;
				if (Password == MyPAssword)
				{
					cout << "Password Founds : " << Password <<endl;
					cout << "Found at Trail Number : " << counter;
					return 1;
				}
					Password = "";
			}
		}
	}
}
int main()
{
	Guess_Password(Read_Password("Enter Your Password (must be 3 capital letters:\n"));
	return 0;
}