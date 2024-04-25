#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsMainScreen.h"
#include <fstream>

class clsLoginScreen :protected clsScreen
{

private:

    
    static bool _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        short FaildLoginCount = 0;
        do
        {
            
            if (LoginFaild)
            {
               
                FaildLoginCount++;
                cout <<"\n\t\t\t\t\tInvlaid Username / Password!....Press Any Key to try Again\n";
                cout << "\t\t\t\t\tYou have " << (3-FaildLoginCount) << " Trials to login.\n\n";

                if (FaildLoginCount == 3)
                {
                    cout << "\n\t\t\t\t\tYour are Locked after 3 faild trails\n";
                    return false;;
                }
       
            }

            cout << "\t\t\t\t\tEnter Username? ";
            cin >> Username;

            cout << "\t\t\t\t\tEnter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();

        clsMainScreen::ShowMainMenue();

        return true;

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};

