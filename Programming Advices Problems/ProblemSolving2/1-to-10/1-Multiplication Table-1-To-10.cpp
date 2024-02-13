#include <iostream>
using namespace std;


#include <iostream>
using namespace std;


void Head()
{
	cout << "\n\n\t\t\tMultiplication Table From 1 To 10\n\n\t";

	for (int i = 1; i <= 10; i++) {
		cout << i << "\t";
	}

	cout << "\n------------------------------------------------------------------------------------------\n";

}

string separetors(int i)
{
	if (i < 10)
		return "  |";
	else
		return " |";
}
void Rows()
{
	for (int A = 1; A <= 10; A++)
	{
		cout << " " << A << separetors(A);
		for (int b = 1; b <= 10; b++)
		{

			cout << "\t" << A * b;

		}
		cout << endl;
	}
}


int main()
{
	Head();
	Rows();

	return 0;
}