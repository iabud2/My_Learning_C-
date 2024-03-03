
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

int main()
{
    int Matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int Number = Read_Number("Enter Numbru want To check in Matrix : ");
    if (is_Number_Exists(Matrix, 3, 3, Number))
    {
        printf("Yes Number %d Exists ", Number);
    }
    else
    {
        cout << "Number Not Found";
    }
    return 0;
}