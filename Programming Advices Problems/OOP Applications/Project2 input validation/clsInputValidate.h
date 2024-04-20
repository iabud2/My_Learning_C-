#pragma once
#include "clsDate.h"
#include <iostream>
#include <string>
class clsInputValidate
{

public:

	static bool IsNumberBetween(int Number, int form, int to)
	{
		if (Number >= form && Number <= to)
		{
			return true;
		}
		return false;
	}
	
	static bool IsNumberBetween(double Number, double form, double to)
	{
		if (Number > form && Number < to)
		{
			return true;
		}
		return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{

		//Date>=From && Date<=To
		if ((clsDate::is_Date1_After_Date2(Date, From) || clsDate::is_Date1_equals_to_Date2(Date, From))
			&&
			(clsDate::is_Date1_Before_Date2(Date, To) || clsDate::is_Date1_equals_to_Date2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::is_Date1_After_Date2(Date, To) || clsDate::is_Date1_equals_to_Date2(Date, To))
			&&
			(clsDate::is_Date1_Before_Date2(Date, From) || clsDate::is_Date1_equals_to_Date2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter a valid one : ") 
	{
		int Number;    
		cout << "Please enter Integer number?" << endl;  
		cin >> Number;
		while (cin.fail()) 
		{	
			cin.clear();      
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');         
			cout << ErrorMessage << endl;         
			cin >> Number;     }
		return Number; 
	}

	static int ReadIntNumberBetween(int from , int to, string ErrorMessage = "Number is not within range, enter again:\n")
	{
		int x = ReadIntNumber();
		while (x <= from || x >= to)
		{
			x = ReadIntNumber();
		}
		return x;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter a valid one : ")
	{
		double Number = 0;
		cout << "Please enter Double number?" << endl;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
			cin >> Number;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double from, double to, string ErrorMessage = "Number is not within range, enter again:\n")
	{
		double x = ReadDblNumber();
		do
		{
			x = ReadDblNumber();

		} while (x <= from || x >= to);
		return x;
	}

	static bool IsValidDate(clsDate Date)
	{
		return Date.Validate_Date();
	}



};

