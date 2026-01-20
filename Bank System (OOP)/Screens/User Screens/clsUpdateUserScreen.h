#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidation.h"


class clsUpdateUserScreen :protected clsScreen

{
private:


    static void _ReadUserInfo(clsUser& User)
    {
       /* cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();*/

        _ReadFirstName(User);
        _ReadLastName(User);
        _ReadEmail(User);
        _ReadPhone(User);
        _ReadPassword(User);
        _ReadPermissions(User);
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLoginRegisterList;
        }
        return Permissions;

    }


    enum enwWhatToUpdate
    {
        enAll = 1, enFirstName = 2, enLastName = 3, eEmail = 4,
        ePhone = 5, ePassword = 6, ePermissions = 7

    };


    static short _ReadOption()
    {

        cout << setw(37) << left << "" << "Choose what do you want to Update? [1 to 7]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter Number between 1 to 7? ");
        return Choice;
    }

    static  clsUser GetUsereobj()
    {

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        return User;

    }

    static void _ReadFirstName(clsUser& User)
    {
      
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

    }

    static void _ReadLastName(clsUser& User)
    {
        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

    }

    static void _ReadEmail(clsUser& User)
    {
        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

    }

    static void _ReadPhone(clsUser& User)
    {
        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();


    }

    static void _ReadPassword(clsUser& User)
    {
        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

    }

    static void _ReadPermissions(clsUser& User)
    {
        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();

    }

    static void _SaveResult(clsUser& User)
    {

        clsUser::enSaveResults SaveResult;

        SaveResult = User.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";

            _PrintUser(User);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }


        }

    }


    static void _PerformUpdateOption(enwWhatToUpdate Options, clsUser& User)
    {
        switch (Options)
        {
        case enAll:
        {
            system("cls");
            _ReadUserInfo(User);
            break;
        }

        case enFirstName:
        {
            system("cls");
            _ReadFirstName(User);
            break;
        }

        case enLastName:
        {
            system("cls");
            _ReadLastName(User);
            break;
        }

        case eEmail:
        {
            system("cls");
            _ReadEmail(User);
            break;

        }
        case ePhone:
        {
            system("cls");
            _ReadPhone(User);
            break;
        }


        case ePassword:
        {
            system("cls");
            _ReadPassword(User);
            break;
        }
        case ePermissions:
        {
            system("cls");
            _ReadPermissions(User);
            break;
        }

        }




    }

    static void ShowUpdateOption(clsUser& User)
    {

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tUpdate Options\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Update All Info.\n";
        cout << setw(37) << left << "" << "\t[2] FirstName.\n";
        cout << setw(37) << left << "" << "\t[3] LastName.\n";
        cout << setw(37) << left << "" << "\t[4] Email.\n";
        cout << setw(37) << left << "" << "\t[5] Phone.\n";
        cout << setw(37) << left << "" << "\t[6] Password.\n";
        cout << setw(37) << left << "" << "\t[7] Permissions.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformUpdateOption((enwWhatToUpdate)_ReadOption(), User);
    }

public:

    static void ShowUpdateUserScreen()
    {

        _DrawScreenHeader("\tUpdate User Screen");

     
        clsUser User1 = GetUsereobj();

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        char Continue = 'y';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            while (true)
            {
                system("cls");
                _DrawScreenHeader("\tUpdate User Info");

                ShowUpdateOption(User1);
                _SaveResult(User1);

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

