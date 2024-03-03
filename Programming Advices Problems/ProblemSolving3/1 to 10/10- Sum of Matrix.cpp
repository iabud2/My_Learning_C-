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
            Matrix[i][J] = RandomNumber(0, 100);
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

int sum_of_matrix(int matrix[3][3], int rows, int columns)
{
    int sum = 0;
    for (int i = 0; i <rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];
    fillMatrix(Matrix, 3, 3);
    cout << "3X3 Matrix of random elements is :\n";
    PrintMatrix(Matrix, 3, 3);
    cout << "Sum of Matrix Element = " << sum_of_matrix(Matrix, 3, 3);
    return 0;
}