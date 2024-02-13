#include <iostream>
using namespace std;

void swap(int &a, int &b)
{ 
    int num = a;
    a = b;
    b = num;
    cout << "\nnum after swaping is A ="<< a<< ", B = "<<b;
}

int main(){
    int a;
    int b;
    cin >> a;
    cin >> b;
    cout << "num before swaping is A =" << a << ", B = " << b;
    swap(a,b );
    cout << "\nnum out function is A =" << a << ", B = " << b;
}