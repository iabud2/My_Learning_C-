#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int Counter_Nubmer(int Matrix[3][3], int rows, int columns, int Number)
{
    short counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (Matrix[i][j] == Number)
                counter++;
        }
    }
    return counter;
}

bool is_Sparse_Matrix(int Matrix[3][3], int rows, int columns)
{
    int MatrixSize = rows * columns;
    return (Counter_Nubmer(Matrix, 3, 3, 0) > (MatrixSize / 2));
}

int main()
{
    int Matrix[3][3] = {{0, 0, 0}, {0, 0, 0}, {5, 9, 3}};
    if (is_Sparse_Matrix(Matrix, 3, 3))
    {
        cout << "It's a Sparse Matrix.";
    }
    else
    {
        cout << "It's Not a Sparse Matrix.";
    }
    return 0;
}