
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void LoadDataFromVector(string FileName, vector<string> &MyData)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        int i = 1;
        for (string &Name : MyData)
        {
            MyFile << i << "- " << Name << endl;
            i++;
        }
    }
    MyFile.close();
    cout << "Data Completly Added!";
}

int main()
{
    vector<string> Names{"Fahad Emam", "Maha ahmed", "Mona Saleh", "Mohammed Ahmed", "Khaled Ali"};
    LoadDataFromVector("MyFile.txt", Names);

    return 0;
}