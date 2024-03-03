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
            cout << setw(3) << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

int Sum_of_Each_Column(int Matrix[3][3], int ColunNumber, int rows)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum = sum + Matrix[i][ColunNumber];
    }
    return sum;
}

void copy_sum_columns_in_Array(int arr[3], int Matrix[3][3], int columns, int rows)
{
    for(int i = 0; i < 3; i++)
    {
        arr[i] = Sum_of_Each_Column(Matrix, i, rows);
    }
    cout << "\nSum Values Copied Successfuly!\n\n";
}

void print_Sum_Columns(int arr[3])
{
    printf("Sum Values for each column = :\n");
    for (int i = 0; i < 3; i++)
    {
        cout << "Sum Of Column " << i + 1 << " = " << arr[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];
    int arr[3];
    fillMatrix(Matrix, 3, 3);
    cout << "3X3 Matrix of random elements is :\n";
    PrintMatrix(Matrix, 3, 3);
    copy_sum_columns_in_Array(arr , Matrix, 3, 3);
    print_Sum_Columns(arr);
    return 0;
}