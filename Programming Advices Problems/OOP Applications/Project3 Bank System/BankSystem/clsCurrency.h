#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsString.h"

class clsCurrency
{
private:
	enum enMode {
		EmptyMode = 0, UpdateMode = 1 
	};

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
			stod(vCurrencyData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;

	}

	static  vector <clsCurrency> _LoadCurrencysDataFromFile()
	{

		vector <clsCurrency> vCurrencys;

		fstream CurrenciesFile;
		CurrenciesFile.open("Currencies.txt", ios::in);

		if (CurrenciesFile.is_open())
		{
			string Line;

			while (getline(CurrenciesFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				vCurrencys.push_back(Currency);
			}
			CurrenciesFile.close();
		}
		return vCurrencys;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsCurrency C : vCurrencies)
			{
				DataLine = _ConvertCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(_vCurrencys);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	
	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream CurrenciesFile;
		CurrenciesFile.open("Currencies.txt", ios::in);
		
		if (CurrenciesFile.is_open())
		{
			string line;
			while (getline(CurrenciesFile, line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					CurrenciesFile.close();
					return Currency;
				}

			}
			CurrenciesFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream CurrenciesFile;
		CurrenciesFile.open("Currencies.txt", ios::in);

		if (CurrenciesFile.is_open())
		{
			string line;
			while (getline(CurrenciesFile, line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(line);
				if (clsString::UpperAllString(Currency.CurrencyCode()) == CurrencyCode)
				{
					CurrenciesFile.close();
					return Currency;
				}

			}
			CurrenciesFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency)
	{
		float AmountInUSD = ConvertToUSD(Amount);
		if (Currency.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return float((AmountInUSD * Currency.Rate()));
	}
};

