#include <iostream>
using namespace std;

int Read_Number()
{
    int Number = 0;
    cout << "Enter a Number : ";
    cin >> Number;
    return Number;
}

string Number_To_Text(int Number)
{
    if (Number == 0)
    {
        return "";
    }
    if (Number >= 1 && Number <= 19)
    {
        string arr[] =
            {"", "One", "Two", "Three", "Fou", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
             "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        return arr[Number] + " ";
    }
    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {"", "", "Twenty", "Thirty", "Forty", "fifty", "Sixty", "Seventy", "Eighty", "nenety"};
        return arr[Number / 10] + " " + Number_To_Text(Number % 10);
    }
    if (Number >= 100 && Number <= 199)
    {
        return "One Hundred " + Number_To_Text(Number % 100);
    }
    if (Number >= 200 && Number <= 999)
    {
        return Number_To_Text(Number / 100) + " Hundred " + Number_To_Text(Number % 100);
    }
    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + Number_To_Text(Number % 1000);
    }
    if (Number >= 2000 && Number <= 999999)
    {
        return Number_To_Text(Number / 1000) + "Thousand " + Number_To_Text(Number % 1000);
    }
    if (Number >= 1000000 && Number <= 1999999)
    {
        return "One Million " + Number_To_Text(Number % 1000000);
    }
    if (Number >= 2000000 && Number <= 999999999)
    {
        return Number_To_Text(Number / 1000000) + "Millions " + Number_To_Text(Number % 1000000);
    }
    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + Number_To_Text(Number % 1000000000);
    }
    if (Number >= 2000000000 && Number <= 999999999999)
    {
        return Number_To_Text(Number / 1000000000) + "Billions " + Number_To_Text(Number % 1000000000);
    }
    else
    {
        return "Out Of Range";
    }
}

int main()
{
    int Number = Read_Number();
    cout << Number_To_Text(Number);
    return 0;
}