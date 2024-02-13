#include <iostream>
using namespace std ;

int main()
{
    cout << ((7 == 7)&&( 7 > 5 ));
    cout << endl;
    cout << ((7 == 7)&&(7 < 5));
    cout << endl;
    cout << ((7 == 7)||(7 < 5));
    cout << endl;
    cout << ((7 < 7)||(7 > 5));
    cout << endl;
    cout << (!(7 == 7)&&(7 > 5));
    cout << endl;
    cout << ((7 ==7) && !(7 < 5));
    return 0;
}