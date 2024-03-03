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

void TrasposeMatrix(int Matrix1[3][3], int Matrix2[3][3], int rows, int columns)
{

    for (int a = 2; a >= 0; a--)
    {
        for (int b = 2; b >= 0; b--)
        {
            Matrix2[b][a] = Matrix1[a][b]; 
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
    int T_Matrix[3][3];
    fillMatrix(Matrix, 3, 3);
    cout << "3X3 Matrix of Ordered elements is :\n";
    PrintMatrix(Matrix, 3, 3);
    TrasposeMatrix(Matrix, T_Matrix, 3, 3);
    cout << "\nTrasnposed Matrix is :\n";
    PrintMatrix(T_Matrix, 3, 3);
    return 0;
}