#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsInputValidation.h";
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUserScreen.h"
#include "clsLoginRegister.h"
#include "clsCurrencyScreen.h"

#include "Global.h"
using namespace std;

class clsMainScreen :protected clsScreen
{


private:

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8 ,eCurrenceisMenue,eExit = 10 
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {

         clsClientListScreen::ShowClientsList();

    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        clsFilndClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
     /*   cout << "\nTransactions Menue Will be here...\n";*/

        clsTransactionsScreen::ShowTransactions();
        _GoBackToMainMenue();
    }

    static void _ShowManageUsersMenue()
    {
        /* cout << "\nUsers Menue Will be here...\n";*/
        clsManageUsersScreen::ShowManageUsersMenue();
        _GoBackToMainMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
       /*  cout << "\nLoginRegister Will be here...\n";*/
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrenciesMenue()
    {
         cout << "\n Currencies Menue Will be here...\n";
         clsCurrencyScreen::ShowCurrnciesMenueScreen();
        _GoBackToMainMenue();
    }

    static void _Logout()
    {
       
        CurrentUser = clsUser::Find("", "");

    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
         
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
           
            break;
        case enMainMenueOptions::eLoginRegister :
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();

        case enMainMenueOptions::eCurrenceisMenue:
        {
            system("cls");
            _ShowCurrenciesMenue();
            _GoBackToMainMenue();
            break;
        }


        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }

    }

public:

    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[01] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[02] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[03] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[04] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[05] Find Client.\n";
        cout << setw(37) << left << "" << "\t[06] Transactions.\n";
        cout << setw(37) << left << "" << "\t[07] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[08] Login Register.\n";
        cout << setw(37) << left << "" << "\t[09] Currencies Menue.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

