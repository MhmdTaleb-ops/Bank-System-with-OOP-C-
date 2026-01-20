#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsUtil.h"



class clsCurrency
{
private:
	enum enMode {EmptyMode = 0,UpdateMode = 1};


	enMode  _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float  _Rate;


	static clsCurrency _ConverLineToCurrencyObj(string Line,string Separetor = "#//#")
	{
		vector <string> vCurrency;
		vCurrency = clsString::Split(Line, Separetor);

		return clsCurrency(enMode::UpdateMode,vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));



	}


	static string _ConverCurrencytObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;

	}

	static  vector <clsCurrency> _LoadCurrentDataFromFile()
	{

		vector <clsCurrency> vCurrency;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConverLineToCurrencyObj(Line);

				vCurrency.push_back(Currency);
			}

			MyFile.close();

		}

		return vCurrency;

	}


	static void _SaveDataToFile(vector <clsCurrency> &vUpDatedDataCurrncies)
	{

		fstream MyFile;
		string Line;

		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			
			for (clsCurrency& C : vUpDatedDataCurrncies)
			{
				Line = _ConverCurrencytObjectToLine(C);
				MyFile << Line << endl;
			}

			MyFile.close();

		}

	}


	static clsCurrency _GetEmptyObj()
	{

		return clsCurrency(enMode::EmptyMode,"", "", "", 0);

	}

	 void _Update()
	{
		vector <clsCurrency> vCurrencies = _LoadCurrentDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (C.CurrencyCode() ==  _CurrencyCode)
			{
				C = *this;
				break;

			}

		}
		
		_SaveDataToFile(vCurrencies);


	}

	


public:

	clsCurrency(enMode Mode,string Country,string CurrencyCode, string CurrencyName,float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;



	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode());
		
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

		float Rate()
		{
			return _Rate;
		}

		void UpdateRate(float NewRate)
		{

			_Rate = NewRate;

			_Update();

		}


		void Print()
		{
			cout << "___________________\n";
			cout << "Country     : " << _Country << endl;
			cout << "CurrencyCode: " << _CurrencyCode << endl;
			cout << "CurrencyName: " << _CurrencyName << endl;
			cout << "Rate        : " << _Rate << endl;
			cout << "___________________\n";

		}

		static clsCurrency FindbyCurrencyCode(string CurrencyCode)
		{


			CurrencyCode = clsString::UpperAllString(CurrencyCode);
			
			fstream MyFile;
			MyFile.open("Currencies.txt", ios::in);//read Mode

			if (MyFile.is_open())
			{
				string Line;
				while (getline(MyFile, Line))
				{
					clsCurrency Currency = _ConverLineToCurrencyObj(Line);

					if (clsString::UpperAllString(Currency.CurrencyCode()) == CurrencyCode)
					{

						MyFile.close();
						return Currency;

					}

				}

				MyFile.close();

			}

			return _GetEmptyObj();
		}


		static clsCurrency FindbyCountryName(string Country)
		{

			Country = clsString::UpperAllString(Country);
			fstream MyFile;
			MyFile.open("Currencies.txt", ios::in);//read Mode

			if (MyFile.is_open())
			{
				string Line;
				while (getline(MyFile, Line))
				{
					clsCurrency Currency = _ConverLineToCurrencyObj(Line);
					if (clsString::UpperAllString(Currency.Country()) == Country)
					{
						MyFile.close();
						return Currency;
					}

				}

				MyFile.close();

			}

			return _GetEmptyObj();
		}


	static	bool IsCurrencyExist(string CurrencyCode)
		{
			clsCurrency Currency = clsCurrency::FindbyCurrencyCode(CurrencyCode);

			return (!Currency.IsEmpty());


		}

	static	vector <clsCurrency> GetCurrnciesList()
		{

			return _LoadCurrentDataFromFile();

		}

	 float ConverCurrencyToUSD(float AmountExchange)
	{
		
		return (float)(AmountExchange / Rate());
	}


	float ConvertTotherCurrency(float Amount,clsCurrency Currency2)
	{
		 
		float AmountIn_USD = ConverCurrencyToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{

			return AmountIn_USD;

	}
		

		return (float)(AmountIn_USD * Currency2.Rate());


	}

};

