#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "ClsDate.h"

using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\t User: " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\t Date: " << clsDate::DateToString(clsDate()) << endl;

    }

    static bool _CheckPermissions(clsUser::enPermissions Permissions)
    {

        if (!CurrentUser.CheckAccessPermission(Permissions))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }




    }

};

