#include <iostream>
#include <iomanip>
using namespace std;

bool is_Palindrome(int Matrix[3][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (Matrix[i][j] != Matrix[i][rows - j - 1])
            {
                return false;
            }
        }
    }
    return true;
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

int main()
{
    int Matrix1[3][3] = {{1, 3, 2}, {2, 4, 2}, {3, 5, 3}};
    PrintMatrix(Matrix1, 3, 3);
    if (is_Palindrome(Matrix1, 3, 3))
    {
        cout << "\n Yes it's a Palindrome Matrix.";
    }
    else
    {
        cout << "\n No, it's Not a Palindrome Matrix.";
    }
    return 0;
}