#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClients.h"
#include "clsInputValidation.h"

class clsUpdateClientScreen :protected clsScreen

{
private:

    enum enwWhatToUpdate
    {
        enAll = 1, enFirstName = 2, enLastName = 3, eEmail = 4,
        ePhone = 5, ePinCode = 6, eAccBalance = 7

    };


    static short _ReadOption()
    {
    
        cout << setw(37) << left << "" << "Choose what do you want to Update? [1 to 7]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter Number between 1 to 4? ");
        return Choice;
    }

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


    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

  static  clsBankClient GetClientobj()
    {

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        return Client1;

    }

  static void _ReadFirstName(clsBankClient& Client)
  {
      cout << "\nEnter FirstName: ";
      Client.FirstName = clsInputValidate::ReadString();

  }

  static void _ReadLastName(clsBankClient& Client)
  {
      cout << "\nEnter LastName: ";
      Client.LastName = clsInputValidate::ReadString();

  }

  static void _ReadEmail(clsBankClient& Client)
  {
      cout << "\nEnter Email: ";
      Client.Email = clsInputValidate::ReadString();

  }

  static void _ReadPhone(clsBankClient& Client)
  {
      cout << "\nEnter Phone: ";
      Client.Phone = clsInputValidate::ReadString();


  }

  static void _ReadPinCode(clsBankClient& Client)
  {
      cout << "\nEnter PinCode: ";
      Client.PinCode = clsInputValidate::ReadString();

  }

  static void _ReadAccBalance(clsBankClient& Client)
  {
      cout << "\nEnter Account Balance: ";
      Client.AccountBalance = clsInputValidate::ReadFloatNumber();

  }

  static void _SaveResult(clsBankClient& Client)
  {

      clsBankClient::enSaveResults SaveResult;

      SaveResult = Client.Save();

      switch (SaveResult)
      {
      case  clsBankClient::enSaveResults::svSucceeded:
      {
          cout << "\nAccount Updated Successfully :-)\n";

          _PrintClient(Client);
          break;
      }
      case clsBankClient::enSaveResults::svFaildEmptyObject:
      {
          cout << "\nError account was not saved because it's Empty";
          break;

      }


      }

      }


  static void _PerformUpdateOption(enwWhatToUpdate Options, clsBankClient &Client)
  {
      switch (Options)
      {
      case enAll:
      {
          system("cls");
          ReadClientInfo(Client);
          break;
      }

      case enFirstName:
      {
          system("cls");
          _ReadFirstName(Client);
          break;
      }

      case enLastName:
      {
          system("cls");
          _ReadLastName(Client);
          break;
      }

      case eEmail:
      {
          system("cls");
          _ReadEmail(Client);
          break;

      }
      case ePhone:
      {
          system("cls");
          _ReadPhone(Client);
          break;
      }


      case ePinCode:
      {
          system("cls");
          _ReadPinCode(Client);
          break;
      }
      case eAccBalance:
      {
          system("cls");
          _ReadAccBalance(Client);
          break;
      }

      }




  }

  static void ShowUpdateOption(clsBankClient& Client)
  {

      cout << setw(37) << left << "" << "===========================================\n";
      cout << setw(37) << left << "" << "\t\tUpdate Options\n";
      cout << setw(37) << left << "" << "===========================================\n";
      cout << setw(37) << left << "" << "\t[1] Update All Info.\n";
      cout << setw(37) << left << "" << "\t[2] FirstName.\n";
      cout << setw(37) << left << "" << "\t[3] LastName.\n";
      cout << setw(37) << left << "" << "\t[4] Email.\n";
      cout << setw(37) << left << "" << "\t[5] Phone.\n";
      cout << setw(37) << left << "" << "\t[6] PinCode.\n";
      cout << setw(37) << left << "" << "\t[7] Account Balance.\n";
      cout << setw(37) << left << "" << "===========================================\n";

      _PerformUpdateOption((enwWhatToUpdate)_ReadOption(), Client);
  }

  public:

      static void ShowUpdateClientScreen()
      {

          if (!_CheckPermissions(clsUser::pUpdateClient))
          {
              return;
          }


          _DrawScreenHeader("\tUpdate Client Screen");


          clsBankClient Client = GetClientobj();

          _PrintClient(Client);

          cout << "\nAre you sure you want to update this client y/n? ";

          char Answer = 'n';
          char Continue = 'y';
          cin >> Answer;

          if (Answer == 'y' || Answer == 'Y')
          {

              while(true)
              {
                  system("cls");
                  _DrawScreenHeader("\tUpdate Client Info");
               
                  ShowUpdateOption(Client);
                  _SaveResult(Client);

                  cout << "\nDo You want to Update another info? Y/N ";
                  cin >> Continue;

                  if (Continue == 'n' || Continue == 'N')
                  {
                      break;

                  }
              }



          }



      }
      
  
};

