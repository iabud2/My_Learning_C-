#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
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
            cout << setw(4) << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void MiddleRow(int Matrix[3][3], int row, int column)
{
    short Midro = row / 2;
    for (int i = 0; i < column; i++)
    {
        printf("%0*d   ", 2, Matrix[Midro][i]);
    }
}

void MiddleColumn(int Matrix[3][3], int row, int column)
{
    short MidCol = column / 2;
    for (int i = 0; i < row; i++)
    {
        printf("%0*d    ", 2, Matrix[i][MidCol]);
    }
}

int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];

    fillMatrix(Matrix, 3, 3);
    cout << "3X3 Matrix of random elements is :\n";
    PrintMatrix(Matrix, 3, 3);
    cout << "\n------------\n";
    cout << "Middle Row ELements:\n";
    MiddleRow(Matrix, 3, 3);
    cout << "\nMiddle Column Elements:\n";
    MiddleColumn(Matrix, 3, 3);

    return 0;
}