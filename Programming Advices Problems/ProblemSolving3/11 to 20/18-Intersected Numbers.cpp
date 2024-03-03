
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

bool is_Number_Exists(int Matrix[3][3], int rows, int columns, int Number)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (Matrix[i][j] == Number)
                return true;
        }
    }
    return false;
}

void Print_Matched_Numbers(int Matrix1[3][3], int Matrix2[3][3], int rows, int columns)
{
    int Number = 0;
    cout << "intesected Number is : \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            Number = Matrix1[i][j];
            if (is_Number_Exists(Matrix2, 3, 3, Number))
                cout << setw(3) << Number;
        }
    }
}
int main()
{
    int Matrix[3][3] = {{15, 77, 90}, {55, 8, 19}, {37, 82, 59}};
    int Matrix2[3][3] = {{77, 55, 37}, {90, 8, 82}, {15, 19, 59}};
    int Matrix3[3][3] = {{77, 55, 37}, {2, 2, 2}, {1, 1, 1}};
    int Matrix4[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    Print_Matched_Numbers(Matrix, Matrix4, 3, 3);
    return 0;
}