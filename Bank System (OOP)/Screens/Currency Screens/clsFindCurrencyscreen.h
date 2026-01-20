#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidation.h"


class clsFindCurrencyscreen : protected clsScreen
{
private:

	static void PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "___________________\n";
		cout << "Country   : " << Currency.Country() << endl;
		cout << "Code      : " << Currency.CurrencyCode() << endl;
		cout << "Name      : " << Currency.CurrencyName() << endl;
		cout << "Rate/(1$) = " << Currency.Rate() << endl;
		cout << "___________________\n";


	}

	static short _ReadOption()
	{
		short Option = 0;
		cout << "\nFnid By: [1] Code Or [2] Country? ";
		Option = clsInputValidate::ReadShortNumberBetween(1, 2);
		return Option;

	}

	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :) \n\n";

			PrintCurrencyCard(Currency);


		}
		else
		{

			cout << "\nCurrency not Found :( \n\n";


		}





	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");

		string Code = "", Country = "";

		if (_ReadOption() == 1)
		{
			cout << "\nEnter CurrencyCode: ";
			Code = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindbyCurrencyCode(Code);
			_ShowResult(Currency);
		}
		else
		{
			cout << "\nEnter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindbyCountryName(Country);
			_ShowResult(Currency);
		}
	}

};

