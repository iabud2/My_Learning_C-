#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

bool is_Scalar_Matric(int matrix[3][3], int rows, int columns)
{
    int check = matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == j && matrix[i][j] != check)
            {
                return false;
            }
            else if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int MyMatrix[3][3] = {{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
    int Matrix[3][3] = {{2, 0, 0}, {2, 2, 2}, {3, 2, 0}};
    if (is_Scalar_Matric(MyMatrix, 3, 3))
    {
        cout << "Yes, It's a scalar matrix";
    }
    else
    {
        cout << "No, It's not a scalar matrix";
    }
    return 0;
}