#include <iostream>
#include <iomanip>
#include <cstdlib>

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
            cout << setw(3) << Matrix[i][j];
        }
        cout << endl;
    }
}


int Min_Number(int Matrix[3][3], int rows, int columns)
{
    int Min_Value = Matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        
        for(int j = 0; j < columns; j++)
        {
            if (Matrix[i][j] < Min_Value)
            {
                Min_Value = Matrix[i][j];
            }
        }
    }
    return Min_Value;
}

int Max_Number(int Matrix[3][3], int rows, int columns)
{
    int Max_Value = Matrix[0][0];
    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < columns; j++)
        {
            if (Matrix[i][j] > Max_Value)
            {
                Max_Value = Matrix[i][j];
            }
        }
    }
    return Max_Value;
}
int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];
    fillMatrix(Matrix, 3, 3);
    cout << "3X3 Matrix of random elements is :\n";
    PrintMatrix(Matrix, 3, 3);
    printf("\nMax Value in Matrix is :%d\n", Max_Number(Matrix, 3, 3));
    printf("Min Value in Matrix is : %d\n", Min_Number(Matrix, 3, 3));
    
    return 0;
}