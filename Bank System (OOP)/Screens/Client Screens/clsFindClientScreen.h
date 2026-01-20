#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClients.h"
#include "clsInputValidation.h"

class clsFilndClientScreen : protected clsScreen
{

private:
    
    static void _PrintClient(clsBankClient Client)
    {
        cout  << "\nClient Card:";

        cout << "\n___________________\n";
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

public:

    static void ShowFindClientScreen()
    {
        if (!_CheckPermissions(clsUser::pFindClient))
        {
            return;
        }

        _DrawScreenHeader("\tFind Client Screen");


        string AccNumber = "";
        cout << "\nEnter an Account Number: ";
        AccNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccNumber))
        {
            cout << "\nNot Found!,enter Another one:";
            AccNumber = clsInputValidate::ReadString();
           
        }
        system("cls");
        _DrawScreenHeader("\tFind Client Screen");
        clsBankClient Client = clsBankClient::Find(AccNumber);

        if (!Client.IsEmpty())
        {

            cout << "\nClient Found :) \n";


        }
        else
        {

            cout << "Client was not Found :( \n";

        }

        _PrintClient(Client);




    }

};

