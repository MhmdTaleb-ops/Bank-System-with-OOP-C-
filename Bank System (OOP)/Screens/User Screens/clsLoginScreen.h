#pragma once
#include <iostream>
#include "Global.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "clsInputValidation.h"


class clsLoginScreen : protected clsScreen
{

	static bool _Login()
	{
		
		short LoginFaildCount = 0;
		string UserName , Password ;
		bool LoginFaild = false;

			do
			{

				if (LoginFaild)
				{
					LoginFaildCount++;
					cout << "\nInvalid UserName/Password!\n";
					cout << "You have " <<  3 - LoginFaildCount << " Trails to login\n";
				
				}

				if (LoginFaildCount == 3)
				{
					cout << "\nThe system is locked due to exhausting your number of login attempts!\n";
					return false;

				}

				cout << "\nEnter UserName: \n";
				UserName = clsInputValidate::ReadString();

				cout << "Enter Password: \n";
				Password = clsInputValidate::ReadString();


				CurrentUser = clsUser::Find(UserName, Password);

				LoginFaild = CurrentUser.IsEmpty();
				


			} while (LoginFaild);

			CurrentUser.RegisterLogin();
			clsMainScreen::ShowMainMenue();
			return true;

		

	}

public:

	static void ShowLoginScreen()
	{
		while(true)
		{

			system("cls");
			_DrawScreenHeader("\t Login Screen ");
			if (!_Login())
			{

				break;
			}
			
			
		
		}


	}


};
