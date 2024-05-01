#include <iostream>
#include "clsDynamicArray.h"

using namespace std;
int main()
{
    clsDynamicArray <int> MyArray(8);
    MyArray.SetItem(0, 1);
    MyArray.SetItem(1, 2);
    MyArray.SetItem(2, 3);
    MyArray.SetItem(3, 4);
    MyArray.SetItem(4, 5);
    MyArray.SetItem(5, 6);
    MyArray.SetItem(6, 7);
    MyArray.SetItem(7, 8);


    cout << "Is the array Empty? : " << MyArray.IsEmpty() << endl;
    cout << "\nArray items is : \n\n";
    MyArray.PrintArray();

    MyArray.InsertAt(0, 1);
    cout << "\n\nArray After Inserting value = 1, at index '0' :\n";
    MyArray.PrintArray();

    MyArray.DeleteItemAt(3);
    cout << "\nArray after delete item at index '3' :\n";
    MyArray.PrintArray();
    cout << "\nAnd the new size for the array is : " << MyArray.Size() << endl;

    cout << "\nArray after deleting First item :\n";
    MyArray.DeleteFirstItem();
    MyArray.PrintArray();


    cout << "\nArray after deleting last item :\n";
    MyArray.DeleteLastItem();
    MyArray.PrintArray();

    int Index = MyArray.Find(5);
    cout << "\n\nthe index of value '5' is : " << Index << endl << endl;

    cout << "Array Aft(er Deleteing item has value = 6 :\n";
    MyArray.DeleteItem(6);
    MyArray.PrintArray();

    MyArray.Clear();
    if (MyArray.IsEmpty())
    {
        cout << "\nYes Array is Empty.\n";
    }
    else
    {
        cout << "\n\nNo, Array not Empty.\n";
    }

    system("pause>0");
    return 0;
}