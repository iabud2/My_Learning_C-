#include <iostream>
using namespace std;

template <typename A> A MyMax(A Number1, A Number2)
{
    return(Number1 > Number2)? Number1:Number2;
}

int main()
{
    cout << MyMax<int>(1, 2) << endl;
    cout << MyMax<float>(5.2 , 2.2) << endl;
    cout << MyMax<char>('a', 'z') << endl;
    
    return 0;
}