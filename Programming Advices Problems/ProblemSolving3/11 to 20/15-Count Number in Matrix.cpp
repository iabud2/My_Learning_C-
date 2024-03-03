#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int Read_Number(string Message)
{
    cout << Message;
    int Number = 0;
    cin >> Number;
    return Number;
}

int Counter_Nubmer(int Matrix[3][3],int rows, int columns, int Number)
{
    short counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if (Matrix[i][j] == Number)
                counter ++;
        }
    }
    return counter;
}

int main()
{
    int Matrix[3][3] = {{9, 3, 3}, {2, 5, 5}, {5, 9, 3}};
    int Number = Read_Number("Enter The Number To count in matrix : ");
    printf("Number %d count in Matrix is %d", Number, Counter_Nubmer(Matrix, 3, 3, Number));
    return 0;
}