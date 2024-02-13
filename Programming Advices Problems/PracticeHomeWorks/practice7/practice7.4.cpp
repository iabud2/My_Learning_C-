#include <iostream>
using namespace std ;

int main(){

    cout << ((5 > 6 && 7 == 7)||(1 || 0));
    cout << endl;
    cout << !(5 > 6 && 7 == 7)||(1 || 0);
    cout << endl;
    cout << !(5 > 6 && 7 == 7) || !(1 || 0);
    cout << endl;
    cout << !(5 > 6 ||  7 == 7) && !(1 || 0);
    cout << endl;
    cout << ((5 > 6 &&  7 <= 8) || (8>1 || 4<=3)) && true;
    cout << endl;
    cout << ((5 > 6 &&  !(7 <= 8)) && (8>1 || 4<=3)) || true;
    cout <<"\nDone";
}
