#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsInputValidation.h";
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalance.h"
#include "clsTransferScreen.h"
#include "clsTransferLogLsitScreen.h"


class clsTransactionsScreen : protected clsScreen
{

private:

    enum enTransactionsOption
    {

        eDeposit = 1, eWithdraw = 2, eTotalBalnce = 3 , eTransfer = 4, eTransferLogList = 5,
        enMainMenue = 6



    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }


    static  void _GoBackToTransactionsMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowTransactions();
    }
     
    static void _ShowDepositScreen()
    {

      /*  cout << "\nDeposit Screen will be her \n";*/
        clsDepositScreen::ShowDepositScreen();

    }

    static void _ShowWithdrawScreen()
    {

        /*cout << "\nWithdraw Screen will be her \n";*/
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalanceScreen()
    {

     /*   cout << "\nTotal Balance Screen will be her \n";*/
        clsTotalBalance::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {

         /*  cout << "\nTransfer Screen will be her \n";*/
        clsTransferScreen::ShowTrnasferScreen();
    }
    
    static void _ShowTransferLogListScreen()
    {
        /*  cout << "\nTransfer Screen will be her \n";*/
        clsTransferLogScreen::ShowTransferLogScreen();
    }


    static void _PerformTransactionsOption(enTransactionsOption Options)
    {
        switch (Options)
        {
        case eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();

        case eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();

        case eTotalBalnce:
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionsMenue();

        case eTransfer :
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();

        }
        case eTransferLogList:
        {
            system("cls");
            _ShowTransferLogListScreen();
            _GoBackToTransactionsMenue();


        }


        case enMainMenue:
        {

        }
    

        }




    }


public:


    static void ShowTransactions()
    {
        if (!_CheckPermissions(clsUser::pTransactions))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen ");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log List.\n";
        cout << setw(37) << left << "" << "\t[6] Back to Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsOption((enTransactionsOption)_ReadMainMenueOption());
    }


};

