#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "clsString.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsInputValidation.h"
#include "clsMainScreen.h"
#include "clsCurrnciesListScreen.h"
#include "clsFindCurrencyscreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrenciesCulculatorScreen.h"

class clsCurrencyScreen : protected clsScreen
{
private:

	enum enCurrencyMenue
	{
		eCurrenciesList = 1, eFindCurrency = 2, eUpdateCurrency = 3, eCurrencyCalculator = 4,
		eBackMainMenue = 5
	};

	 static short _ReadCurrencyMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	 static  void _GoBackCurrenciesScreen()
	 {
		 cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		 system("pause>0");
		 ShowCurrnciesMenueScreen();
	 }

	static void _ShowListCurrncies()
	{

	/*	cout << "in Process...";*/
		clsCurrnciesListScreen::ShowCurrenciesListScreen();

	}

	static void _ShowFindCurrncy()
	{

	/*	cout << "in Process...";*/

		clsFindCurrencyscreen::ShowFindCurrencyScreen();


	}

	static void _ShowUpdateCurrencyRate()
	{

	/*	cout << "in Process...";*/

		clsUpdateRateScreen::ShowUpateRateScreen();


	}

	static void _ShowCurrencyCalculator()
	{

	/*	cout << "in Process...";*/
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

	}

static	void _PerformCurrnciesMenueOption(enCurrencyMenue Option)
	{
		switch (Option)
		{

		case eCurrenciesList :
		{
			system("cls");
			_ShowListCurrncies();
			_GoBackCurrenciesScreen();
			break;

		}
		case eFindCurrency:
		{
			system("cls");
			_ShowFindCurrncy();
			_GoBackCurrenciesScreen();
			break;
		}
		case eUpdateCurrency:
		{
			system("cls");
			_ShowUpdateCurrencyRate();
			_GoBackCurrenciesScreen();
			break;

		}

		case eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackCurrenciesScreen();
			break;

		}


		case eBackMainMenue:
		{


		}


		}

	}


public:

	static void  ShowCurrnciesMenueScreen()
	{

		system("cls");
		_DrawScreenHeader("\t Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t Currency Exchnge Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currncies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrnciesMenueOption((enCurrencyMenue)_ReadCurrencyMenueOption());

	}


};

