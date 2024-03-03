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

int Sum_of_Each_Row(int Matrix[3][3], int rownumber, int columns)
{
    int sum = 0;
    for (int i = 0; i < columns; i++)
    {
        sum = sum + Matrix[rownumber][i];
    }
    return sum;
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

void PrintArrayofSums(int Matrix[3][3], int columns, int rows)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Row Number " << i + 1 << " Sums => " << Sum_of_Each_Row(Matrix, i, columns) <<  endl;
    }
}

int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];
    fillMatrix(Matrix, 3, 3);
    cout << "3X3 Matrix of random elements is :\n";
    PrintMatrix(Matrix, 3, 3);
    cout << "\nSum of Each Row in Matrix :\n";
    PrintArrayofSums(Matrix, 3, 3);
    return 0;
}