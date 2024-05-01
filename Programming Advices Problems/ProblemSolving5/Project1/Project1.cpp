#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

int main()
{
	clsDblLinkedList <int> MyDblLinkedList;


	MyDblLinkedList.InsertAtBeginning(5);
	MyDblLinkedList.InsertAtBeginning(4);
	MyDblLinkedList.InsertAtBeginning(3);
	MyDblLinkedList.InsertAtBeginning(2);
	MyDblLinkedList.InsertAtBeginning(1);

	cout << "Double linked list items is :\n";
	MyDblLinkedList.PrintList();

	MyDblLinkedList.InsertAfter(4, 6);
	cout << "\n\nlist items is:\n";
	MyDblLinkedList.PrintList();
	system("pause>0");
	return 0;
}