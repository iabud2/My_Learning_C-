#include <iostream>
using namespace std;

int main()
{
	int Numbers[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Numbers[i][j] = (i + 1) * (j + 1);
		}
	}
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			printf(" %0*d ", 2, Numbers[x][y]);
		}cout << endl;
	}
	return 0;
}