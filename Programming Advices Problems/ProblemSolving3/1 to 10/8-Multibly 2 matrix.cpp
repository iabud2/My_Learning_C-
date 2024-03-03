#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int RandomNumber(int from, int to)
{
    int Randint = rand() % (from - to + 1) + from;
    return Randint;
}

void fillMatrix(int Matrix[3][3], int columns, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int J = 0; J < columns; J++)
        {
            Matrix[i][J] = RandomNumber(1, 10);
        }
    }
}

void Multibly_two_Matrix(int Matrix1[3][3], int Matrix2[3][3], int Result[3][3], int rows, int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            Result[row][column] = (Matrix1[row][column]) * (Matrix2[row][column]);
        }
    }
}
void PrintMatrix(int Matrix[3][3], int columns, int rows)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%0*d  ", 2, Matrix[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(0));
    int Matrix1[3][3];
    int Matrix2[3][3];
    int Result[3][3];
    fillMatrix(Matrix1, 3, 3);
    cout << "Matrix1 :\n";
    PrintMatrix(Matrix1, 3, 3);
    printf("----------------------");
    fillMatrix(Matrix2, 3, 3);
    cout << "Matrix2 :\n";
    PrintMatrix(Matrix2, 3, 3);
    Multibly_two_Matrix(Matrix1, Matrix2, Result, 3, 3);
    cout << "Result: \n";
    PrintMatrix(Result, 3, 3);
    return 0;
}