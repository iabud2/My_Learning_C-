#include <iostream>
using namespace std;

int main()
{
    int A;
    cout << "Enter The First Number\n";
    cin >> A ;
    int B ;
    cout << "Enter The Second Number\n";
    cin >> B;

    cout << A << " == " << B << " Is " << (A == B) << endl;
    cout << A << " != " << B << " Is " << (A != B) << endl;
    cout << A << " > " << B << " Is " << (A > B) << endl;
    cout << A << " < " << B << " Is " << (A < B) << endl;
    cout << A << " <= " << B << " Is " << (A <= B) << endl;
    cout << A << " >= " << B << " Is " << (A >= B) << endl;
    return 0 ;
}