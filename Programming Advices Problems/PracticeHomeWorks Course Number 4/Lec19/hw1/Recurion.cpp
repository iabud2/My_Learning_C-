#include <iostream>
using namespace std;

void PrintNumbers(int N, int M)
{
	if (M >= N)
	{
		cout << M << endl;
		PrintNumbers(N, M - 1);
	}
}

int main()
{

	PrintNumbers(1, 10);
	return 0;
}