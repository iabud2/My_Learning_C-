#include <iostream>
#include "clsMyQueueArr.h"
int main()
{
	clsMyQueueArr <string> MyQueue;
	MyQueue.push("Ahmed");
	MyQueue.push("Osama");
	MyQueue.push("Khaled");
	MyQueue.push("Omar");
	MyQueue.push("Sara");
	cout << "Queue Items:\n";
	MyQueue.Print();

	cout << "\n\nFront Item in Queue is : " << MyQueue.front() << endl;

	MyQueue.pop();
	cout << "\nQueue After pop item :\n";
	MyQueue.Print();

	cout << "\n\nQueue Size is : " << MyQueue.Size() << endl;
	cout << "\nItem in the front of Queue is : " << MyQueue.front() << endl;
	cout << "\nLast item in the Queue is : " << MyQueue.back() << endl;

	cout << "\n\nItem number (2) in Queue is : " << MyQueue.GetItem(2);

	MyQueue.Reverse();
	cout << "\n\nQueue After Reverse :\n";
	MyQueue.Print();

	MyQueue.UpdateItem(2, "Abdullah");
	cout << "\n\nQueue After Updating item number '2' to 'Abdullah' :\n";
	MyQueue.Print();

	MyQueue.InsertAfter(2, "Mahamoud");
	cout << "\n\nQueue After Insert item 'Mahmoud' After Item number '2' : \n";
	MyQueue.Print();

	MyQueue.InsertAtFront("Mona");
	cout << "\n\nQueue After insert item 'Mona' at Front : \n";
	MyQueue.Print();


	MyQueue.InsertAtBack("Fahad");
	cout << "\n\nQueue After inser item 'Fahad' at End : \n";
	MyQueue.Print();

	system("pause>0");
	return 0;
}
