// Vectors
#include <iostream>
#include <vector>
using namespace std;

void FillVector(vector<int>& MyVector)
{
    int Number = 0;
    cout << "Please Enter a number :\n";
    cin >> Number;
    while (cin.fail())
    {
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         cout << "invalid number Enter a valid number : ";
         cin >> Number;
}
    MyVector.push_back(Number);
}

void ReadVectorElements(vector <int> Myvector)
{
    for (int &Number : Myvector)
    {
        cout << Number << endl;
    }
}

int main()
{
    vector <int> MyNumbers;
    char Again = 'Y';
    do {
        FillVector(MyNumbers);
        cout << "You want to add more numbers (y/n)";
        cin >> Again;
    } while (Again == 'Y' || Again == 'y');
    ReadVectorElements(MyNumbers);
    return 0;
}