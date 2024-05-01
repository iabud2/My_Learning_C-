#include <iostream>
#include "clsMyString.h"

using namespace std;

int  main()
{
	clsMyString S1;
	cout << "Value After Do Any thing : " << S1.value << "\n\n";

	S1.value = "Ahmed";
	cout << "S1 value : " << S1.value << "\n\n";
	S1.value = "Ahemd1";
	cout << "S1 value : " << S1.value << "\n\n";
	S1.value = "Ahmed2";
	cout << "S1 value : " << S1.value << "\n\n";

	S1.Undo();
	cout << "S1 value x1 Undo :" << S1.value << "\n\n";
	S1.Undo();
	cout << "S1 value x2 Undo :" << S1.value << "\n\n";	
	S1.Undo();
	cout << "S1 value x3 Undo :" << S1.value << "\n\n";

	S1.Redo();
	cout << "S1 value x1 Redo :" << S1.value << "\n\n";
	S1.Redo();
	cout << "S1 value x2 Redo :" << S1.value << "\n\n";
	S1.Redo();
	cout << "S1 value x3 Redo :" << S1.value << "\n\n";

	system("pause>0");
	return 0;
}