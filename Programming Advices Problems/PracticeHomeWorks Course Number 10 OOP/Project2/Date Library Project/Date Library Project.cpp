#pragma warning(disabled : 4996)
#include <iostream>
#include "clsDate.h"
#include "clsPeriod.h"
using namespace std;

int main()
{
	clsDate Date1;
	clsDate Date2(20, 20, 2030);
	clsDate Date3("2/2/2022");
	clsDate Date4(250, 2023);
	
	Date1.PrintDate();
	Date2.PrintDate();
	Date3.PrintDate();
	Date4.PrintDate();
	
	//Days in Month, Hours in Year, Minutes in Year, Seconds in Year:

	cout << "1- Days in Month : " << Date1.Days_In_Month() << endl;
	cout << "2- Days in month : " << clsDate::Days_In_Month(2024, 2) << endl << endl;

	cout << "1- Hours in Month : " << Date1.Hours_In_Month() << endl;
	cout << "2- Hours in Month: " << clsDate::Hours_In_Month(2024, 4) << endl << endl;

	cout << "1- Minutes in Month : " << Date1.Minutes_In_Month() << endl;
	cout << "2- Minutes in Month : " << clsDate::Minutes_In_Month(2024, 4) << endl << endl;

	cout << "1- Seconds in Month : " << Date1.Seconds_In_Month() << endl;
	cout << "2- Seconds in Month : " << clsDate::Seconds_In_Month(2024, 4) << endl << endl;

	//------------------------------------------------------------------------------------
	//Day Order From Month : 

	cout << "1- Day Order in Month : " << Date1.Find_Day_Order_In_Week() << endl;
	cout << "2- Day Order in Month: " << clsDate::Find_Day_Order_In_Week(4, 2024, 6) << endl << endl;

	//-------------------------------------------------------------------------------------
	//Day Name :

	cout << "1- Day Name : " << Date1.Day_Name() << endl;
	cout << "2- Day Name : " << clsDate::Day_Name(6, 4, 2024) << endl << endl;

	//-------------------------------------------------------------------------------------
	//Month Calender :
	
	cout << "\nMonth Calender 1:";
	Date1.Month_Calender();
	cout << "\nMonth Calender 2:";
	clsDate::Month_Calender(4, 2024);
	cout << "\n\n";
	
	//--------------------------------------------------------------------------------------
	//Year Calender :

	cout << "\nYear Calender 1:";
	Date1.Year_Calender();
	cout << "\nYear Calender 2: ";
	clsDate::Year_Calender(2024);
	cout << "\n\n";

	//--------------------------------------------------------------------------------------
	//Days From The Beginning :

	cout << "1- Days From Beginning :" << Date1.Days_From_Beginning() << endl;
	cout << "2- Days From Beginning :" << clsDate::Days_From_Beginning(30, 1, 2024) << endl << endl;

	//--------------------------------------------------------------------------------------
	//Date After Number Of Days & Days from The begginning of The Year :
	
	cout << "1- Date From the Beginning Of The Year : " << Date1.NumberOfDaysFromTheBeginingOfTheYear() << endl;
	cout << "2- Date Form The Beginning Of The Year : " << clsDate::NumberOfDaysFromTheBeginingOfTheYear(6, 4, 2024) << endl << endl;

	Date1.Date_After_Number_of_Days(5);
	clsDate Date5(10, 10, 2024);
	cout << "1- Date After 5 Days : ";
	Date1.PrintDate();
	
	clsDate::Date_After_Number_of_Days(Date5, 5);
	cout << "2- Date After 5 Days : ";
	Date5.PrintDate();
	cout << endl << endl;
	
	//---------------------------------------------------------------------------------------
	//is Date1 Before Or Equals to Date2:
	if (Date1.is_Date1_Before_Date2(Date2))
		cout << "Yes\n";
	else
		cout << "No\n";
	if (clsDate::is_Date1_Before_Date2(Date1, Date2))
		cout << "Yes\n\n";
	else
		cout << "No\n\n";


	if (Date1.is_Date1_equals_to_Date2(Date2))
		cout << "Yes\n";
	else
		cout << "No\n";
	if (clsDate::is_Date1_equals_to_Date2(Date1, Date2))
		cout << "Yes\n\n";
	else
		cout << "No\n\n";
	//----------------------------------------------------------------------------------------
	//Is last Day in (Month/Year) :
	
	if (Date2.is_Last_Day_In_Month())
		cout << "Yes\n";
	else
		cout << "No\n";

	//You Can Use:
	//clsDate::is_Last_Day_In_Month(Date2);

	if (Date2.is_Last_Month())
		cout << "Yes\n\n";
	else
		cout << "No\n\n";
	//or:
	//clsDate::is_Last_Month(Date1);
	
	//------------------------------------------------------------------------------------------
	//Increase Date By One Day:

	Date1.Increase_Date_By_One_day();
	cout << "Date1 After Adding 1 Day :";
	Date1.PrintDate();
	cout << endl;
	//Or clsDate::Increase_Date_By_One_day(Date1);
	
	//--------------------------------------------------------------------------------------------
	//Diff In Days :

	cout << "1- Diff in Days :" << Date2.Diff_In_Days(Date1) << endl << endl;

	//--------------------------------------------------------------------------------------------
	//Increase Date Functions:

	Date1.Increase_Date_By_X_Day(10);
	cout << "After 10 Days ";
	Date1.PrintDate();
	cout << endl;
	
	Date1.Increase_Date_By_One_Week();
	cout << "After Adding 1 Week ";
	Date1.PrintDate();
	cout << endl;

	Date1.Increase_Date_By_X_Weeks(2);
	cout << "After Adding 2 Weeks ";
	Date1.PrintDate();
	cout << endl;

	Date1.Increase_Date_By_One_Month();
	cout << "After Adding 1 Month ";
	Date1.PrintDate();
	cout << endl;

	Date1.Increase_Date_By_X_Month(2);
	cout << "After Adding 2 Months ";
	Date1.PrintDate();
	cout << endl;

	Date1.Increase_Date_By_One_Year();
	cout << "After Adding 1 Year ";
	Date1.PrintDate();
	cout << endl;

	Date1.Increase_Date_By_X_Years(2);
	cout << "After Adding 2 Years ";
	Date1.PrintDate();
	cout << endl;

	Date1.Increase_Date_By_One_Decade();
	cout << "After Adding 1 Decade ";
	Date1.PrintDate();
	cout << endl;

	Date1.Increase_Date_By_X_Decades(2);
	cout << "After Adding 2 Decades ";
	Date1.PrintDate();
	cout << endl;

	Date1.Increase_Date_By_One_Century();
	cout << "After Adding 1 Century ";
	Date1.PrintDate();
	cout << endl;

	Date1.Increase_Date_By_One_Millennium();
	cout << "After Adding 1 Millennium ";
	Date1.PrintDate();
	cout << endl;

	//--------------------------------------------------------------------------------------------
	// Decrease Date Functions:

	Date1.Decrease_Date_By_One_day();
	cout << "Before One Day ";
	Date1.PrintDate();
	cout << endl;

	Date1.Decrease_Date_By_X_Day(10);
	cout << "Before ten Days ";
	Date1.PrintDate();
	cout << endl;

	Date1.Decrease_Date_By_One_Week();
	cout << "Before One Week ";
	Date1.PrintDate();
	cout << endl;

	Date1.Deacrease_Date_By_X_Weaks(2);
	cout << "Before 2 Week ";
	Date1.PrintDate();
	cout << endl;


	Date1.Decrease_Date_By_One_Month();
	cout << "Before 1 Month ";
	Date1.PrintDate();
	cout << endl;

	Date1.Decrease_Date_By_X_Month(2);
	cout << "Before 2 Months ";
	Date1.PrintDate();
	cout << endl;

	Date1.Decrease_Date_By_One_Year();
	cout << "Before One Year ";
	Date1.PrintDate();
	cout << endl;
	
	Date1.Deacrese_Date_By_X_Years(10);
	cout << "Before ten Years ";
	Date1.PrintDate();
	cout << endl;

	Date1.Decreace_Date_By_One_Decade();
	cout << "Before One Decade ";
	Date1.PrintDate();
	cout << endl;

	Date1.Decrease_Date_By_X_Decades(2);
	cout << "Before 2 Decade ";
	Date1.PrintDate();
	cout << endl;

	Date1.Decrease_Date_By_One_Century();
	cout << "Before 1 Century ";
	Date1.PrintDate();
	cout << endl;

	Date1.Decrease_Date_By_One_Millennium();
	cout << "Before 1 Millennium ";
	Date1.PrintDate();
	cout << endl;
	//--------------------------------------------------------------------------------------------
	//More Functions :

	cout << "Days In Year : " << Date1.Days_In_Year() << endl << endl;
	
	if (Date1.Is_End_Of_Week())
		cout << "Yes , it's End Of Week\n\n";
	else
		cout << "No, Not End Of Week\n\n";
	//_-_-_-
	if (Date1.Is_Weekend())
		cout << "Yes , it's Weekend\n\n";
	else
		cout << "No, Not Weekend\n\n";
	//_-_-_-
	if (Date1.Is_Business_Day())
		cout << "Yes , it's a Business_Day\n\n";
	else
		cout << "No, Not a Business_Day\n\n";

	//_-_-_-
	cout << "Days Until End Of Week : " << Date1.Days_Until_The_End_Of_Week() << endl << endl;
	//_-_-_-
	cout << "Days Until End Of Month : " << Date1.Days_Until_The_End_Of_Month() << endl << endl;
	//_-_-_-
	cout << "Days Until End Of Month : " << Date1.Days_Until_The_End_Of_Year() << endl << endl;
	//_-_-_-
	clsDate DateV(20, 2, 2022);
	cout << "Vacation Days : " << Date3.Calculate_Vacation_Days(DateV) << endl << endl;
	//_-_-_-
	Date2.Days_to_vacation(20);
	cout << "After 20 Days Vacation : ";
	Date2.PrintDate();
	cout << endl;

	//-----------------------------------------------------------------------------------------
	//Period Functions:
	clsPeriod Period1(clsDate(1, 1, 2022), clsDate(10, 1, 2022));
	Period1.Print();

	cout << "\n";

	clsPeriod Period2(clsDate(3, 1, 2022), clsDate(5, 1, 2022));
	Period2.Print();

	//You can check like this
	cout << endl << Period1.IsOverLapWith(Period2) << endl;

	
	//Also you can call the static method and send period 1 and period 2
	cout << endl << clsPeriod::IsOverlapPeriods(Period1, Period2) << endl;

	system("pause>0");
	return 0;
}