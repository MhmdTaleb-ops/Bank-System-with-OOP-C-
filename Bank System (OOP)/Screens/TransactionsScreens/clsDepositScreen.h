#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsInputValidation.h";
#include "clsMainScreen.h"
class clsDepositScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string ReadAccountNumber()
    {

        string Acc = clsInputValidate::ReadString();

        return Acc;

    }


public:

  static  void ShowDepositScreen()
    {

      _DrawScreenHeader("\t\tDeposit Screen ");
      cout << "\nEnter Account Number: ";
        string Acc = ReadAccountNumber();

        while (!clsBankClient::IsClientExist(Acc))
        {

            cout << "\nAccount With [" << Acc << "] is not Exist , Enter Another one..\n";
            Acc = ReadAccountNumber();

        }
        clsBankClient Client1 = clsBankClient::Find(Acc);
        
        _PrintClient(Client1);

        double Amount = 0;
        char Ans = 'Y';
        cout << "\nEenter Amount You Want To Deposit: ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nare You sure To Depostin it? y/n : ";
        cin >> Ans;

        if (Ans == 'Y' || Ans == 'y')
        {

            Client1.Deposit(Amount);
            cout << "\nAmount Deposit Succsesfully\n";
            cout << "New Balance Account = " << Client1.AccountBalance << endl;


        }
        else
        {

            cout << "\nOpreation Cancelled \n";


        }



    }


};

