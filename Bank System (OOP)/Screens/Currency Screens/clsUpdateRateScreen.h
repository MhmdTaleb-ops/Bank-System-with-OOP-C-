#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidation.h"

class clsUpdateRateScreen : protected clsScreen
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

	static float _ReadRate()
	{
		float NewRate;

		cout << "\nPlease Enter New Rate: ";
		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;

	}

public:

	static void ShowUpateRateScreen()
	{
		string Code;

		_DrawScreenHeader("\tUpdate Rate Screen");


		cout << "\nEnter Currency Code: ";
		Code = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindbyCurrencyCode(Code);

		PrintCurrencyCard(Currency);


		char ans = 'n';

		cout << "\nAre You sure do you Want to Update the rate of this Currency? y/n ";
		cin >> ans;

		if (ans == 'y' || ans == 'Y')
		{

			cout << "Updated Rate \n";
			cout << "________________\n";

			Currency.UpdateRate(_ReadRate());


			cout << "\nRate Upated Succesfully :)\n";

			PrintCurrencyCard(Currency);

		}
	
	}


};

