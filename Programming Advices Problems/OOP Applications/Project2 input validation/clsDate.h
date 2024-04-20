#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <ctime>
#include "clsString.h"
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

class clsDate
{
private:
	short _Day;
	short _Month;
	short _Year;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(short day, short month, short year)
	{
		_Day = day;
		_Month = month;
		_Year = year;
	}

	clsDate(string Date)
	{
		vector <string> vDate = clsString::Split(Date, "/");
		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short DateOrderinYear, short Year)
	{
		clsDate Date = Date_From_Day_Order_in_Year(DateOrderinYear, Year);
		_Day = Date.Day;
		_Month = Date.Month;
		_Year = Date.Year;
	}

	void Set_Day(short Day)
	{
		_Day = Day;
	}

	void Set_Month(short Month)
	{
		_Month = Month;
	}

	void Set_Year(short Year)
	{
		_Year = Year;
	}

	short GetDay()
	{
		return _Day;
	}

	short GetMonth()
	{
		return _Month;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetDay, put = Set_Day)) short Day;
	__declspec(property(get = GetMonth, put = Set_Month)) short Month;
	__declspec(property(get = GetYear, put = Set_Year)) short Year;

	static	bool is_Leap(short Year)
	{
		return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
	}

	bool is_Leap()
	{
		return is_Leap(_Year);
	}

	clsDate Date_From_Day_Order_in_Year(short Number_Of_Days, short Year)
	{
		clsDate Date;
		Date.Year = Year;
		short Remaining_days = Number_Of_Days;
		Date.Month = 1;
		while (true)
		{
			short Month_in_days = Days_In_Month(Year, Date.Month);
			if (Remaining_days > Month_in_days)
			{
				Date.Month++;
				Remaining_days -= Month_in_days;
			}
			else
			{
				Date.Day = Remaining_days;
				break;
			}
		}
		return Date;
	}

	static string Date_To_String(clsDate Date)
	{
		string String_Date;
		String_Date += to_string(Date.Day) + "/";
		String_Date += to_string(Date.Month) + "/";
		String_Date += to_string(Date.Year);
		return String_Date;
	}

	string Date_To_String()
	{
		return Date_To_String(*this);
	}

	void PrintDate()
	{
		cout << "Date is : " << Date_To_String() << endl;
	}

	static short Days_In_Month(short Year, short Month)
	{

		int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // Months of 31 Days (1, 3 , 5, 7, 8, 10, 12)
		if (Month > 12 || Month <= 0)
		{
			return 0;
		}
		return ((Month == 2) ? (is_Leap(Year) ? 29 : 28) : arr[Month - 1]);
	}

	short Days_In_Month()
	{
		return Days_In_Month(_Year, _Month);
	}

	static short Hours_In_Month(short Year, short Month)
	{
		return Days_In_Month(Year, Month) * 24;
	}

	int Hours_In_Month()
	{
		return Hours_In_Month(_Year, _Month);
	}

	static int Minutes_In_Month(short Year, short Month)
	{
		return Hours_In_Month(Year, Month) * 60;
	}

	int Minutes_In_Month()
	{
		return Minutes_In_Month(_Year, _Month);
	}

	static int Seconds_In_Month(int Year, int Month = 12)
	{
		return Minutes_In_Month(Year, Month) * 60;
	}

	int Seconds_In_Month()
	{
		return Seconds_In_Month(_Year, _Month);
	}

	static short Find_Day_Order_In_Week(short Day,short Month, short Year)
	{
		short A = (14 - Month) / 12;
		short y = Year - A;
		short m = Month - (12 * A) - 2;
		short d = ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))) % 7;
		return d;
	}

	static short Find_Day_Order_In_Week(clsDate Date)
	{
		return Find_Day_Order_In_Week(Date.Day, Date.Month, Date.Year);
	}

	short Find_Day_Order_In_Week()
	{
		return Find_Day_Order_In_Week(*this);
	}

	static string Day_Name(short D, short M, short Y)
	{
		int Day = Find_Day_Order_In_Week(D, M, Y);

		string Days_Array[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
		return Days_Array[Day];
	}

	string Day_Name()
	{
		return Day_Name(_Day, _Month, _Year);
	}

	static	string MonthsName(short Month)
	{
		string Days_Array[] = { "Jun", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return Days_Array[Month - 1];
	}

	string MonthsName()
	{
		return MonthsName(_Month);
	}

	static void Month_Calender(short Month, short Year)
	{
		short Day = Find_Day_Order_In_Week(1, Month, Year);
		short Number_Of_days = Days_In_Month(Year, Month);
		// calender Head
		cout << "\n  _______________" << MonthsName(Month) << "_______________\n\n";
		for (short D = 0; D < 7; D++)
		{
			cout << setw(5) << left << Day_Name(D, Month, Year);
		}
		cout << endl;
		// calender Body
		int i;
		for (i = 0; i < Day; i++)
		{
			cout << "     ";
		}
		for (int j = 1; j <= Number_Of_days; j++)
		{
			cout << setw(5) << left << j;
			if (++i == 7)
			{
				i = 0;
				cout << endl;
			}
		}
		cout << "\n_________________________________\n";
	}

	void Month_Calender()
	{
		Month_Calender(_Month, _Year);
	}

	static void Year_Calender(short Year)
	{
		printf("\n_________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("_________________________________\n");
		for (int i = 1; i <= 12; i++)
		{
			Month_Calender(i, Year);
		}
	}

	void Year_Calender()
	{
		Year_Calender(_Year);
	}

	static short Days_From_Beginning(short Day, short Month, short Year)
	{
		short sum = 0;
		for (int i = 1; i < Month; i++)
		{
			sum += Days_In_Month(Year, i);
		}
		sum += Day;
		return sum;
	}

	short Days_From_Beginning()
	{
		return Days_From_Beginning(_Day, _Month, _Year);
	}

	static short Days_From_Beginning(clsDate Date)
	{
		return Days_From_Beginning(Date.Day, Date.Month, Date.Year);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short sum = 0;
		for (int i = 1; i < Month; i++)
		{
			sum += Days_In_Month(Year, i);
		}
		sum += Day;
		return sum;
	}

	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
	}

	static clsDate Date_After_Number_of_Days(clsDate& Date, int Days)
	{
		int Remaining_Days = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
		Date.Month = 1;
		short Month_Days = 0;
		while (true)
		{
			Month_Days = Days_In_Month(Date.Year, Date.Month);
			if (Remaining_Days > Month_Days)
			{
				Remaining_Days -= Month_Days;
				Date.Month++;
				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
			else
			{
				Date.Day = Remaining_Days;
				break;
			}
		}
		return Date;
	}

	void Date_After_Number_of_Days(int Days)
	{
		Date_After_Number_of_Days(*this, Days);
	}

	static bool is_Date1_Before_Date2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false) : false);
	}

	bool is_Date1_Before_Date2(clsDate Date2)
	{
		return is_Date1_Before_Date2(*this, Date2);
	}

	static bool is_Date1_equals_to_Date2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
	}

	bool is_Date1_equals_to_Date2(clsDate Date2)
	{
		return is_Date1_equals_to_Date2(*this, Date2);
	}

	static bool is_Last_Day_In_Month(clsDate Date)
	{
		return (Date.Day == Days_In_Month(Date.Year, Date.Month));
	}

	bool is_Last_Day_In_Month()
	{
		return is_Last_Day_In_Month(*this);
	}

	static bool is_Last_Month(clsDate Date)
	{
		return (Date.Month == 12);
	}

	bool is_Last_Month()
	{
		return is_Last_Month(*this);
	}

	static clsDate Increase_Date_By_One_day(clsDate& Date)
	{
		if (is_Last_Day_In_Month(Date))
		{
			if (is_Last_Month(Date))
			{
				Date.Year++;
				Date.Day = 1;
				Date.Month = 1;
			}
			else
			{
				Date.Month++;
				Date.Day = 1;
			}
		}
		else
		{
			Date.Day++;
		}
		return Date;
	}

	void Increase_Date_By_One_day()
	{
		Increase_Date_By_One_day(*this);
	}

	static clsDate Increase_Date_By_X_Day(clsDate& Date, int X_Days)
	{
		for (int i = 1; i <= X_Days; i++)
		{
			Date = Increase_Date_By_One_day(Date);
		}

		return Date;
	}

	void Increase_Date_By_X_Day(int X_Days)
	{
		Increase_Date_By_X_Day(*this, X_Days);
	}

	static clsDate Increase_Date_By_One_Week(clsDate& Date)
	{
		Date = Increase_Date_By_X_Day(Date, 7);
		return Date;
	}

	void Increase_Date_By_One_Week()
	{
		Increase_Date_By_One_Week(*this);
	}

	static clsDate Increase_Date_By_X_Weeks(clsDate& Date, int X_Weaks)
	{
		for (int i = 1; i <= X_Weaks; i++)
		{
			Date = Increase_Date_By_One_Week(Date);
		}
		return Date;
	}

	void Increase_Date_By_X_Weeks(int X_Weaks)
	{
		Increase_Date_By_X_Weeks(*this, X_Weaks);
	}

	static clsDate Increase_Date_By_One_Month(clsDate& Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}
		short Number_of_Days_in_Month = Days_In_Month(Date.Year, Date.Month);
		if (Date.Day > Number_of_Days_in_Month)
		{
			Date.Day = Number_of_Days_in_Month;
		}
		return Date;
	}

	void Increase_Date_By_One_Month()
	{
		Increase_Date_By_One_Month(*this);
	}

	static clsDate Increase_Date_By_X_Month(clsDate& Date, int X_Months)
	{
		for (int i = 1; i <= X_Months; i++)
		{
			Date = Increase_Date_By_One_Month(Date);
		}
		return Date;
	}

	void Increase_Date_By_X_Month(int X_Months)
	{
		 Increase_Date_By_X_Month(*this, X_Months);
	}

	static clsDate Increase_Date_By_One_Year(clsDate& Date)
	{
		Date.Year++;
		return Date;
	}

	void Increase_Date_By_One_Year()
	{
		Increase_Date_By_One_Year(*this);
	}

	static clsDate Increase_Date_By_X_Years(clsDate& Date, int X_Years)
	{
		Date.Year += X_Years;
		return Date;
	}

	void Increase_Date_By_X_Years(int X_Years)
	{
		Increase_Date_By_X_Years(*this, X_Years);
	}

	static clsDate Increase_Date_By_One_Decade(clsDate& Date)
	{
		Date.Year += 10;
		return Date;
	}

	void Increase_Date_By_One_Decade()
	{
		 Increase_Date_By_One_Decade(*this);
	}

	static clsDate Increase_Date_By_X_Decades(clsDate& Date, int X_Decades)
	{
		Date.Year += X_Decades * 10;
		return Date;
	}

	void Increase_Date_By_X_Decades(int X_Decades)
	{
		Increase_Date_By_X_Decades(*this, X_Decades);
	}

	static clsDate Increase_Date_By_One_Century(clsDate& Date)
	{
		Date.Year += 100;
		return Date;
	}

	void Increase_Date_By_One_Century()
	{
		Increase_Date_By_One_Century(*this);
	}

	static clsDate Increase_Date_By_One_Millennium(clsDate& Date)
	{
		Date.Year += 1000;
		return Date;
	}

	void Increase_Date_By_One_Millennium()
	{
		Increase_Date_By_One_Millennium(*this);
	}

	static bool is_First_Day_In_Month(clsDate Date)
	{
		return (Date.Day == 1) ? true : false;
	}

	bool is_First_Day_In_Month()
	{
		return is_First_Day_In_Month(*this);
	}

	static bool is_First_Month(clsDate Date)
	{
		return (Date.Month == 1) ? true : false;
	}

	bool is_First_Month()
	{
		return is_First_Month(*this);
	}

	static clsDate Decrease_Date_By_One_day(clsDate& Date)
	{
		if (is_First_Day_In_Month(Date))
		{
			if (is_First_Month(Date))
			{
				Date.Year--;
				Date.Month = 12;
				Date.Day = Days_In_Month(Date.Year, Date.Month);
			}
			else
			{
				Date.Month--;
				Date.Day = Days_In_Month(Date.Year, Date.Month);
			}
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}

	void Decrease_Date_By_One_day()
	{
		Decrease_Date_By_One_day(*this);
	}

	static clsDate Decrease_Date_By_X_Day(clsDate& Date, int X_Days)
	{
		for (int i = 1; i <= X_Days; i++)
		{
			Date = Decrease_Date_By_One_day(Date);
		}

		return Date;
	}

	void Decrease_Date_By_X_Day(int X_Days)
	{
		Decrease_Date_By_X_Day(*this, X_Days);
	}

	static clsDate Decrease_Date_By_One_Week(clsDate& Date)
	{
		Date = Decrease_Date_By_X_Day(Date, 7);
		return Date;
	}

	void Decrease_Date_By_One_Week()
	{
		Decrease_Date_By_One_Week(*this);
	}

	static clsDate Deacrease_Date_By_X_Weaks(clsDate& Date, int X_Weaks)
	{
		for (int i = 1; i <= X_Weaks; i++)
		{
			Date = Decrease_Date_By_One_Week(Date);
		}
		return Date;
	}

	void Deacrease_Date_By_X_Weaks(int X_Weaks)
	{
		Deacrease_Date_By_X_Weaks(*this, X_Weaks);
	}

	static	clsDate Decrease_Date_By_One_Month(clsDate& Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}
		short Number_of_Days_in_Month = Days_In_Month(Date.Year, Date.Month);
		if (Date.Day > Number_of_Days_in_Month)
		{
			Date.Day = Number_of_Days_in_Month;
		}
		return Date;
	}

	void Decrease_Date_By_One_Month()
	{
		Decrease_Date_By_One_Month(*this);
	}

	static clsDate Decrease_Date_By_X_Month(clsDate& Date, int X_Months)
	{
		for (int i = 1; i <= X_Months; i++)
		{
			Date = Decrease_Date_By_One_Month(Date);
		}
		return Date;
	}

	void Decrease_Date_By_X_Month(int X_Months)
	{
		Decrease_Date_By_X_Month(*this, X_Months);
	}

	static clsDate Decrease_Date_By_One_Year(clsDate& Date)
	{
		Date.Year--;
		return Date;
	}

	void Decrease_Date_By_One_Year()
	{
		Decrease_Date_By_One_Year(*this);
	}

	static clsDate Deacrese_Date_By_X_Years(clsDate& Date, int X_Years)
	{
		Date.Year -= X_Years;
		return Date;
	}

	void Deacrese_Date_By_X_Years(int X_Years)
	{
		Deacrese_Date_By_X_Years(*this, X_Years);
	}

	static clsDate Decreace_Date_By_One_Decade(clsDate& Date)
	{
		Date.Year -= 10;
		return Date;
	}

	void Decreace_Date_By_One_Decade()
	{
		Decreace_Date_By_One_Decade(*this);
	}

	static clsDate Decrease_Date_By_X_Decades(clsDate& Date, int X_Decades)
	{
		Date.Year -= X_Decades * 10;
		return Date;
	}

	void Decrease_Date_By_X_Decades(int X_Decades)
	{
		Decrease_Date_By_X_Decades(*this, X_Decades);
	}

	static clsDate Decrease_Date_By_One_Century(clsDate& Date)
	{
		Date.Year -= 100;
		return Date;
	}

	void Decrease_Date_By_One_Century()
	{
		Decrease_Date_By_One_Century(*this);
	}

	static clsDate Decrease_Date_By_One_Millennium(clsDate& Date)
	{
		Date.Year -= 1000;
		return Date;
	}

	void Decrease_Date_By_One_Millennium()
	{
		Decrease_Date_By_One_Millennium(*this);
	}

	static short Days_In_Year(short Year)
	{
		return (is_Leap(Year)) ? 366 : 365;
	}

	short Days_In_Year()
	{
		return Days_In_Year(_Year);
	}

	static bool Is_End_Of_Week(clsDate Date)
	{
		return (Find_Day_Order_In_Week(Date) == 6) ? true : false;
	}

	bool Is_End_Of_Week()
	{
		return Is_End_Of_Week(*this);
	}

	static bool Is_Weekend(clsDate Date)
	{
		return (Find_Day_Order_In_Week(Date) == 5) ? true : (Find_Day_Order_In_Week(Date) == 6) ? true
			: false;
	}

	bool Is_Weekend()
	{
		return Is_Weekend(*this);
	}

	static bool Is_Business_Day(clsDate Date)
	{
		return (Is_Weekend(Date)) ? false : true;
	}

	bool Is_Business_Day()
	{
		return Is_Business_Day(*this);
	}

	static short Days_Until_The_End_Of_Week(clsDate Date)
	{
		return (6 - Find_Day_Order_In_Week(Date));
	}

	short Days_Until_The_End_Of_Week()
	{
		return Days_Until_The_End_Of_Week(*this);
	}

	static short Days_Until_The_End_Of_Month(clsDate Date)
	{
		return (Days_In_Month(Date.Year, Date.Month) - Date.Day);
	}
	 
	short Days_Until_The_End_Of_Month()
	{
		return Days_Until_The_End_Of_Month(*this);
	}

	static short Days_Until_The_End_Of_Year(clsDate Date)
	{
		return (Days_In_Year(Date.Year) - Days_From_Beginning(Date));
	}

	short Days_Until_The_End_Of_Year()
	{
		return Days_Until_The_End_Of_Year(*this);
	}

	static void Swap_Dates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;
		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;
		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;
	}

	void Swap_Dates(clsDate &Date2)
	{
		Swap_Dates(*this, Date2);
	}

	static int Diff_In_Days(clsDate Date1, clsDate Date2, bool includ_Current_Day = false)
	{
		int Days = 0;
		short Swap_Flag = 1;
		if (!is_Date1_Before_Date2(Date1, Date2))
		{
			Swap_Dates(Date1, Date2);
			Swap_Flag = -1;
		}
		while (is_Date1_Before_Date2(Date1, Date2))
		{
			Days++;
			Date1 = Increase_Date_By_One_day(Date1);
		}
		return (includ_Current_Day) ? ++Days * Swap_Flag : Days * Swap_Flag;
	}

	int Diff_In_Days(clsDate Date2)
	{
		return Diff_In_Days(*this, Date2);
	}

	static short Calculate_Busnis_Days(clsDate from, clsDate to)
	{
		short Days = 0;
		while (is_Date1_Before_Date2(from, to))
		{
			if (Is_Business_Day(from))
				Days++;
			from = Increase_Date_By_One_day(from);
		}
		return Days;
	}

	short Calculate_Busnis_Days(clsDate to)
	{
		return Calculate_Busnis_Days(*this, to);
	}

	static short Calculate_Vacation_Days(clsDate from, clsDate to)
	{
		return Calculate_Busnis_Days(from, to);
	}

	short Calculate_Vacation_Days(clsDate Date2)
	{
		return Calculate_Vacation_Days(*this, Date2);
	}

	static clsDate Days_to_vacation(clsDate from, int Calculate_Vacation_Days)
	{
		for (int i = 1; i <= Calculate_Vacation_Days; i++)
		{
			if (Is_Business_Day(from))
				from = Increase_Date_By_One_day(from);
		}
		return from;
	}

	void Days_to_vacation(int Calculate_Vacation_Days)
	{
		Days_to_vacation(*this, Calculate_Vacation_Days);
	}

	static bool is_Date1_After_Date2(clsDate Date1, clsDate Date2)
	{
		return (!is_Date1_Before_Date2(Date1, Date2) && !is_Date1_equals_to_Date2(Date1, Date2));
	}
	
	bool is_Date1_After_Date2(clsDate Date2)
	{
		return is_Date1_After_Date2(*this, Date2);
	}

	enum enDateCompare
	{
		Before = -1,
		Equals = 0,
		After = 1
	};

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (is_Date1_Before_Date2(Date1, Date2))
		{
			return enDateCompare(-1);
		}
		if (is_Date1_equals_to_Date2(Date1, Date2))
		{
			return enDateCompare(0);
		}
		if (is_Date1_After_Date2(Date1, Date2))
		{
			return enDateCompare(1);
		}
	}

	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	static bool Validate_Date(clsDate Date)
	{
		if (Date.Day > Days_In_Month(Date.Year, Date.Month) || Date.Day <= 0)
			return false;
		if (Date.Month > 12 || Date.Month <= 0)
			return false;
		return true;
	}
	
	bool Validate_Date()
	{
		return Validate_Date(*this);
	}

	string Format_Date(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string Format_Date_String;
		Format_Date_String = clsString::Replace_Word_in_String(DateFormat, "dd", to_string(Date.Day));
		Format_Date_String = clsString::Replace_Word_in_String(DateFormat, "mm", to_string(Date.Month));
		Format_Date_String = clsString::Replace_Word_in_String(DateFormat, "yyyy", to_string(Date.Year));
		return Format_Date_String;
	}

};

