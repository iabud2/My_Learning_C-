#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void fillMatrix(int Matrix[3][3], int columns, int rows)
{
    short Counter = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int J = 0; J < columns; J++)
        {
            Matrix[i][J] = Counter;
            Counter++;
        }
    }
}

void PrintMatrix(int Matrix[3][3], int columns, int rows)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(3) << Matrix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];
    fillMatrix(Matrix, 3, 3);
    cout << "3X3 Matrix of Ordered elements is :\n";
    PrintMatrix(Matrix, 3, 3);

    return 0;
}