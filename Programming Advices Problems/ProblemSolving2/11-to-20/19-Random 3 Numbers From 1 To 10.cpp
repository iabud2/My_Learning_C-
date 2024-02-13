#include <iostream>
#include <cstdlib>
using namespace std;


int Random_Number(int from , int to)
{
	int	random_num = rand() % (to - from + 1) + from;
	return random_num;
}

void Get_Random()
{
	for (int i = 1; i <= 3; i++)
	{
		cout << Random_Number(20, 50) << endl;
	}
}
int main()
{
	
	srand((unsigned)time(NULL));
	Get_Random();
	return 0;
}