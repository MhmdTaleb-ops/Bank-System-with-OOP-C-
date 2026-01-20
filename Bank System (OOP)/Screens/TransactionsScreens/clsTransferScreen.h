#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidation.h";
#include "clsScreen.h";
#include "ClsBankClients.h"
#include "ClsDate.h"
#include "clsString.h"
#include "Global.h"
class clsTransferScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient& Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadACcountNumber(string Msg = "")
    {

        string Acc;
        cout << Msg << endl;
        Acc = clsInputValidate::ReadString();


        while (!clsBankClient::IsClientExist(Acc))
        {

            cout << "\nClient not Fount, Enter Another one : ";
            Acc = clsInputValidate::ReadString();


        }

        return Acc;
    }

    static double _ReadAmount(clsBankClient SourceClient)
    {

        double Amount = 0;
        cout << "\n\nEnter Transfer Amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        while (SourceClient.AccountBalance < Amount && Amount < 0)
        {

            cout << "\nAmount Exceeds the avilable Balance,Enter Another Amount: ";
            Amount = clsInputValidate::ReadDblNumber();

        }

        return Amount;
    }


public:


    static void ShowTrnasferScreen()
    {
   
        _DrawScreenHeader("\t Transfer Screen");
        cout << clsString::RedString("\nTransfer fee : ") + clsString::RedString("0.005");

        double Amount = 0;
        string  DistantionAccNumber;

        clsBankClient SourceClient = clsBankClient::Find(_ReadACcountNumber("\nEnter Account Number To Transfer "
            + clsString::RedString("From: ")));

        _PrintClient(SourceClient);


        DistantionAccNumber = _ReadACcountNumber("\nEnter Account Number To Transfer "
         +clsString::RedString("To: "));

        while (DistantionAccNumber == SourceClient.AccountNumber())
        {

            DistantionAccNumber = _ReadACcountNumber("\n" + clsString::RedString("You Cant Transfer To Same Account!")
                + ",Enter Another Account Number: ");
           
        }

        clsBankClient DistantionClient = clsBankClient::Find(DistantionAccNumber);

        _PrintClient(DistantionClient);

        Amount = _ReadAmount(SourceClient);

        char Ans;
      
        cout << "Are You sure You Want to perform this Opretion Y/N? ";
        cin >> Ans;

        if (Ans == 'Y' || Ans == 'y')
        {
            float fee = 0.005;
            if (SourceClient.Trnasfer(Amount, fee,DistantionClient ,CurrentUser.UserName))
            {
               
                cout << "\nTransfer done Succesfully \n";
                
            }


        }
        else cout << "\nOpration Cancelled\n";

        _PrintClient(SourceClient);
        cout << endl;
        _PrintClient(DistantionClient);


    }

};

