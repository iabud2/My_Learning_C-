#include <iostream>
#include "clsUtil.h"
using namespace std;

int main()
{
	clsUtil::Srand();
	cout << "\t\tUtility Library \n\n";
	cout << "------------------------------------------------\n\n";
	int Random_Number = clsUtil::Random_Number(1, 10);
	cout << "Random Number : " << Random_Number << endl;

	cout << "Random Character : " << clsUtil::Random_Character(clsUtil::Mix) << endl;

	cout << "Generate Word : " << clsUtil::Generate_Word(clsUtil::Mix) << endl;

	cout << "Generate Key : " << clsUtil::Generate_Key(clsUtil::Mix) << endl << endl;

	cout << "Generate Keys : " << endl;
	clsUtil::Generated_Keys(5, clsUtil::Mix);

	cout << "\nSwap Functions :\n";
	
	int A = 10, B = 20;
	cout << "Swap int : \n";
	cout << "Before Swap : " << "A = " << A << "  B = " << B << endl;
	clsUtil::Swap(A, B);
	cout << "After Swap  : " << "A = " << A << "  B = " << B << endl;

	double C = 5.6465, D = 8.852;
	cout << "Swap Doubles : \n";
	cout << "Before Swap : " << "C = " << C << "  D = " << D << endl;
	clsUtil::Swap(C, D);
	cout << "After Swap  : " << "C = " << C << "  D = " << D << endl;

	string S1 = "Ahmed", S2 = "Mohammed";
	cout << "Swap String : \n";
	cout << "Before Swap : " << "S1 : " << S1 << "- S2 :" << S2 << endl;
	clsUtil::Swap(S1, S2);
	cout << "After Swap  : " << "S1 : " << S1 << "- S2 :" << S2 << endl;

	int arr[4] = {1, 2, 3, 4};
	string arr1[4] = { "Ahmed", "Khaled", "Abdullah", "Ali" };

	cout << "\nArray of int Before Shuffle : " << endl << endl;
	clsUtil::Print_Array(arr, 4);
	clsUtil::shuffle_Array(arr, 4);
	cout << "\nArray of int After Shuffle : " << endl <<  endl;
	clsUtil::Print_Array(arr, 4);

	cout << "\nArray of String Before Shuffle : " << endl << endl;
	clsUtil::Print_Array(arr1, 4);
	clsUtil::shuffle_Array(arr1, 4);
	cout << "\nArray of String After Shuffle : " << endl << endl;
	clsUtil::Print_Array(arr1, 4);

	cout << "\nArray Filled With Random Numbers: \n";
	int array[10];
	clsUtil::FillArrayWithRandomNumbers(array, 10, 0, 100);
	clsUtil::Print_Array(array, 10);

	cout << "\nFill Array With Random Words : \n";
	string Sarr[5];
	clsUtil::FillArrayWithRandomWords(Sarr, 5, clsUtil::CapitalLetter, 6);
	clsUtil::Print_Array(Sarr, 5);

	cout << "\nArray Filled With Random Keys : \n";
	string Karr[5];
	clsUtil::FillArrayWithRandomKeys(Karr, 5, clsUtil::Digit, 5);
	clsUtil::Print_Array(Karr, 3);

	cout << clsUtil::Tabs(2) << "\nTabs Function\n\n";
	
	string Name = "Ahmed Khaled Mohammed";
	cout << "Name After Encryption : ";
	clsUtil::Encryption(Name);
	cout << Name << endl;

	cout << "Name After Decryption : ";
	clsUtil::Decryption(Name);
	cout << Name << endl;


	system("pause>0");;
	return 0;

}