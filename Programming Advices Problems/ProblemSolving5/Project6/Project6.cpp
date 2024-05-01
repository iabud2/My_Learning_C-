#include <iostream>
#include "clsMyStackArr.h"
using namespace std;
int main()
{
    clsMyStackArr <char> MyStack;

    MyStack.push('e');
    MyStack.push('d');
    MyStack.push('c');
    MyStack.push('b');
    MyStack.push('a');

    cout << "Stack items is :\n";
    MyStack.Print();

    cout << "\n\nStack Size is : " << MyStack.Size() << endl;

    cout << "\nThe item on top of the stack is : " << MyStack.Top() << endl;

    cout << "\nThe item on bottom of the stack is : " << MyStack.Bottom() << endl;

    MyStack.pop();
    cout << "\nStack After [1] pop :\n";
    MyStack.Print();

    cout << "\n\nitem [3] : " << MyStack.GetItem(3) << endl;

    MyStack.Reverse();
    cout << "\nStack After Reverse :\n";
    MyStack.Print();

    cout << "\n\nStack After Updating Item [2] to 'z' :\n";
    MyStack.UpdateItem(2, 'z');
    MyStack.Print();

    MyStack.InsertAfter(2, 'y');
    cout << "\n\nStack After Inserting item 'y' After item '2' : \n";
    MyStack.Print();

    cout << "\n\nStack After inserting 'O' At the top of the stack :\n";
    MyStack.InsertAtFront('O');
    MyStack.Print();

    system("pause>0");
    return 0;
}


