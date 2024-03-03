#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

bool Check_Identity_Matrix(int matrix1[3][3],  int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if (i == j && matrix1[i][j] != 1)
            {
                return false;
            }
            else if ( i != j && matrix1[i][j] != 0)
            {
                return false;
            } 
        }
    }
    return true;
}

int main()
{
    int Matrix1[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int Matrix2[3][3] = {{1, 1, 1}, {0, 1, 1}, {1, 0, 0}};
    if (Check_Identity_Matrix(Matrix2, 3, 3))
    {
        cout << "It's an identity Matrix";
    }
    else 
    {
        cout << "It's not an identity Matrix";
    }
    return 0;

}