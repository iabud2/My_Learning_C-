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
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

bool check_Matrices_Equality(int Matrix1[3][3], int Matrix2[3][3], int rows, int columns)
{
    return (sum_of_matrix(Matrix1, rows, columns) == sum_of_matrix(Matrix2, rows, columns));    
}
int main()
{
    srand((unsigned)time(0));
    int Matrix1[3][3];
    int Matrix2[3][3];

    fillMatrix(Matrix1, 3, 3);
    cout << "Matrix 1:\n";   
    PrintMatrix(Matrix1, 3, 3);

    fillMatrix(Matrix2, 3, 3);
    cout << "Matrix2:\n";
    PrintMatrix(Matrix2, 3, 3);

    
    if (check_Matrices_Equality(Matrix1, Matrix2, 3, 3))
    {
        cout << "\nBoth Matrices is equal.";
    }
    else 
    {
        cout << "\nNo , Matrices Not Equal.";
    }
    return 0;
}