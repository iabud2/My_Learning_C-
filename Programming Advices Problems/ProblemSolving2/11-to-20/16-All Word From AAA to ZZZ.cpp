

#include <iostream>
using namespace std;



void All_Posible_Words()
{
	for (int i = 65; i <= 90; i++)
	{
		
		for (int j = 65; j <= 90; j++)
		{

			for (int k = 65; k <= 90; k++)
			{
				cout << char(i) << char(j) << char(k);
				cout << endl;
			}
		}
			cout << "\n--------------------------\n";

	}
}
int main()
{
	All_Posible_Words();
	return 0;
}